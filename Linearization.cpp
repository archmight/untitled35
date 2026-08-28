//
// Created by workstation on 25.08.2026.
//

#include "Linearization.h"

#include <utility>
#include <iostream>

#include "math.h"

Linearization::Linearization(CustomVector d, CustomVector c): D(std::move(d)), C(std::move(c)) {}

std::vector<double> Linearization::Function(double a, double b, double z) {
    std::vector<double> c;
    for (double d: D) {
        c.emplace_back(a + b * pow(d, z));
    }
    return c;
}

double Linearization::getA() const {
    return a;
}

void Linearization::setA(double a) {
    Linearization::a = a;
}

double Linearization::getB() const {
    return b;
}

void Linearization::setB(double b) {
    Linearization::b = b;
}

double Linearization::getZ() const {
    return z;
}

void Linearization::setZ(double z) {
    Linearization::z = z;
}

double Linearization::getMse() const {
    return mse;
}

void Linearization::setMse(double mse) {
    Linearization::mse = mse;
}

void Linearization::calc() {
    CustomVector zCandidates = CustomVector::linSpace(0.1, 3.0, 1000);
    double bestA, bestB, bestZ;

    for (double zEst: zCandidates) {
        CustomVector X = D ^ zEst;
        double xMean = X.mean();
        double cMean = C.mean();
        double bEst = CustomVector::sum((X - xMean) * (C - cMean)) / (CustomVector::sum((X - xMean)^2));
        double aEst = cMean - bEst*xMean;

        if(bEst <= 0){
            continue;
        }

        CustomVector cPred = X * bEst + aEst;
        double mse = ((C - cPred) ^ 2).mean();
        if (mse < this->mse){
            this->mse = mse;
            bestA = aEst;
            bestB = bEst;
            bestZ = zEst;
        }
    }
    a = bestA;
    b = bestB;
    z = bestZ;
}

void Linearization::print() {
    std::cout << std::endl << "a: " << a << " b: " << b << " z: " << z << " mse: " << mse;
}


