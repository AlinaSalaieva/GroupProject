#include <iostream>
#include <memory>
#include <cmath>
#include "shared_types.h"

std::unique_ptr<Result> calculateB(std::shared_ptr<const InputData> data);

int main() {
    auto input = std::make_shared<const InputData>(InputData{
        .f = [](double x) { return std::sin(x); },
        .a = 0.0,
        .b = 3.14159265358979323846,
        .n = 1000
        });

    std::cout << "=== Integration Results ===\n";

    auto resultB = calculateB(input);
    if (resultB) {
        auto [valueB, errorB] = *resultB;
        std::cout << "Student B - Trapezoidal result: " << valueB
            << " (Estimated error: " << errorB << ")" << std::endl;
    }
    else {
        std::cout << "[Student B] Function not implemented yet." << std::endl;
    }
    return 0;
}