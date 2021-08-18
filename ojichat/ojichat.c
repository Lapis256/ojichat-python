#include <Python.h>

PyObject* generate(PyObject* , PyObject*);

int PyArg_ParseTuple_Uii(PyObject* args, PyObject** a, int* b, int* c) {
    return PyArg_ParseTuple(args, "|Uii", a, b, c);
}

static struct PyMethodDef methods[] = {
    {
        "generate",
        (PyCFunction)generate,
        METH_VARARGS,
        "おじさんの文言を生成します"
    },
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "ojichat.ojichat",
    "ojichatのPythonラッパーです",
    -1,
    methods
};

PyMODINIT_FUNC PyInit_ojichat(void) {
    return PyModule_Create(&module);
}
