#ifndef SHARED_TYPES_H
#define SHARED_TYPES_H

#include <functional>

struct InputData {
    std::function<double(double)> f;
    double a;
    double b;
    int n;
};

struct Result {
    double value;
    double error;
};

#endif // SHARED_TYPES_H
