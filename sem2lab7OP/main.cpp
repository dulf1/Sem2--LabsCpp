#include "realisation.h"

int main() {
    CircularBuffer<int> buffer(5);
    buffer.push_back(2);
    buffer.push_back(100);
    buffer.push_back(4);
    buffer.push_back(55);
    buffer.push_back(1);
    buffer.push_back(5);
    std::cout << *buffer.end() << " " << *buffer.begin() << "\n";
    buffer.pop_back();
    buffer.pop_front();
    auto it = buffer.begin();
    it++;
    buffer.insert(it,1);
    std::sort(buffer.begin(), buffer.end());
    std::cout << "Buffer is full: " << std::boolalpha << buffer.isFull() << std::endl;

    std::cout << "Buffer contents: ";
    for (int i = 0; i < buffer.size(); i++) {
        std::cout << buffer[i] << " ";
    }
    std::cout << "\n";

    std::cout << "Buffer contents after pop_front() and pop_back(): ";
    for (int i = 0; i < buffer.size(); i++) {
        std::cout << buffer[i] << " ";
    }
    std::cout << "\n";

    std::cout << "Buffer contents using iterators: ";
    for (auto it = buffer.begin(); it != buffer.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    buffer.clear();

    std::cout << "Buffer is empty: " << std::boolalpha << buffer.empty() << std::endl;

    return 0;
}