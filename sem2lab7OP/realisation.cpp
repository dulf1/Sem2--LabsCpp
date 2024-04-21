#include "realisation.h"

template <typename T>
CircularBuffer<T>::CircularBuffer(size_t capacity): capacity(capacity), head(0), tail(0), count(0), full(false) {
    buffer = new T[capacity];
}
template <typename T>
CircularBuffer<T>::~CircularBuffer() {
    delete[] buffer;
}
template <typename T>
void CircularBuffer<T>::resize(size_t new_capacity) {
    T* new_buffer = new T[new_capacity];
    size_t current_size = size();
    for (size_t i = 0; i < current_size; ++i) {
        new_buffer[i] = (*this)[i];
    }
    delete[] buffer;
    buffer = new_buffer;
    capacity = new_capacity;
    head = 0;
    tail = current_size;
    count = current_size;
    full = count == capacity;
}
template <typename T>
void CircularBuffer<T>::push_back(const T &item) {
    if (full) resize(capacity * 2);
    buffer[tail] = item;
    tail = (tail + 1) % capacity;
    if (tail == head) full = true;
    count = std::min(count + 1, capacity);
}
template <typename T>
void CircularBuffer<T>::push_front(const T &item) {
    if (full) resize(capacity * 2);
    head = (head + capacity - 1) % capacity;
    buffer[head] = item;
    if (tail == head) full = true;
    count = std::min(count + 1, capacity);
}
template <typename T>
void CircularBuffer<T>::pop_back() {
    if (empty()) return;
    tail = (tail + capacity - 1) % capacity;
    full = false;
    count = count > 0 ? count - 1 : 0;
}
template <typename T>
void CircularBuffer<T>::pop_front() {
    if (empty()) return;
    head = (head + 1) % capacity;
    full = false;
    count = count > 0 ? count - 1 : 0;
}
template <typename T>
T &CircularBuffer<T>::operator[](size_t index){
    return buffer[(head + index) % capacity];
}
template <typename T>
const T &CircularBuffer<T>::operator[](size_t index) const{
    return buffer[(head + index) % capacity];
}
template <typename T>
bool CircularBuffer<T>::empty() const {
    return count == 0;
}
template <typename T>
bool CircularBuffer<T>::isFull() const {
    return full;
}
template <typename T>
size_t CircularBuffer<T>::size() const {
    return count;
}
template <typename T>
void CircularBuffer<T>::clear() {
    head = 0;
    tail = 0;
    count = 0;
    full = false;
}
template <typename T>
void CircularBuffer<T>::Sort() {
    std::sort(begin(),end());
}

template <typename T>
void CircularBuffer<T>::insert(iterator pos, const T &item) {
    if (full) resize(capacity * 2);
    size_t insertIndex = pos - begin();
    if (insertIndex < count / 2) {
        head = (head + capacity - 1) % capacity;
        for (size_t i = 0; i < insertIndex; ++i) {
            buffer[(head + i) % capacity] = buffer[(head + i + 1) % capacity];
        }
    } else {
        for (size_t i = count; i > insertIndex; --i) {
            buffer[(head + i) % capacity] = buffer[(head + i - 1) % capacity];
        }
        tail = (tail + 1) % capacity;
    }
    buffer[(head + insertIndex) % capacity] = item;
    count++;
    full = count == capacity;
}

template <typename T>
void CircularBuffer<T>::erase(iterator pos) {
    if (empty()) return;
    size_t eraseIndex = pos - begin();
    if (eraseIndex < count / 2) {
        // Сдвигаем элементы вправо
        for (size_t i = eraseIndex; i > 0; --i) {
            buffer[(head + i) % capacity] = buffer[(head + i - 1) % capacity];
        }
        head = (head + 1) % capacity;
    } else {
        for (size_t i = eraseIndex; i < count - 1; ++i) {
            buffer[(head + i) % capacity] = buffer[(head + i + 1) % capacity];
        }
        tail = (tail + capacity - 1) % capacity;
    }
    count--;
    full = false;
}

template class CircularBuffer<int>;