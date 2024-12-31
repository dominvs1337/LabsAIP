#include <iostream>
#include <stdexcept>
#include <initializer_list>

using namespace std;

template <typename T>
class Stack {
private:
    struct Node {
        T value;           
        Node* next;       
        Node* prev;       

        Node(const T& val, Node* p = nullptr, Node* n = nullptr)
            : value(val), prev(p), next(n) {
        }

        friend class Stack<T>;
    };

    Node* head;
    Node* tail;
    size_t size_;

    void clear() {
        while (size_) {
            pop();
        }
    }

public:
    Stack() : head(nullptr), tail(nullptr), size_(0) {}

    Stack(initializer_list<T> initList) : Stack() {
        for (const auto& item : initList) {
            push(item);
        }
    }

    Stack(const Stack& other) : Stack() {
        for (Node* current = other.head; current != nullptr; current = current->next) {
            push(current->value);
        }
    }

    Stack& operator=(const Stack& other) {
        if (this != &other) {
            clear();
            for (Node* current = other.head; current != nullptr; current = current->next) {
                push(current->value);
            }
        }
        return *this;
    }

    Stack(Stack&& other) noexcept : head(other.head), tail(other.tail), size_(other.size_) {
        other.head = other.tail = nullptr;
        other.size_ = 0;
    }


    Stack& operator=(Stack&& other) noexcept {
        if (this != &other) {
            clear();
            head = other.head;
            tail = other.tail;
            size_ = other.size_;
            other.head = other.tail = nullptr;
            other.size_ = 0;
        }
        return *this;
    }

    ~Stack() {
        clear();
    }

    void push(const T& value) {
        Node* newNode = new Node(value, tail, nullptr);
        if (tail) tail->next = newNode;
        tail = newNode;
        if (!head) head = newNode;
        ++size_;
    }

    void pop() {
        if (!tail) {
            throw underflow_error("Стек пуст. Невозможно удалить элемент.");
        }
        Node* toDelete = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete toDelete;
        --size_;
    }

    void insertAt(size_t pos, const T& value) {
        if (pos > size_) throw out_of_range("Позиция выходит за пределы размера.");

        if (pos == size_) {
            push(value);
            return;
        }

        Node* current = head;
        for (size_t i = 0; i < pos; ++i) {
            current = current->next;
        }

        Node* newNode = new Node(value, current->prev, current);
        if (current->prev) current->prev->next = newNode;
        else head = newNode;
        current->prev = newNode;
        ++size_;
    }

    T& operator[](size_t index) {
        if (index >= size_) throw out_of_range("Индекс выходит за пределы размера.");

        Node* current = head;
        for (size_t i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->value;
    }

    size_t size() const {
        return size_;
    }

    bool isEmpty() const {
        return size_ == 0;
    }

    T top() const {
        if (!tail) throw underflow_error("Стек пуст. Невозможно получить элемент.");
        return tail->value;
    }
};

int main() {
    setlocale(0, "");
    Stack<int> stack = { 1, 2, 3, 4, 5 };

    cout << "Начальный стек: \n";
    for (size_t i = 0; i < stack.size(); ++i) {
        cout << stack[i] << " ";
    }
    cout << "\n";

    cout << "Добавление элемента 99 на позицию 2: \n";
    stack.insertAt(2, 99);
    for (size_t i = 0; i < stack.size(); ++i) {
        cout << stack[i] << " ";
    }
    cout << "\n";

    cout << "Удаление элемента с конца.\n";
    stack.pop();
    for (size_t i = 0; i < stack.size(); ++i) {
        cout << stack[i] << " ";
    }
    cout << "\n";

    return 0;
}