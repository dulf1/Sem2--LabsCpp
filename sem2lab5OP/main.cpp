#include "realisation.h"

using namespace std;

int main(){
    try {
        Matrix<int> matrix(3, 3);
        matrix.at(0, 0) = 1;
        matrix.at(2, 2) = 9;
        matrix.at(3, 3) = 10;
        matrix.add(3,4,10);
    } catch (const MatrixListOfRange& e) {
        std::cout << "Caught exception: " << e.what() << "\n";
    }
}