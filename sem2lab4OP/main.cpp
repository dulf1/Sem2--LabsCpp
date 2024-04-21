 #include "realisation.h"

int main() {
    short n;
    std::cout << "Write how many figures do you want to add:\n";
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        addFigure();
    }
    sort();
    displayFigures();
    clearFigures();
    return 0;
}