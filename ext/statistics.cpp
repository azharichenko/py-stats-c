#define PY_SSIZE_T_CLEAN
#include <Python.h>

static PyObject* Py_mean(PyObject* self, PyObject* args) { 
	double result; 
	if (! PyArg_ParseTuple(args, "i")) 
	{ 
		return NULL; 
	}  
	return Py_BuildValue("f", result); 
} 

static PyObject* Py_fmean(PyObject* self, PyObject* args) {
	return NULL;
}

static PyObject* Py_geometric_mean(PyObject* self, PyObject* args) {
	return NULL;
}

static PyObject* Py_harmonic_mean(PyObject* self, PyObject* args) {
	return NULL;
}

static PyObject* Py_median(PyObject* self, PyObject* args) {
	return NULL;
}

static PyObject* Py_median_low(PyObject* self, PyObject* args) {
	return NULL;
}

static PyObject* Py_median_high(PyObject* self, PyObject* args) {
	return NULL;
}

static PyObject* Py_median_grouped(PyObject* self, PyObject* args) {
	return NULL;
}

static PyObject* Py_mode(PyObject* self, PyObject* args) {
	return NULL;
}

static PyObject* Py_multimode(PyObject* self, PyObject* args) {
	return NULL;
}

static PyObject* Py_pstdev(PyObject* self, PyObject* args) {
	return NULL;
}

static PyObject* Py_pvariance(PyObject* self, PyObject* args) {
	return NULL;
}

static PyObject* Py_stdev(PyObject* self, PyObject* args) {
	return NULL;
}

static PyObject* Py_variance(PyObject* self, PyObject* args) {
	return NULL;
}

static PyObject* Py_quantiles(PyObject* self, PyObject* args) {
	return NULL;
}



/* Module method table */
static PyMethodDef StatisticMethods[] = { 
	{"mean", Py_gcd, METH_VARARGS,  PyDoc_STR("Return the sample arithmetic mean of data.")}, 
	{ NULL } 
}; 

/* Module structure */
static struct PyModuleDef statsmodule = { 
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
