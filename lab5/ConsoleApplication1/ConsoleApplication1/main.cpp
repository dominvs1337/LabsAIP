#include <iostream>
#include "List.hpp"
#include "ForwardIterator.hpp"
#include "ReverseIterator.hpp"

void menu() {
    std::cout << "\nMenu:\n";
    std::cout << "1. Push back\n";
    std::cout << "2. Display forward iteration\n";
    std::cout << "3. Display reverse iteration\n";
    std::cout << "4. Exit\n";
}

int main() {
    List<int> list;
    int choice, value;

    while (true) {
        menu();
        std::cout << "Enter choice: ";
        std::cin >> choice;

        try {
            switch (choice) {
            case 1:
                std::cout << "Enter value: ";
                std::cin >> value;
                list.push_back(value);
                break;
            case 2:
                std::cout << "Forward iteration:\n";
                try {
                    auto it = list.begin();
                    while (it.hasNext()) {
                        std::cout << it.next() << " ";
                    }
                    std::cout << std::endl;
                }
                catch (const ExceptionHandler& e) {
                    e.showMessage();
                }
                break;
            case 3:
                std::cout << "Reverse iteration:\n";
                try {
                    auto rit = list.rbegin();
                    while (rit.hasNext()) {
                        std::cout << rit.next() << " ";
                    }
                    std::cout << std::endl;
                }
                catch (const ExceptionHandler& e) {
                    e.showMessage();
                }
                break;
            case 4:
                return 0; // Возвращаем 0 для успешного завершения программы
            default:
                std::cout << "Invalid choice. Try again.\n";
            }
        }
        catch (ExceptionHandler& e) {
            e.showMessage();
        }
    }

    return 0;
}
