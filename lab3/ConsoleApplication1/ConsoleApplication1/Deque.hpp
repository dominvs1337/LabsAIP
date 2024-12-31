#pragma once
#include "List.hpp"

template <typename T>
class Deque {
private:
    List<T> list;

public:
    Deque() = default;

    void push_front(const T& value) {
        list.push_front(value);
    }

    void push_back(const T& value) {
        list.push_back(value);
    }

    void pop_front() {
        list.pop_front();
    }

    void pop_back() {
        list.pop_back();
    }

    T& front() {
        return list.front();
    }

    T& back() {
        return list.back();
    }

    bool empty() const {
        return list.empty();
    }

    size_t size() const {
        return list.getSize();
    }
};
