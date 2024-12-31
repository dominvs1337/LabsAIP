#pragma once

template <typename T>
class IteratorInterface {
public:
    virtual bool hasNext() const = 0;   // Проверка наличия следующего элемента
    virtual T& next() = 0;              // Переход к следующему элементу
    virtual ~IteratorInterface() = default;
};
