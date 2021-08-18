#include <Python.h>

PyObject* generate(PyObject* , PyObject*);

int PyArg_ParseTupleAndKeywords_Uii(PyObject* args, PyObject* kwargs, PyObject** a, int* b, int* c) {
    static char *kwlist[] = {"name", "num", "level", NULL};
    return PyArg_ParseTupleAndKeywords(args, kwargs, "|Uii", kwlist, a, b, c);
}

static struct PyMethodDef methods[] = {
    {
        "generate",
        (PyCFunction)generate,
        METH_VARARGS | METH_KEYWORDS,
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
