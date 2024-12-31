#pragma once
#include "IteratorInterface.hpp"
#include "Node.hpp"
#include "ExceptionHandler.hpp"

template <typename T>
class ForwardIterator : public IteratorInterface<T> {
private:
    Node<T>* current;

public:
    ForwardIterator(Node<T>* start) : current(start) {}

    bool hasNext() const override {
        return current != nullptr;
    }

    T& next() override {
        if (!current) {
            throw ExceptionHandler("End of collection reached.");
        }
        T& value = current->value;
        current = current->next;
        return value;
    }
};
