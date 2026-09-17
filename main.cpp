#include <iostream>
#include <memory>
#include <cmath>
#include "shared_types.h"

std::unique_ptr<Result> calculateA(std::shared_ptr<const InputData> data);

int main() {
    // 1. Створюємо об'єкт із вхідними даними
    auto input = std::make_shared<InputData>();
    input->f = [](double x) { return std::sin(x); }; // Інтегруємо f(x) = sin(x)
    input->a = 0.0;
    input->b = 3.14159265358979323846;
    input->n = 100;

    std::cout << "=== Numerical Integration Project ===" << std::endl;

    auto resultA = calculateA(input);
    if (resultA) {
        std::cout << "[Student A] Simpson method result: " << resultA->value 
                  << " (Estimated error: " << resultA->error << ")" << std::endl;
    } else {
        std::cout << "[Student A] Function not implemented yet." << std::endl;
    }

    return 0;
}
