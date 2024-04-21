#ifndef REALISATION_H
#define REALISATION_H

#include <iostream>
#include <cmath>
#include <vector>

void addFigure();

void displayFigures();

void clearFigures();

void sort();

class CVector2D {
public:
    double x, y;
};

class IGeoFig {
public:
    virtual double square() const = 0;

    virtual double perimeter() const = 0;
};

class IPhysObject {
public:
    virtual double mass() const = 0;

    virtual CVector2D position() const = 0;

    virtual bool operator==(const IPhysObject &ob) const = 0;

    virtual bool operator<(const IPhysObject &ob) const = 0;
};

class IPrintable {
public:
    virtual void draw() const = 0;
};

class IDialogInitiable {
public:
    virtual void initFromDialog() = 0;
};

class BaseCObject {
public:
    virtual const char *classname() const = 0;

    virtual unsigned int size() const = 0;
};

class Circle : public BaseCObject, public IDialogInitiable, public IPrintable, public IPhysObject, public IGeoFig {
private:
    double radius;
    double circle_mass;
    CVector2D center;

public:
    Circle(double r = 0.0, double m = 0.0);

    [[nodiscard]] double square() const override;

    [[nodiscard]] double perimeter() const override;

    [[nodiscard]] double mass() const override;

    [[nodiscard]] CVector2D position() const override;

    bool operator==(const IPhysObject &ob) const override;

    bool operator<(const IPhysObject &ob) const override;

    void draw() const override;

    void initFromDialog() override;

    [[nodiscard]] const char *classname() const override;

    [[nodiscard]] unsigned int size() const override;
};

class IsoscelesTrapezoid
        : public BaseCObject, public IDialogInitiable, public IPrintable, public IPhysObject, public IGeoFig {
private:
    double lowerBase;
    double upperBase;
    double height;
    double massValue;
    CVector2D centerPosition;

public:
    explicit IsoscelesTrapezoid(double lowerBase = 0.0, double upperBase = 0.0, double height = 0.0, double mass = 0.0);

    [[nodiscard]] double square() const override;

    [[nodiscard]] double perimeter() const override;

    [[nodiscard]] double mass() const override;

    [[nodiscard]] CVector2D position() const override;

    bool operator==(const IPhysObject &ob) const override;

    bool operator<(const IPhysObject &ob) const override;

    void draw() const override;

    void initFromDialog() override;

    [[nodiscard]] const char *classname() const override;

    [[nodiscard]] unsigned int size() const override;
};

#endif // REALISATION_H
