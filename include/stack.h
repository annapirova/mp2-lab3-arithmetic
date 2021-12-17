// объявление и реализация шаблонного стека
// стек поддерживает операции:
// - вставка элемента,
// - извлечение элемента,
// - просмотр верхнего элемента (без удаления)
// - проверка на пустоту,
// - получение количества элементов в стеке
// - очистка стека
// при вставке в полный стек должна перевыделяться память


#ifndef MP2_LAB3_ARITHMETIC_STACK_H
#define MP2_LAB3_ARITHMETIC_STACK_H

#include <ostream>

template<typename T>
class TStack {
private:
    T *pContent;
    int size;
    int capacity;
public:
    explicit TStack(int capacity_ = 0);

    TStack(const TStack<T> &stack_);

    ~TStack();

    void push(const T &value);

    void pop();

    const T &top();

    bool empty();

    int getSize();

    void clear();

    friend std::ostream &operator<<(std::ostream &out, const TStack<T> &stack_) {
        for (int i = 0; i < stack_.size; i++)
            out << stack_.pContent[i] << ' ';
        return out;
    }
};

template<typename T>
TStack<T>::TStack(int capacity_) {
    if (capacity_ < 0) {
        throw std::logic_error("capacity < 0");
    }
    size = 0;
    capacity = capacity_ + capacity_;
    pContent = new T[capacity];
}

template<typename T>
TStack<T>::TStack(const TStack<T> &stack_) {
    size = stack_.size;
    capacity = size + size;
    pContent = new T[capacity];
    for (int i = 0; i < size; ++i) {
        pContent[i] = stack_.pContent[i];
    }
}

template<typename T>
TStack<T>::~TStack() {
    delete[]pContent;
}

template<typename T>
void TStack<T>::push(const T &value) {
    if (size == capacity) {
        auto tmpCapacity = capacity;
        T *tmpContent = new T[tmpCapacity];
        for (int i = 0; i < size; ++i) {
            tmpContent[i] = pContent[i];
        }
        delete[]pContent;
        capacity = capacity + capacity;
        pContent = new T[capacity];
        for (int i = 0; i < tmpCapacity; ++i) {
            pContent[i] = tmpContent[i];
        }
    }
    size++;
    pContent[size - 1] = value;
}

template<typename T>
void TStack<T>::pop() {
    if (empty()) {
        throw std::logic_error("pop from empty stack");
    }
    size--;
}

template<typename T>
const T &TStack<T>::top() {
    if (empty()) {
        throw std::logic_error("get top in empty stack");
    }
    return pContent[size - 1];
}

template<typename T>
bool TStack<T>::empty() {
    return !bool(size);
}

template<typename T>
int TStack<T>::getSize() {
    return size;
}

template<typename T>
void TStack<T>::clear() {
    if (!empty()) {
        size = 0;
        delete[]pContent;
        pContent = new T[capacity];
    }
}


#endif //MP2_LAB3_ARITHMETIC_STACK_H