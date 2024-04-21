#ifndef SEM2LAB6_REALISATION_H
#define SEM2LAB6_REALISATION_H

#include <iostream>
#include <vector>
#include <functional>

template <typename InputIt, typename Predicate>
bool any_of(InputIt first, InputIt last, Predicate p);

template <typename InputIt, typename Predicate>
bool one_of(InputIt first, InputIt last, Predicate p);

template <typename InputIt, typename T>
InputIt find_not(InputIt first, InputIt last, const T& value);

class CPoint {
public:
    int first, second;
    CPoint(int a, int b);
    bool operator==(const CPoint& other);
    bool operator<(const CPoint& other);
    bool operator!=(const CPoint& other);
    friend std::ostream& operator<<(std::ostream& os, const CPoint& point);
};


#endif //SEM2LAB6_REALISATION_H