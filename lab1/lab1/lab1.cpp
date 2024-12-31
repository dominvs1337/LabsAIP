#include <iostream>
#include <cmath>
#include <stdexcept>

// Класс исключения
class CustomException : public std::exception {
private:
    std::string message;
    double value;
    int errorCode;

public:
    CustomException(const std::string& msg, double val, int code)
        : message(msg), value(val), errorCode(code) {
    }

    const char* what() const noexcept override {
        return message.c_str();
    }

    double getValue() const {
        return value;
    }

    int getErrorCode() const {
        return errorCode;
    }
};

// Функция для вычисления Z1
double computeZ1(double& b) {
    double result;
    double discriminant = b * b - 4.0;

    if (discriminant < 0) {
        throw CustomException("Discriminant is negative", discriminant, 1);
    }

    double sqrtDiscriminant = sqrt(discriminant);
    double denominator = sqrtDiscriminant + b + 2.0;

    if (denominator == 0) {
        throw CustomException("Division by zero in Z1", denominator, 2);
    }

    result = (sqrt(2.0 * b + 2.0 * sqrtDiscriminant)) / denominator;
    return result;
}

// Функция для вычисления Z2
double computeZ2(double& b) {
    double result;
    double sqrtTerm = sqrt(b + 2.0);

    if (sqrtTerm == 0) {
        throw CustomException("Division by zero in Z2", sqrtTerm, 3);
    }

    result = 1.0 / sqrtTerm;
    return result;
}

int main() {
    double b = 5.0; // Пример значения b

    try {
        double z1 = computeZ1(b);
        double z2 = computeZ2(b);

        std::cout << "Z1 = " << z1 << std::endl;
        std::cout << "Z2 = " << z2 << std::endl;

        if (std::abs(z1 - z2) < 1e-6) {
            std::cout << "Values are approximately equal." << std::endl;
        }
        else {
            std::cout << "Values are not approximately equal." << std::endl;
        }
    }
    catch (const CustomException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        std::cerr << "Value: " << e.getValue() << std::endl;
        std::cerr << "Error Code: " << e.getErrorCode() << std::endl;
    }

    return 0;
}