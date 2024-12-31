#pragma once
#include "IteratorInterface.hpp"
#include "Node.hpp"
#include "ExceptionHandler.hpp"

template <typename T>
class ReverseIterator : public IteratorInterface<T> {
private:
    Node<T>* current;

public:
    ReverseIterator(Node<T>* start) : current(start) {}

    bool hasNext() const override {
        return current != nullptr;
    }

    T& next() override {
        if (!current) {
            throw ExceptionHandler("Start of collection reached.");
        }
        T& value = current->value;
        current = current->prev;
        return value;
    }
};
