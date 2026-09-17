#include <iostream>
#include <memory>
#include <cmath>
#include <chrono>
#include "shared_types.h"

std::unique_ptr<Result> calculateA(std::shared_ptr<const InputData> data);
std::unique_ptr<Result> calculateB(std::shared_ptr<const InputData> data);

int main() {
    size_t evalCount = 0;

    auto input = std::make_shared<InputData>();
    input->f = [&evalCount](double x) {
        evalCount++;
        return std::sin(x);
        };
    input->a = 0.0;
    input->b = 3.14159265358979323846;
    input->n = 100;

    const double exactValue = 2.0;

    std::cout << "=== Numerical Integration Comparison ===" << std::endl;

    evalCount = 0;
    auto startA = std::chrono::high_resolution_clock::now();
    auto resultA = calculateA(input);
    auto endA = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> timeA = endA - startA;

    if (resultA) {
        auto [valueA, errorA] = *resultA;
        std::cout << "\n[Student A - Simpson Method]" << std::endl;
        std::cout << "Result: " << valueA << std::endl;
        std::cout << "Estimated Error: " << errorA << std::endl;
        std::cout << "Actual Error: " << std::abs(valueA - exactValue) << std::endl;
        std::cout << "Function Evaluations: " << evalCount << std::endl;
        std::cout << "Execution Time: " << timeA.count() << " us" << std::endl;
    }
    else {
        std::cout << "[Student A] Function not implemented yet." << std::endl;
    }

    evalCount = 0;
    auto startB = std::chrono::high_resolution_clock::now();
    auto resultB = calculateB(input);
    auto endB = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> timeB = endB - startB;

    if (resultB) {
        auto [valueB, errorB] = *resultB;
        std::cout << "\n[Student B - Trapezoidal Method]" << std::endl;
        std::cout << "Result: " << valueB << std::endl;
        std::cout << "Estimated Error: " << errorB << std::endl;
        std::cout << "Actual Error: " << std::abs(valueB - exactValue) << std::endl;
        std::cout << "Function Evaluations: " << evalCount << std::endl;
        std::cout << "Execution Time: " << timeB.count() << " us" << std::endl;
    }
    else {
        std::cout << "[Student B] Function not implemented yet." << std::endl;
    }

    return 0;
}