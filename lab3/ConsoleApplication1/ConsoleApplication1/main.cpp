#include <iostream>
#include <string>
#include "Deque.hpp"
#include "ExceptionHandler.hpp"

void menu() {
    std::cout << "\nMenu:\n";
    std::cout << "1. Push front\n";
    std::cout << "2. Push back\n";
    std::cout << "3. Pop front\n";
    std::cout << "4. Pop back\n";
    std::cout << "5. Display front and back\n";
    std::cout << "6. Check empty\n";
    std::cout << "7. Exit\n";
}

template <typename T>
void testDeque() {
    Deque<T> dq;
    int choice;
    T value;

    while (true) {
        menu();
        std::cout << "Enter choice: ";
        std::cin >> choice;

        try {
            switch (choice) {
            case 1:
                std::cout << "Enter value: ";
                std::cin >> value;
                dq.push_front(value);
                break;
            case 2:
                std::cout << "Enter value: ";
                std::cin >> value;
                dq.push_back(value);
                break;
            case 3:
                dq.pop_front();
                std::cout << "Popped front element.\n";
                break;
            case 4:
                dq.pop_back();
                std::cout << "Popped back element.\n";
                break;
            case 5:
                std::cout << "Front: " << dq.front() << ", Back: " << dq.back() << std::endl;
                break;
            case 6:
                std::cout << (dq.empty() ? "Deque is empty." : "Deque is not empty.") << std::endl;
                break;
            case 7:
                return;
            default:
                std::cout << "Invalid choice. Try again.\n";
            }
        }
        catch (ExceptionHandler& e) {
            e.showMessage();
        }
    }
}

int main() {
    std::cout << "Choose type:\n1. int\n2. double\n3. string\n";
    int typeChoice;
    std::cin >> typeChoice;

    switch (typeChoice) {
    case 1:
        testDeque<int>();
        break;
    case 2:
        testDeque<double>();
        break;
    case 3:
        testDeque<std::string>();
        break;
    default:
        std::cout << "Invalid type choice!\n";
    }

    return 0;
}
