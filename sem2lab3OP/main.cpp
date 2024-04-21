#include <iostream>
#include "realisation.h"

int main() {
    int n, m;
    std::cin >> n >> m;
    Array arr1;
    for (int i = 0; i < n; i++) {
        arr1.append(1);
    }
    arr1.display();

    Array arr2;
    for (int i = 0; i < m; i++) {
        arr2.append(2);
    }
    arr2.display();
    Array arr3 = arr1 + arr2;
    arr3.display();

    std::cout << (arr1 == arr2) << std::endl;
    std::cout << (arr1 < arr2) << std::endl;
    std::cout << (arr1 != arr2) << std::endl;

    Complex c1(3.0, 4.0);
    Complex c2(1.0, -2.0);

    Complex sum = c1 + c2;
    Complex product1 = c1 * c2;
    Complex product2 = c1 * 2.0;

    Complex result1 = c1 + c2 + c1;
    Complex result2 = c1 * c2 * 2.0;

    std::cout << "Sum: " << sum.getReal() << " + " << sum.getImaginary() << "i" << std::endl;
    std::cout << "Product 1: " << product1.getReal() << " + " << product1.getImaginary() << "i" << std::endl;
    std::cout << "Product 2: " << product2.getReal() << " + " << product2.getImaginary() << "i" << std::endl;
    std::cout << "Result 1: " << result1.getReal() << " + " << result1.getImaginary() << "i" << std::endl;
    std::cout << "Result 2: " << result2.getReal() << " + " << result2.getImaginary() << "i" << std::endl;

    std::cout << "Length of c1: " << c1.length() << std::endl;

    return 0;
}

