#include <iostream>
#include <stdexcept>  // For std::runtime_error

int factorial(int n) {
    if (n < 0) {
        throw std::runtime_error("Factorial is not defined for negative numbers.");
    } else if (n == 0 || n == 1) {
        return 1;
    } else {
        int result = 1;
        for (int i = 2; i <= n; ++i) {
            result *= i;
        }
        return result;
    }
}

int main() {
    try {
        int num;
        std::cout << "Enter a number: ";
        std::cin >> num;

        std::cout << "Factorial of " << num << " is " << factorial(num) << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
