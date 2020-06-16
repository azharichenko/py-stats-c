//  "An implementation of the statistics module in the python standard library",
#include<boost/python.hpp>
#include<boost/operators.hpp>

#include<math.h>
#include<algorithm>
#include<map>
#include<vector>
#include<iostream>

using namespace boost::python;


double mean(object seq) {
    double total = 0.0;
    for(int i = 0;i < len(seq);i++) {
        total += extract<double>(seq[i]);
    }
    total /= len(seq);
    return total;
}

double geometric_mean(object seq) {
    double total = extract<double>(seq[0]);
    for(int i = 1;i < len(seq);i++) {
        total *= extract<double>(seq[i]);
    }
    return std::pow(total, 1.0 / len(seq));
}

double harmonic_mean(object seq) {
    double total = 0.0;
    for(int i = 0;i < len(seq);i++) {
        total += 1.0 / extract<double>(seq[i]);
    }
    total = len(seq) / total;
    return total;
}

object median(list seq) {
    seq.sort();
    long midway = len(seq) / 2;
    if (len(seq) % 2 == 0) {
        return object((extract<double>(seq[midway]) + extract<double>(seq[midway - 1])) / 2.0);
    }
    return seq[midway];
}

object median_low(list seq) {
    seq.sort();
    long midway = len(seq) / 2;
    if (len(seq) % 2 == 0) {
        return seq[midway - 1];
    }
    return seq[midway];
}

object median_high(list seq) {
    seq.sort();
    return seq[len(seq) / 2];
}

double _ss(object seq) {
    double mu = mean(seq);
    double pstdev = 0.0;

    for(int i = 0;i < len(seq);i++) {
        pstdev += std::pow(extract<double>(seq[i]) - mu, 2);
    }

    return pstdev;
}

double pvariance(object seq) {
    return _ss(seq) / len(seq);
}

double pstdev(object seq) {
    double pvar = pvariance(seq);
    return std::pow(pvar, 0.5);
}

double variance(object seq) {
    if(len(seq) == 1) {
        return 0;
    }
    return _ss(seq) / (len(seq) - 1);
}

double stdev(object seq) {
    double var = variance(seq);
    return std::pow(var, 0.5);
}

object mode(object seq) {
    std::map<object, int> counter;
    object value;
    int count = -1;

    if(len(seq) == 0) {
        return object();
    }

    for(int i = 0;i < len(seq);i++) {
        counter[seq[i]]++;
        if (counter[seq[i]] > count) {
            value = seq[i];
            count = counter[seq[i]];
        }
    }
    
    return value;
}

list multimode(object seq) {
    std::map<object, int> counter;
    int count = -1;

    if(len(seq) == 0) {
        return list();
    }

    for(int i = 0;i < len(seq);i++) {
        counter[seq[i]]++;
        if (counter[seq[i]] > count) {
            count = counter[seq[i]];
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

list quantiles(object data) {
    list result;
    return result;
}

BOOST_PYTHON_MODULE(stats)
{
    def("mean", mean);
    def("fmean", mean);
    def("geometric_mean", geometric_mean);
    def("harmonic_mean", harmonic_mean);
    def("median", median);
    def("median_high", median_high);
    def("median_low", median_low);
    def("pvariance", pvariance);
    def("variance", variance);
    def("pstdev", pstdev);
    def("stdev", stdev);
    def("mode", mode);
    def("multimode", multimode);
    def("quantiles", quantiles, (arg("data")));
}