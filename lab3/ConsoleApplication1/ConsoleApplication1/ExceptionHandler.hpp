#pragma once
#include <iostream>

class ExceptionHandler {
private:
    std::string message;
public:
    ExceptionHandler(const std::string& msg) : message(msg) {}
    void showMessage() const { std::cerr << "Error: " << message << std::endl; }
};
