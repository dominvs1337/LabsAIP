#pragma once
#include "Node.hpp"
#include "SmartPointer.hpp"
#include "ExceptionHandler.hpp"
#include "ForwardIterator.hpp"
#include "ReverseIterator.hpp"

template <typename T>
class List {
private:
    Node<T>* head;
    Node<T>* tail;
    size_t size;

public:
    List() : head(nullptr), tail(nullptr), size(0) {}

    // Добавление элементов
    void push_front(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        ++size;
    }

    void push_back(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (!tail) {
            head = tail = newNode;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        ++size;
    }

    // Удаление элементов
    void pop_front() {
        if (!head) throw ExceptionHandler("List is empty");
        Node<T>* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        delete temp;
        --size;
    }

    void pop_back() {
        if (!tail) throw ExceptionHandler("List is empty");
        Node<T>* temp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        delete temp;
        --size;
    }

    // Доступ к элементам
    T& front() {
        if (!head) throw ExceptionHandler("List is empty");
        return head->value;
    }

    T& back() {
        if (!tail) throw ExceptionHandler("List is empty");
        return tail->value;
    }

    // Методы для проверки состояния
    bool empty() const { return size == 0; }
    size_t getSize() const { return size; }

    // Итераторы
    ForwardIterator<T> begin() {
        return ForwardIterator<T>(head);
    }

    ReverseIterator<T> rbegin() {
        return ReverseIterator<T>(tail);
    }

    // Деструктор
    ~List() {
        while (head) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }
};
