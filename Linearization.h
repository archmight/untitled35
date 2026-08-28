//
// Created by workstation on 25.08.2026.
//

#ifndef UNTITLED35_LINEARIZATION_H
#define UNTITLED35_LINEARIZATION_H


#include <vector>
#include "CustomVector.h"

class Linearization {
    CustomVector D;
    CustomVector C;
    double a, b, z;
    double mse = 999999999999999;
public:
    Linearization(CustomVector d, CustomVector c);
    std::vector<double> Function(double a, double b, double z);


    double getA() const;

    void setA(double a);

    double getB() const;

    void setB(double b);

    double getZ() const;

    void setZ(double z);

    double getMse() const;

    void setMse(double mse);

    void calc();

    void print();
};


#endif //UNTITLED35_LINEARIZATION_H
