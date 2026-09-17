#include "shared_types.h"
#include <memory>
#include <cmath>

std::unique_ptr<Result> calculateB(std::shared_ptr<const InputData> data) {
    if (!data || data->n <= 0) {
        return std::make_unique<Result>(Result{ 0.0, -1.0 });
    }

    double h = (data->b - data->a) / data->n;
    double sum = 0.5 * (data->f(data->a) + data->f(data->b));

    for (int i = 1; i < data->n; ++i) {
        double x = data->a + i * h;
        sum += data->f(x);
    }
    double integral_n = h * sum;

    int n2 = data->n / 2;
    if (n2 <= 0) {
        return std::make_unique<Result>(Result{ integral_n, 0.0 });
    }

    double h2 = (data->b - data->a) / n2;
    double sum2 = 0.5 * (data->f(data->a) + data->f(data->b));

    for (int i = 1; i < n2; ++i) {
        double x = data->a + i * h2;
        sum2 += data->f(x);
    }
    double integral_n2 = h2 * sum2;

    double error_estimate = std::abs(integral_n - integral_n2) / 3.0;

    return std::make_unique<Result>(Result{ integral_n, error_estimate });
}