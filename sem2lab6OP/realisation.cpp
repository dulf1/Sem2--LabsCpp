#include "realisation.h"

template bool one_of(std::vector<int>::iterator first, std::vector<int>::iterator last, std::function<bool(int)> p);
template bool one_of(std::vector<CPoint>::iterator first, std::vector<CPoint>::iterator last, std::function<bool(CPoint&)> p);
template bool any_of(std::vector<int>::iterator first, std::vector<int>::iterator last, std::function<bool(int)> p);
template bool any_of(std::vector<CPoint>::iterator first, std::vector<CPoint>::iterator last, std::function<bool(CPoint&)> p);
template std::vector<int>::iterator find_not(std::vector<int>::iterator first, std::vector<int>::iterator last, const int& value);
template std::vector<CPoint>::iterator find_not(std::vector<CPoint>::iterator first, std::vector<CPoint>::iterator last, const CPoint& value);

std::ostream& operator<<(std::ostream& os, const CPoint& point) {
    os << '(' << point.first << ", " << point.second << ')';
    return os;
}
template <typename InputIt, typename Predicate>
bool any_of(InputIt first, InputIt last, Predicate p) {
    for (; first != last; ++first) {
        if (p(*first)) {
            return true;
        }
    }
    return false;
}

template <typename InputIt, typename Predicate>
bool one_of(InputIt first, InputIt last, Predicate p) {
    bool found = false;
    for (; first != last; ++first) {
        if (p(*first)) {
            if (found) {
                return false;
            }
            found = true;
        }
    }
    return found;
}

template <typename InputIt, typename T>
InputIt find_not(InputIt first, InputIt last, const T& value) {
    for (; first != last; ++first) {
        if (*first != value) {
            return first;
        }
    }
    return last;
}

CPoint::CPoint(int a, int b) {
    first = a;
    second = b;
}

bool CPoint::operator==(const CPoint& other) {
    return this->second == other.second and this->first == other.first;
}

bool CPoint::operator<(const CPoint& other) {
    return this->second < other.second and this->first < other.first;
}

bool CPoint::operator!=(const CPoint& other) {
    return this->second != other.second or this->first != other.first;
}