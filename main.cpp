#include <iostream>
#include <memory>
#include <cmath>
#include "shared_types.h"

std::unique_ptr<Result> calculateA(std::shared_ptr<const InputData> data);
std::unique_ptr<Result> calculateB(std::shared_ptr<const InputData> data);

int main() {
    auto input = std::make_shared<InputData>();
    input->f = [](double x) { return std::sin(x); };
    input->a = 0.0;
    input->b = 3.14159265358979323846;
    input->n = 100;

    std::cout << "=== Numerical Integration Project ===" << std::endl;

    auto resultB = calculateB(input);
    if (resultB) {
        auto [valueB, errorB] = *resultB;
        std::cout << "[Student B] Result: " << valueB
            << " (Estimated error: " << errorB << ")" << std::endl;
    }
    else {
        std::cout << "[Student B] Function not implemented yet." << std::endl;
    }

    return 0;
}
