#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <math.h>

static PyObject* Py_mean(PyObject* self, PyObject* args) { 
	PyObject *list, *item;
	Py_ssize_t n;
	double result = 0.0;
	int i; 
	if (!PyArg_ParseTuple(args, "O!", &PyList_Type, &list)) 
	{ 
		return NULL; 
	}  

	n = PyList_Size(list);
	for(i = 0;i < n;i++) {
		item = PyList_GetItem(list, i);
		if(PyLong_Check(item)) {
			result += (double)PyLong_AsLong(item);
		}
	}

	result /= (double)n;
	return Py_BuildValue("f", result); 
} 

// static PyObject* Py_fmean(PyObject* self, PyObject* args) {
// 	// TODO: Look into why the implementation difference between fmean and mean
// 	return NULL;
// }

static PyObject* Py_geometric_mean(PyObject* self, PyObject* args) {
	// TODO: handle issue of floating point error
	PyObject *list, *item;
	Py_ssize_t n;
	double result = 0.0;
	int i; 
	if (!PyArg_ParseTuple(args, "O!", &PyList_Type, &list)) 
	{ 
		return NULL; 
	}  

	n = PyList_Size(list);
	for(i = 0;i < n;i++) {
		item = PyList_GetItem(list, i);
		if(PyLong_Check(item)) {
			if (i == 0) {
				result = (double)PyLong_AsLong(item);
			} else {
				result *= (double)PyLong_AsLong(item);
			}
		}
	}

	result = pow(result, 1.0/n);
	return Py_BuildValue("f", result); 
}

static PyObject* Py_harmonic_mean(PyObject* self, PyObject* args) {
	PyObject *list, *item;
	Py_ssize_t n;
	double result = 0.0;
	int i; 
	if (!PyArg_ParseTuple(args, "O!", &PyList_Type, &list)) 
	{ 
		return NULL; 
	}  

	n = PyList_Size(list);
	for(i = 0;i < n;i++) {
		item = PyList_GetItem(list, i);
		if(PyLong_Check(item)) {
			result += 1.0/PyLong_AsLong(item);
		}
	}
	result = (double)n / result;
	return Py_BuildValue("f", result); 
}

// static PyObject* Py_median(PyObject* self, PyObject* args) {
// 	return NULL;
// }

// static PyObject* Py_median_low(PyObject* self, PyObject* args) {
// 	return NULL;
// }

// static PyObject* Py_median_high(PyObject* self, PyObject* args) {
// 	return NULL;
// }

// static PyObject* Py_median_grouped(PyObject* self, PyObject* args) {
// 	return NULL;
// }

// static PyObject* Py_mode(PyObject* self, PyObject* args) {
// 	return NULL;
// }

// static PyObject* Py_multimode(PyObject* self, PyObject* args) {
// 	return NULL;
// }

// static PyObject* Py_pstdev(PyObject* self, PyObject* args) {
// 	return NULL;
// }

// static PyObject* Py_pvariance(PyObject* self, PyObject* args) {
// 	return NULL;
// }

// static PyObject* Py_stdev(PyObject* self, PyObject* args) {
// 	return NULL;
// }

// static PyObject* Py_variance(PyObject* self, PyObject* args) {
// 	return NULL;
// }

// static PyObject* Py_quantiles(PyObject* self, PyObject* args) {
// 	return NULL;
// }



/* Module method table */
static PyMethodDef StatisticMethods[] = { 
	{"mean", Py_mean, METH_VARARGS,  PyDoc_STR("Return the sample arithmetic mean of data.")}, 
	{"fmean", Py_mean, METH_VARARGS,  PyDoc_STR("Return the sample arithmetic mean of data.")}, 
	{"geometric_mean", Py_geometric_mean, METH_VARARGS,  PyDoc_STR("Return the sample arithmetic mean of data.")}, 
	{"harmonic_mean", Py_harmonic_mean, METH_VARARGS,  PyDoc_STR("Return the sample arithmetic mean of data.")}, 
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
PyMODINIT_FUNC PyInit_stats(void) 
{ 
	return PyModule_Create(&statsmodule); 
}
