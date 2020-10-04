//  "An implementation of the statistics module in the python standard library",
#include<boost/python.hpp>
#include<boost/python/def.hpp>
#include<boost/python/exception_translator.hpp>
#include<boost/operators.hpp>

#include<math.h>
#include<algorithm>
#include<exception>
#include<map>
#include<vector>
#include<iostream>

using namespace boost::python;

struct StatisticsError : std::exception {
};

void translate(StatisticsError const& e) {
    PyErr_SetString(PyExc_RuntimeError,"Something is wrong");
}


object mean(object data) {
    if(len(data) < 1) {
        throw StatisticsError();
    } else if (len(data) == 1) {
        return data[0];
    }

    double total = 0.0;
    for(int i = 0;i < len(data);i++) {
        total += extract<double>(data[i]);
    }
    total /= len(data);
    return object(total);
}

object geometric_mean(object data) {
    if(len(data) < 1) {
        throw StatisticsError();
    } else if (len(data) == 1) {
        return data[0];
    }

    double total = extract<double>(data[0]);
    for(int i = 1;i < len(data);i++) {
        total *= extract<double>(data[i]);
    }
    return object(pow(total, 1.0 / len(data)));
}

object harmonic_mean(object data) {
    if(len(data) < 1) {
        throw StatisticsError();
    } else if (len(data) == 1) {
        return data[0];
    }

    double total = 0.0;
    for(int i = 0;i < len(data);i++) {
        total += 1.0 / extract<double>(data[i]);
    }
    total = len(data) / total;
    return object(total);
}

object median(list data) {
    if(len(data) == 0) {
        throw StatisticsError();
    }
    data.sort();
    long midway = len(data) / 2;
    if (len(data) % 2 == 0) {
        return object((extract<double>(data[midway]) + extract<double>(data[midway - 1])) / 2.0);
    }
    return data[midway];
}

object median_low(list data) {
    if(len(data) == 0) {
        throw StatisticsError();
    }
    data.sort();
    long midway = len(data) / 2;
    if (len(data) % 2 == 0) {
        return data[midway - 1];
    }
    return data[midway];
}

object median_high(list data) {
    if(len(data) == 0) {
        throw StatisticsError();
    }
    data.sort();
    return data[len(data) / 2];
}

double _ss(object data, object c) {
    if(len(data) == 0) {
        throw StatisticsError();
    }
    double c_1;
    if(c.is_none()) {
        c_1 = extract<double>(mean(data));
    } else {
        c_1 = extract<double>(c);
    }
    
    double pstdev = 0.0;

    for(int i = 0;i < len(data);i++) {
        pstdev += std::pow(extract<double>(data[i]) - c_1, 2);
    }

    return pstdev;
}

object pvariance(object data, object mu) {
    return object(_ss(data, mu) / len(data));
}

object pstdev(object data, object mu) {
    return object(pow((_ss(data ,mu) / len(data)), 0.5));
}

object variance(object data, object xbar) {
    return object(_ss(data, xbar) / (len(data) - 1));
}

object stdev(object data, object xbar) {
    return object(pow(_ss(data, xbar) / (len(data) - 1), 0.5));
}

object mode(object data) {
    std::map<object, int> counter;
    object value;
    int count = -1;

    if(len(data) == 0) {
        return object();
    }

    for(int i = 0;i < len(data);i++) {
        counter[data[i]]++;
        if (counter[data[i]] > count) {
            value = data[i];
            count = counter[data[i]];
        }
    }
    
    return value;
}

list multimode(object data) {
    std::map<object, int> counter;
    int count = -1;

    if(len(data) == 0) {
        return list();
    }

    for(int i = 0;i < len(data);i++) {
        counter[data[i]]++;
        if (counter[data[i]] > count) {
            count = counter[data[i]];
        }
    }

    list w;
    for (std::map<object, int>::iterator it = counter.begin(); it != counter.end(); ++it) {
        if (it->second == count) {
            w.append(it->first);
        }
    }
    return w;
}

list quantiles(object data, object n, object method) {
    list result;
    return result;
}

object median_grouped(object data, object interval) {
    if(len(data) == 0) {
        throw StatisticsError();
    } else if (len(data) == 1) {
        return data[0];
    }

    double L = extract<double>(data[len(data/2)]) + extract<double>(interval) / 2;
    // Add bisect details

    return object(L);
}

BOOST_PYTHON_MODULE(stats)
{
    register_exception_translator<StatisticsError>(&translate);
    def("mean", mean);
    def("fmean", mean);
    def("geometric_mean", geometric_mean);
    def("harmonic_mean", harmonic_mean);
    def("median", median);
    def("median_high", median_high);
    def("median_low", median_low);
    def("pvariance", pvariance, (args("data"), args("mu")=object()));
    def("variance", variance, (args("data"), args("xbar")=object()));
    def("pstdev", pstdev, (args("data"), args("mu")=object()));
    def("stdev", stdev, (args("data"), args("xbar")=object()));
    def("mode", mode);
    def("multimode", multimode);
    def("quantiles", quantiles, (arg("data"), arg("n")=4, arg("method")="exclusive"));
    def("median_grouped", median_grouped, (arg("data"), arg("interval")=1));
}