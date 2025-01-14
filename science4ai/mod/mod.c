#define PY_SSIZE_T_CLEAN
#include "science4ai.h"
#include <Python.h>
#include <structmember.h>

static PyObject* method_fputs(PyObject* self, PyObject* args)
{
    char *str, *filename = NULL;
    int bytes_copied = -1;
    if (!PyArg_ParseTuple(args, "ss", &str, &filename))
    {
        return NULL;
    }

    FILE* fp     = fopen(filename, "w");
    bytes_copied = fputs(str, fp);
    fclose(fp);

    return PyLong_FromLong(bytes_copied);
}

static void science4ai_dll(PyObject* self)
{
    science4ai();
}

static PyMethodDef ModMethods[] = {
    { .ml_name  = "fputs",
      .ml_meth  = method_fputs,
      .ml_flags = METH_VARARGS,
      .ml_doc   = "Python interface for fputs C library function." },
    { .ml_name  = "science4ai_dll",
      .ml_meth  = (PyCFunction)science4ai_dll,
      .ml_flags = METH_NOARGS,
      .ml_doc   = "Python interface for dynamic library function." },
    { NULL, NULL, 0, NULL }
};
static struct PyModuleDef Mod = {
    PyModuleDef_HEAD_INIT, .m_name = "mod",
    .m_doc = "Python interface for the C library function", .m_size = -1,
    .m_methods = ModMethods
};
PyMODINIT_FUNC PyInit_mod(void)
{
    PyObject* mod = PyModule_Create(&Mod);
    if (mod == NULL)
        return NULL;
#ifdef Py_GIL_DISABLED
    PyUnstable_Module_SetGIL(mod, Py_MOD_GIL_NOT_USED);
#endif
    return mod;
}