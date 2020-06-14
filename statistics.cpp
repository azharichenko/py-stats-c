// #define PY_SSIZE_T_CLEAN
// #include <Python.h>
// #include <math.h>

// #include <algorithm>
// #include <map>
// #include <vector>

// #include<iostream>

// PyObject *StatisticsError = NULL;

// static PyObject *Py_mean(PyObject *self, PyObject *args) {
//   PyObject *list, *item;
//   Py_ssize_t n;
//   double result = 0.0;
//   int i;
//   if (!PyArg_ParseTuple(args, "O!", &PyList_Type, &list)) {
//     return NULL;
//   }

//   n = PyList_Size(list);

//   if (n == 0) {
//     return NULL;
//   }

//   for (i = 0; i < n; i++) {
//     item = PyList_GetItem(list, i);
//     if (PyLong_Check(item)) {
//       result += (double)PyLong_AsLong(item);
//     } else if (PyFloat_Check(item)) {
//       result += PyFloat_AS_DOUBLE(item);
//     } else {
//       return NULL;
//     }
//   }

//   result /= (double)n;
//   return PyFloat_FromDouble(result);
// }

// // static PyObject* Py_fmean(PyObject* self, PyObject* args) {
// // 	// TODO: Look into why the implementation difference between fmean and
// // mean 	return NULL;
// // }

// static PyObject *Py_geometric_mean(PyObject *self, PyObject *args) {
//   // TODO: handle issue of floating point error
//   PyObject *list, *item;
//   Py_ssize_t n;
//   double result = 0.0;

//   int i;
//   if (!PyArg_ParseTuple(args, "O!", &PyList_Type, &list)) {
//     return NULL;
//   }

//   n = PyList_Size(list);

//   if (n == 0) {
//     return NULL;
//   }

//   for (i = 0; i < n; i++) {
//     item = PyList_GetItem(list, i);
//     if (i == 0) {
//       if (PyLong_Check(item)) {
//         result = (double)PyLong_AsLong(item);
//       } else if (PyFloat_Check(item)) {
//         result = PyFloat_AS_DOUBLE(item);
//       } else {
//         return NULL;
//       }
//       continue;
//     }

//     if (PyLong_Check(item)) {
//       result *= (double)PyLong_AsLong(item);
//     } else if (PyFloat_Check(item)) {
//       result *= PyFloat_AS_DOUBLE(item);
//     } else {
//       return NULL;
//     }
//   }

//   result = pow(result, 1.0 / n);
//   return PyFloat_FromDouble(result);
// }

// static PyObject *Py_harmonic_mean(PyObject *self, PyObject *args) {
//   PyObject *list, *item;
//   Py_ssize_t n;
//   double result = 0.0;
//   int i;
//   if (!PyArg_ParseTuple(args, "O!", &PyList_Type, &list)) {
//     return NULL;
//   }

//   n = PyList_Size(list);

//   if (n == 0) {
//     return NULL;
//   }

//   for (i = 0; i < n; i++) {
//     item = PyList_GetItem(list, i);
//     if (PyLong_Check(item)) {
//       result += 1.0 / PyLong_AsLong(item);
//     } else if (PyFloat_Check(item)) {
//       result += 1.0 / PyFloat_AS_DOUBLE(item);
//     } else {
//       return NULL;
//     }
//   }
//   result = (double)n / result;
//   return PyFloat_FromDouble(result);
// }

// static PyObject *Py_median(PyObject *self, PyObject *args) {
//   PyObject *list, *item;
//   int i, n;
//   std::vector<double> values;
//   auto it = values.begin();

//   if (!PyArg_ParseTuple(args, "O!", &PyList_Type, &list)) {
//     return NULL;
//   }

//   n = PyList_Size(list);

//   if (n == 0) {
//     return NULL;
//   }

//   for (i = 0; i < n; i++) {
//     item = PyList_GetItem(list, i);
//     if (PyLong_Check(item)) {
// 		it = values.insert(it, (double)PyLong_AsLong(item));
//     } else if (PyFloat_Check(item)) {
// 		it = values.insert(it, PyFloat_AS_DOUBLE(item));
//     } else {
//       return NULL;
//     }
//   }

//   std::stable_sort(values.begin(), values.end());
//   i = values.size() / 2;

//   if (n % 2 == 0) {
//     return PyFloat_FromDouble( (values.at(i) + values.at(i - 1)) / 2);
//   }

//   return PyFloat_FromDouble(values.at(i));
// }

// static PyObject* Py_median_low(PyObject* self, PyObject* args) {
//   PyObject *list, *item;
//   int i, n;
//   std::vector<double> values;
//   auto it = values.begin();

//   if (!PyArg_ParseTuple(args, "O!", &PyList_Type, &list)) {
//     return NULL;
//   }

//   n = PyList_Size(list);

//   if (n == 0) {
//     return NULL;
//   }

//   for (i = 0; i < n; i++) {
//     item = PyList_GetItem(list, i);
//     if (PyLong_Check(item)) {
// 		it = values.insert(it, (double)PyLong_AsLong(item));
//     } else if (PyFloat_Check(item)) {
// 		it = values.insert(it, PyFloat_AS_DOUBLE(item));
//     } else {
//       return NULL;
//     }
//   }

//   std::stable_sort(values.begin(), values.end());
//   i = values.size() / 2;

//   if (n % 2 == 0) {
//     return PyFloat_FromDouble(values.at(i - 1));
//   }

//   return PyFloat_FromDouble(values.at(i));
// }

// static PyObject* Py_median_high(PyObject* self, PyObject* args) {
// 	  PyObject *list, *item;
//   int i, n;
//   std::vector<double> values;
//   auto it = values.begin();

//   if (!PyArg_ParseTuple(args, "O!", &PyList_Type, &list)) {
//     return NULL;
//   }

//   n = PyList_Size(list);

//   if (n == 0) {
//     return NULL;
//   }

//   for (i = 0; i < n; i++) {
//     item = PyList_GetItem(list, i);
//     if (PyLong_Check(item)) {
// 		it = values.insert(it, (double)PyLong_AsLong(item));
//     } else if (PyFloat_Check(item)) {
// 		it = values.insert(it, PyFloat_AS_DOUBLE(item));
//     } else {
//       return NULL;
//     }
//   }

//   std::stable_sort(values.begin(), values.end());
//   i = values.size() / 2;

//   if (n % 2 == 0) {
//     return PyFloat_FromDouble(values.at(i));
//   }

//   return PyFloat_FromDouble(values.at(i));
// }

// // static PyObject* Py_median_grouped(PyObject* self, PyObject* args) {
// // 	return NULL;
// // }

// static PyObject *Py_mode(PyObject *self, PyObject *args) {
//   PyObject *list, *item;
//   int i;
//   if (!PyArg_ParseTuple(args, "O!", &PyList_Type, &list)) {
//     return NULL;
//   }
//   Py_ssize_t n;
//   n = PyList_Size(list);
//   if (n < 1) {
//     return NULL;
//   }

//   std::map<double, int> counter;

//   for (i = 0; i < n; i++) {
//     item = PyList_GetItem(list, i);
//     if (PyLong_Check(item)) {
//       counter[(double)PyLong_AsLong(item)]++;
//     } else if (PyFloat_Check(item)) {
//       counter[PyFloat_AS_DOUBLE(item)]++;
//     } else {
//       return NULL;
//     }
//   }

//   float value;
//   int count = -1;
//   for (std::map<double, int>::iterator it = counter.begin();
//        it != counter.end(); ++it) {
//     if (it->second > 1 && it->second > count) {
//       value = it->first;
//       count = it->second;
//     }
//   }
//   if (count == -1) {
//     PyErr_SetString(StatisticsError, "all values are equally common");
//     return NULL;
//   }
//   return PyFloat_FromDouble(value);
// }

// // static PyObject* Py_multimode(PyObject* self, PyObject* args) {
// // 	return NULL;
// // }

// static double _ss(PyObject *self, PyObject *args) {
//   PyObject *list, *item, *mean = Py_mean(self, args);

//   if (mean == NULL) {
//     return -1.0;
//   }

//   Py_ssize_t n;
//   double pstdev = 0.0, mu = PyFloat_AS_DOUBLE(mean);
//   int i;

//   if (!PyArg_ParseTuple(args, "O!", &PyList_Type, &list)) {
//     return -1.0;
//   }

//   n = PyList_Size(list);
//   if (n == 0) {
//     return -1.0;
//   }

//   for (i = 0; i < n; i++) {
//     item = PyList_GetItem(list, i);
//     if (PyLong_Check(item)) {
//       pstdev += pow((double)PyLong_AsLong(item) - mu, 2);
//     } else if (PyFloat_Check(item)) {
//       pstdev += pow(PyFloat_AS_DOUBLE(item) - mu, 2);
//     } else {
//       return -1.0;
//     }
//   }
//   return pstdev;
// }

// static PyObject *Py_pvariance(PyObject *self, PyObject *args) {
//   PyObject *list;
//   Py_ssize_t n;
//   double ss = _ss(self, args);

//   if (ss < 0) {
//     return NULL;
//   }

//   if (!PyArg_ParseTuple(args, "O!", &PyList_Type, &list)) {
//     return NULL;
//   }

//   n = PyList_Size(list);
//   if (n == 0) {
//     return NULL;
//   }
//   return Py_BuildValue("f", ss / n);
// }

// static PyObject *Py_pstdev(PyObject *self, PyObject *args) {
//   PyObject *pvariance = Py_pvariance(self, args);

//   if (pvariance == NULL) {
//     return NULL;
//   }

//   double pstdev = PyFloat_AS_DOUBLE(pvariance);
//   pstdev = pow(pstdev, 0.5);

//   return Py_BuildValue("f", pstdev);
// }

// static PyObject *Py_variance(PyObject *self, PyObject *args) {
//   PyObject *list;
//   Py_ssize_t n;
//   double ss = _ss(self, args);

//   if (ss < 0) {
//     return NULL;
//   }

//   if (!PyArg_ParseTuple(args, "O!", &PyList_Type, &list)) {
//     return NULL;
//   }

//   n = PyList_Size(list);
//   if (n == 0) {
//     return NULL;
//   }
//   return Py_BuildValue("f", ss / (n - 1));
// }

// static PyObject *Py_stdev(PyObject *self, PyObject *args) {
//   PyObject *variance = Py_variance(self, args);

//   if (variance == NULL) {
//     return NULL;
//   }

//   double stdev = PyFloat_AS_DOUBLE(variance);
//   stdev = pow(stdev, 0.5);

//   return Py_BuildValue("f", stdev);
// }

// // static PyObject* Py_quantiles(PyObject* self, PyObject* args) {
// // 	return NULL;
// // }

// /* Module method table */
// static PyMethodDef StatisticMethods[] = {
//     {"mean", Py_mean, METH_VARARGS,
//      PyDoc_STR("Return the sample arithmetic mean of data.")},
//     {"fmean", Py_mean, METH_VARARGS,
//      PyDoc_STR("Return the sample arithmetic mean of data.")},
//     {"geometric_mean", Py_geometric_mean, METH_VARARGS,
//      PyDoc_STR("Return the sample arithmetic mean of data.")},
//     {"harmonic_mean", Py_harmonic_mean, METH_VARARGS,
//      PyDoc_STR("Return the sample arithmetic mean of data.")},
//     {"pstdev", Py_pstdev, METH_VARARGS,
//      PyDoc_STR("Return the population standard deviation.")},
//     {"pvariance", Py_pvariance, METH_VARARGS,
//      PyDoc_STR("Return the population variance.")},
//     {"stdev", Py_stdev, METH_VARARGS,
//      PyDoc_STR("Return the sample standard deviation.")},
//     {"variance", Py_variance, METH_VARARGS,
//      PyDoc_STR("Return the sample variance.")},
//     {"mode", Py_mode, METH_VARARGS, PyDoc_STR("Returns the mode of the data.")},
//     {"median", Py_median, METH_VARARGS,
//      PyDoc_STR("Returns the median of the data.")},
//     {"median_high", Py_median_high, METH_VARARGS,
//      PyDoc_STR("Returns the median of the data. If even it return the upper "
//                "median.")},
//     {"median_low", Py_median_low, METH_VARARGS,
//      PyDoc_STR("Returns the median of the data.  If even it return the lower "
//                "median.")},
//     {NULL}};

// /* Module structure */
// static struct PyModuleDef statsmodule = {
//     PyModuleDef_HEAD_INIT, "stats",
//     "An implementation of the statistics module in the python standard library",
//     -1, StatisticMethods};

// /* Module initialization function */
// PyMODINIT_FUNC PyInit_stats(void) {
//   PyObject *module;
//   module = PyModule_Create(&statsmodule);
//   if (StatisticsError == NULL) {
//     StatisticsError =
//         PyErr_NewException("stats.StatisticsError", PyExc_Exception, NULL);
//   }
//   return module;
// }
#include <boost/python.hpp>

using namespace boost::python;

char const* say_hi()
{
    return "Hi!";
}

BOOST_PYTHON_MODULE(statistics)
{
    def("say_hi", say_hi);
}