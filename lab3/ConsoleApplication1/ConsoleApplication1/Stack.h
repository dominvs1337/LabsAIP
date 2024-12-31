#include "List.h"
#include <initializer_list>
#include <stdexcept>

template <typename T>
class Stack {
private:
    List<T> list;

public:
    Stack() = default;

    // Конструктор с initializer_list
    Stack(std::initializer_list<T> initList) {
        for (const T& value : initList) {
            push(value);
        }
    }

    // Конструктор копирования
    Stack(const Stack& other) : list(other.list) {}

    // Оператор присваивания копированием
    Stack& operator=(const Stack& other) {
        if (this != &other) {
            list = other.list;
        }
        return *this;
    }

    // Конструктор перемещения
    Stack(Stack&& other) noexcept : list(std::move(other.list)) {}

    // Оператор присваивания перемещением
    Stack& operator=(Stack&& other) noexcept {
        if (this != &other) {
            list = std::move(other.list);
        }
        return *this;
    }

    // Метод для добавления элемента в стек
    void push(const T& value) {
        list.push_back(value);
    }

    // Метод для удаления верхнего элемента из стека
    void pop() {
        if (empty()) {
            throw std::out_of_range("Stack is empty");
        }
        list.pop_back();
    }

    // Метод для получения верхнего элемента стека
    T& top() {
        if (empty()) {
            throw std::out_of_range("Stack is empty");
        }
        return list.back();
    }

    // Метод для проверки, пустой ли стек
    bool empty() const {
        return list.empty();
    }
};