#define PY_SSIZE_T_CLEAN
#include <Python.h>

static PyObject* Py_mean(PyObject* self, PyObject* args) 
{ 
	double result; 
	if (! PyArg_ParseTuple(args, "i")) 
	{ 
		return NULL; 
	}  
	return Py_BuildValue("i", result); 
} 

/* Module method table */
static PyMethodDef StatisticMethods[] = 
{ 
	{"mean", Py_gcd, METH_VARARGS,  PyDoc_STR("Return the sample arithmetic mean of data.")}, 
	{ NULL } 
}; 

/* Module structure */
static struct PyModuleDef statsmodule = 
{ 
	PyModuleDef_HEAD_INIT, 
	"stats",
	"An implementation of the statistics module in the python standard library", 
	-1, 
	StatisticMethods 
}; 

/* Module initialization function */
PyMODINIT_FUNC PyInit_sample(void) 
{ 
	return PyModule_Create(&statsmodule); 
}
