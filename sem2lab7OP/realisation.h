#ifndef SEM2LAB7_REALISATION_H
#define SEM2LAB7_REALISATION_H

#include <iostream>
#include <iterator>
#include <stdexcept>
#include <algorithm>
#include <functional>

template<typename T>
class CircularBuffer {
private:
    T *buffer;
    size_t head, tail, capacity, count;
    bool full;

public:
    class iterator : public std::iterator<std::random_access_iterator_tag, T> {
    private:
        CircularBuffer *cb;
        size_t index;

    public:

        iterator(CircularBuffer &buffer, size_t start) : cb(&buffer), index(start) {}

        iterator &operator++() {
            index = (index + 1) % cb->capacity;
            return *this;
        }

        iterator operator++(int) {
            iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        iterator &operator--() {
            index = (index + cb->capacity - 1) % cb->capacity;
            return *this;
        }

        iterator operator--(int) {
            iterator tmp = *this;
            --(*this);
            return tmp;
        }

        bool operator==(const iterator &other) const {
            return index == other.index and cb == other.cb;
        }

        bool operator!=(const iterator &other) const {
            return !(*this == other);
        }

        T &operator*() {
            return cb->buffer[index];
        }

        T *operator->() {
            return &cb->buffer[index];
        }

        iterator &operator+=(ptrdiff_t n) {
            index = (index + n + cb->capacity) % cb->capacity;
            return *this;
        }

        iterator &operator-=(ptrdiff_t n) {
            index = (index - n + cb->capacity) % cb->capacity;
            return *this;
        }

        T &operator[](ptrdiff_t n) {
            return *(*this + n);
        }

        // Арифметические операторы
        friend iterator operator+(const iterator &it, ptrdiff_t n) {
            iterator tmp = it;
            tmp += n;
            return tmp;
        }

        friend iterator operator-(const iterator &it, ptrdiff_t n) {
            iterator tmp = it;
            tmp -= n;
            return tmp;
        }

        ptrdiff_t operator-(const iterator &other) const {
            if (cb != other.cb) throw std::logic_error("Iterators belong to different buffers");
            ptrdiff_t direct = index - other.index;
            ptrdiff_t wrap = (cb->capacity - other.index) + index;
            if (std::abs(direct) < std::abs(wrap)) {
                return direct;
            } else {
                return direct > 0 ? wrap : -wrap;
            }
        }

        bool operator<(const iterator &other) const {
            if (cb != other.cb) throw std::logic_error("Iterators belong to different buffers");
            return (*this - other) < 0;
        }

        bool operator>(const iterator &other) const {
            return other < *this;
        }

        bool operator<=(const iterator &other) const {
            return !(*this > other);
        }

        bool operator>=(const iterator &other) const {
            return !(*this < other);
        }
    };

    CircularBuffer(size_t capacity);

    ~CircularBuffer();

    void erase(iterator pos);

    void insert(iterator pos, const T &item);

    iterator end() {
        return iterator(*this, tail);
    }

    iterator begin() {
        return iterator(*this, head);
    }

    void resize(size_t new_capacity);

    void push_back(const T &item);

    void push_front(const T &item);

    void pop_back();

    void pop_front();

    T &operator[](size_t index);

    const T &operator[](size_t index) const;

    bool empty() const;

    bool isFull() const;

    size_t size() const;

    void clear();

    void Sort();

};

#endif //SEM2LAB7_REALISATION_H