#include "realisation.h"

int main() {
    int y = 2;
    CPoint z = {1,1};
    std::vector<int> v = {1, 3, 5, 7, 9};
    std::vector<CPoint> d = {{1,1},{2,3},{4,5}};
    std::function<bool(int)> odd = [](int x) { return x % 2 == 1; };
    std::function<bool(int)> even = [](int x) { return x % 2 == 0; };
    std::function<bool(CPoint&)> odd2 = [](CPoint &x) { return x.first % 2 == 1 and x.second%2==1; };
    std::function<bool(CPoint&)> even2 = [](CPoint &x) { return x.first % 2 == 0 and x.second%2==0; };
    std::cout << "all_of: " << one_of(v.begin(), v.end(), even ) << "\n";
    std::cout << "any_of: " << std::any_of(v.begin(), v.end(), odd) << "\n";
    std::cout << "none_of: " << *find_not(v.begin(), v.end(), y) << "\n\n";
    std::cout << "all_of: " << one_of(d.begin(), d.end(), even2 ) << "\n";
    std::cout << "any_of: " << std::any_of(d.begin(), d.end(), odd2) << "\n";
    std::cout << "none_of: " << *find_not(d.begin(), d.end(), z) << "\n";
}