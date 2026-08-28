//
// Created by workstation on 26.08.2026.
//

#include <numeric>
#include <iostream>
#include "CustomVector.h"




CustomVector::CustomVector(std::initializer_list<double> list) {
    data = list;
}


CustomVector CustomVector::linSpace(double start, double end, int num) {
    double step = (end - start)/num;
    std::vector<double> lin;
    for (int i = 0; i < num; ++i) {
        lin.push_back(start + i*step);
    }
    CustomVector result = CustomVector{};
    result.setData(lin);
    return result;
}

CustomVector CustomVector::operator^(double value) const {
    std::vector<double> result;
    for (auto d: data) {
        result.emplace_back(std::pow(d, value));
    }
    return {result};
}

CustomVector::CustomVector(std::vector<double> vector1) {
    data = vector1;
}

const std::vector<double> &CustomVector::getData() const {
    return data;
}

void CustomVector::setData(const std::vector<double> &data) {
    this->data = data;
}

double CustomVector::mean() {
    return std::accumulate(data.begin(), data.end(), 0.0) / data.size();
}

CustomVector CustomVector::operator-(double value) const {
    std::vector<double> result;
    for(double d: data) {
        result.emplace_back(d - value);
    }
    return {result};
}

CustomVector CustomVector::operator*(CustomVector value) const {
    if(this->getData().size() != value.getData().size()) {
        std::cerr << "NOT EQUAL SIZE";
        return {};
    }

    std::vector<double> result;
    for (int i = 0; i < value.getData().size(); ++i) {
        result.push_back(data[i] * value.getData()[i]);
    }

    return {result};
}

double CustomVector::sum(CustomVector customVector) {
    return std::accumulate(customVector.getData().begin(), customVector.getData().end(), 0.0);
}

CustomVector CustomVector::operator*(double value) const {
    std::vector<double> result;
    for (double d: data) {
        result.emplace_back(d * value);
    }
    return {result};
}

CustomVector CustomVector::operator+(double value) const {
    std::vector<double> result;
    for (double d: data) {
        result.emplace_back(d + value);
    }
    return {result};
}

CustomVector CustomVector::operator-(CustomVector value) const {
    if(this->getData().size() != value.getData().size()) {
        std::cerr << "NOT EQUAL SIZE";
        return {};
    }

    std::vector<double> result;
    for (int i = 0; i < value.getData().size(); ++i) {
        result.push_back(data[i] - value.getData()[i]);
    }

    return {result};
}

CustomVector CustomVector::ones(int n) {
    std::vector<double> result;
    for (int i = 0; i < n; ++i) {
        result.emplace_back(1);
    }
    return {result};
}

CustomVector CustomVector::log(const CustomVector& vector) {
    std::vector<double> result;
    for (double value : vector) {
        result.emplace_back(std::log(value));
    }
    return {result};
}

double CustomVector::length(CustomVector vector) {
    double result = 0;
    for (double value : vector) {
        result += value*value;
    }
    return result;
}







