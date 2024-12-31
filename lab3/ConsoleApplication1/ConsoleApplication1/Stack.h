#include "List.h"
#include <initializer_list>
#include <stdexcept>

template <typename T>
class Stack {
private:
    List<T> list;

public:
    Stack() = default;

    // ����������� � initializer_list
    Stack(std::initializer_list<T> initList) {
        for (const T& value : initList) {
            push(value);
        }
    }

    // ����������� �����������
    Stack(const Stack& other) : list(other.list) {}

    // �������� ������������ ������������
    Stack& operator=(const Stack& other) {
        if (this != &other) {
            list = other.list;
        }
        return *this;
    }

    // ����������� �����������
    Stack(Stack&& other) noexcept : list(std::move(other.list)) {}

    // �������� ������������ ������������
    Stack& operator=(Stack&& other) noexcept {
        if (this != &other) {
            list = std::move(other.list);
        }
        return *this;
    }

    // ����� ��� ���������� �������� � ����
    void push(const T& value) {
        list.push_back(value);
    }

    // ����� ��� �������� �������� �������� �� �����
    void pop() {
        if (empty()) {
            throw std::out_of_range("Stack is empty");
        }
        list.pop_back();
    }

    // ����� ��� ��������� �������� �������� �����
    T& top() {
        if (empty()) {
            throw std::out_of_range("Stack is empty");
        }
        return list.back();
    }

    // ����� ��� ��������, ������ �� ����
    bool empty() const {
        return list.empty();
    }
};