package main
 
// #include <Python.h>
// int PyArg_ParseTupleAndKeywords_Uii(PyObject*, PyObject*, PyObject**, int*, int*);
import "C"
import "fmt"
import "unsafe"
import "github.com/greymd/ojichat/generator"

func pyString(str string) *C.PyObject {
	cstr := C.CString(str)
	ret := C.PyUnicode_FromString(cstr)
	C.free(unsafe.Pointer(cstr))
	return ret
}

func parseArgs(args *C.PyObject, kwargs *C.PyObject) (generator.Config, error) {
	var obj *C.PyObject = pyString("")
	num := C.int(4)
	level := C.int(0)
	if C.PyArg_ParseTupleAndKeywords_Uii(args, kwargs, &obj, &num, &level) == 0 {
		return generator.Config{"", 0, 0}, fmt.Errorf("")
	}
	
	bytes := C.PyUnicode_AsUTF8String(obj)
	name := C.GoString(C.PyBytes_AsString(bytes))
	C.Py_DecRef(bytes)
	return generator.Config{name, int(num), int(level)}, nil
}

//export generate
func generate(self *C.PyObject, args *C.PyObject, kwargs *C.PyObject) *C.PyObject {
	config, err := parseArgs(args, kwargs)
	if err != nil {
		return nil
	}
	
	result, err := generator.Start(config)
	if err != nil {
		error_str := C.CString(err.Error())
		C.PyErr_SetString(C.PyExc_ValueError, error_str)
		C.free(unsafe.Pointer(error_str))
		return nil
	}
	
	return pyString(result)
}

func main() {}
