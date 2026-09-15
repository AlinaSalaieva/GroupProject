#include <iostream>
#include <memory>
#include <cmath>
#include "shared_types.h"

std::unique_ptr<Result> calculateA(std::shared_ptr<const InputData> data);
std::unique_ptr<Result> calculateB(std::shared_ptr<const InputData> data);

int main() {
    auto data = std::make_shared<const InputData>(InputData{
        [](double x) { return x * x; },
        0.0,
        2.0,
        1000
    });

    std::cout << "--- Integration comparison ---" << std::endl;

    return 0;
}
