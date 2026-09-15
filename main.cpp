#include <iostream>
#include <memory>
#include <cmath>
#include "shared_types.h"

// Прототипи функцій
std::unique_ptr<Result> calculateA(std::shared_ptr<const InputData> data);
std::unique_ptr<Result> calculateB(std::shared_ptr<const InputData> data);

int main() {
    // 1. Створення вхідних даних
    auto input = std::make_shared<InputData>();
    input->f = [](double x) { return std::sin(x); };
    input->a = 0.0;
    input->b = 3.14159265358979323846;
    input->n = 100;

    std::cout << "=== Numerical Integration Project ===" << std::endl;

    // 2. Виклик функції Student A
    auto resultA = calculateA(input);
    if (resultA) {
        // Опрацювання за допомогою Structured Bindings (C++17/C++20)
        auto [valueA, errorA] = *resultA;
        std::cout << "[Student A] Simpson method result: " << valueA 
                  << " (Estimated error: " << errorA << ")" << std::endl;
    } else {
        std::cout << "[Student A] Function not implemented yet." << std::endl;
    }

    // 3. Виклик функції Student B
    auto resultB = calculateB(input);
    if (resultB) {
        auto [valueB, errorB] = *resultB;
        std::cout << "[Student B] Result: " << valueB 
                  << " (Estimated error: " << errorB << ")" << std::endl;
    } else {
        std::cout << "[Student B] Function not implemented yet." << std::endl;
    }

    return 0;
}
