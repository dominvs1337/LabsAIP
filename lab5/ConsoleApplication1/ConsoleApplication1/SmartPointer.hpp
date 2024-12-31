#pragma once

template <typename T>
class SmartPointer {
private:
    T* ptr;
public:
    SmartPointer(T* p = nullptr) : ptr(p) {}
    ~SmartPointer() { delete ptr; }
    T& operator*() { return *ptr; }
    T* operator->() { return ptr; }
    SmartPointer(const SmartPointer&) = delete; // ������ �����������
    SmartPointer& operator=(const SmartPointer&) = delete; // ������ ������������
};
