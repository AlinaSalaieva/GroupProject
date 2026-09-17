#include "shared_types.h"
#include <memory>
#include <cmath>

std::unique_ptr<Result> calculateA(std::shared_ptr<const InputData> data) {
    if (!data || data->n % 2 != 0 || data->n <= 0) {
        return std::make_unique<Result>(Result{ 0.0, -1.0 });
    }

    double h = (data->b - data->a) / data->n;
    double sum = data->f(data->a) + data->f(data->b);

    for (int i = 1; i < data->n; ++i) {
        double x = data->a + i * h;
        if (i % 2 == 0) {
            sum += 2.0 * data->f(x);
        } else {
            sum += 4.0 * data->f(x);
        }
    }

    double integral_n = (h / 3.0) * sum;

    int n2 = data->n / 2;
    double h2 = (data->b - data->a) / n2;
    double sum2 = data->f(data->a) + data->f(data->b);
    for (int i = 1; i < n2; ++i) {
        double x = data->a + i * h2;
        sum2 += (i % 2 == 0) ? 2.0 * data->f(x) : 4.0 * data->f(x);
    }
    double integral_n2 = (h2 / 3.0) * sum2;
    double error_estimate = std::abs(integral_n - integral_n2) / 15.0;

    return std::make_unique<Result>(Result{ integral_n, error_estimate });
}
