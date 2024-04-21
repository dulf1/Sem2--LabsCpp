#include "realisation.h"

std::vector<BaseCObject *> figures;

void addFigure() {
    short choice;
    std::cout << "Choose a figure to add:\n";
    std::cout << "1. Circle\n";
    std::cout << "2. Isosceles Trapezoid\n";
    std::cout << "0. Exit\n";
    std::cin >> choice;
    BaseCObject *newFigure;
    switch (choice) {
        case 1:
            newFigure = new Circle();
            break;
        case 2:
            newFigure = new IsoscelesTrapezoid();
            break;
        case 0:
            return;
        default:
            std::cout << "Invalid choice." << std::endl;
            return;
    }

    auto *x = dynamic_cast<IDialogInitiable *>(newFigure);
    x->initFromDialog();
    figures.push_back(newFigure);
}

void displayFigures() {
    if (figures.empty()) {
        return;
    }
    int memory = 0;
    int square = 0;
    int perimeter = 0;
    int center = 0;
    for (auto *figure: figures) {
        auto *printable = dynamic_cast<IPrintable *>(figure);
        auto *x = dynamic_cast<IGeoFig *>(figure);
        auto *y = dynamic_cast<IPhysObject *>(figure);
        square += x->square();
        perimeter += x->perimeter();
        center += y->mass();
        memory += sizeof(figures);
        if (printable) {
            printable->draw();
        } else {
            std::cout << "Error 404\n" << std::endl;
        }
    }
    std::cout << "Square of all figures = " << square;
    std::cout << "\nPerimeter of all figures = " << perimeter;
    std::cout << "\nCenter of mass = " << center / figures.size();
    std::cout << "\nMemory of all figures = " << memory;
}

void clearFigures() {
    for (auto *figure: figures) {
        delete figure;
    }
    figures.clear();
}

void sort() {
    for (int i = 1; i < figures.size(); i++) {
        for (int j = i; j > 0; j--) {
            auto* x = dynamic_cast<IPhysObject*>(figures[j-1]);
            auto* y = dynamic_cast<IPhysObject*>(figures[j]);
            if (x->mass() > y->mass()) {
                std::swap(figures[j-1], figures[j]);
            }
        }
    }
}

Circle::Circle(double r, double m) : radius(r), circle_mass(m), center({0.0, 0.0}) {}

double Circle::square() const {
    return M_PI * radius * radius;
}

double Circle::perimeter() const {
    return 2 * M_PI * radius;
}

double Circle::mass() const {
    return circle_mass;
}

CVector2D Circle::position() const {
    return center;
}

bool Circle::operator==(const IPhysObject &ob) const {
    return this->mass() == ob.mass();
}

bool Circle::operator<(const IPhysObject &ob) const {
    return this->mass() < ob.mass();
}

void Circle::draw() const {
    std::cout << "Circle with radius: " << radius << ", mass: " << circle_mass << ", position: (" << center.x << ", "
              << center.y << ")" << std::endl;
}

void Circle::initFromDialog() {
    std::cout << "Enter circle radius:\n";
    std::cin >> radius;
    std::cout << "Enter circle mass:\n";
    std::cin >> circle_mass;
    std::cout << "Enter circle center x and y:\n";
    std::cin >> center.x >> center.y;
}

const char *Circle::classname() const {
    return "Circle";
}

unsigned int Circle::size() const {
    return sizeof(*this);
}

IsoscelesTrapezoid::IsoscelesTrapezoid(double lowerBase, double upperBase, double height, double mass)
        : lowerBase(lowerBase), upperBase(upperBase), height(height), massValue(mass), centerPosition({0.0, 0.0}) {}

double IsoscelesTrapezoid::square() const {
    return (lowerBase + upperBase) / 2 * height;
}

double IsoscelesTrapezoid::perimeter() const {
    double side = sqrt(pow((lowerBase - upperBase) / 2, 2) + height * height);
    return lowerBase + upperBase + 2 * side;
}

double IsoscelesTrapezoid::mass() const {
    return massValue;
}

CVector2D IsoscelesTrapezoid::position() const {
    return centerPosition;
}

bool IsoscelesTrapezoid::operator==(const IPhysObject &ob) const {
    return this->mass() == ob.mass();
}

bool IsoscelesTrapezoid::operator<(const IPhysObject &ob) const {
    return this->mass() < ob.mass();
}

void IsoscelesTrapezoid::draw() const {
    std::cout << "Isosceles Trapezoid with lower base: " << lowerBase << ", upper base: " << upperBase
              << ", height: " << height << ", mass: " << massValue
              << ", position: (" << centerPosition.x << ", " << centerPosition.y << ")" << std::endl;
}

void IsoscelesTrapezoid::initFromDialog() {
    std::cout << "Enter lower base:\n";
    std::cin >> lowerBase;
    std::cout << "Enter upper base:\n";
    std::cin >> upperBase;
    std::cout << "Enter height:\n";
    std::cin >> height;
    std::cout << "Enter mass:\n";
    std::cin >> massValue;
    std::cout << "Enter position (x y):\n";
    std::cin >> centerPosition.x >> centerPosition.y;
}

const char *IsoscelesTrapezoid::classname() const {
    return "IsoscelesTrapezoid";
}

unsigned int IsoscelesTrapezoid::size() const {
    return sizeof(*this);
}
