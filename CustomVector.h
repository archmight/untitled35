//
// Created by workstation on 26.08.2026.
//

#ifndef UNTITLED35_CUSTOMVECTOR_H
#define UNTITLED35_CUSTOMVECTOR_H


#include <vector>
#include <math.h>
#include <ostream>

class CustomVector {


    std::vector<double> data;
public:
    CustomVector() = default;
    CustomVector(std::vector<double> vector1);
    CustomVector(std::initializer_list<double> list);

    const std::vector<double> &getData() const;

    void setData(const std::vector<double> &data);

    static CustomVector linSpace(double start, double end, int num);
    static double sum(CustomVector customVector);
    static CustomVector ones(int n);

    CustomVector operator^(double value) const ;
    CustomVector operator-(double value) const ;
    CustomVector operator*(CustomVector value) const ;
    CustomVector operator-(CustomVector value) const ;
    CustomVector operator*(double value) const;
    CustomVector operator+(double value) const;

    friend std::ostream& operator<<(std::ostream& os, const CustomVector& p){
        os << std::endl << "========= Vector =========" << std::endl;
        for (auto element: p.getData()) {
            os << element << " ";
        }
        os << std::endl << "==========================" << std::endl;
        return os;
    }

    auto begin() { return data.begin(); }
    auto end() { return data.end(); }

    auto begin() const { return data.cbegin(); }
    auto end() const { return data.cend(); }

    double mean();

    static CustomVector log(const CustomVector& vector);

    static double length(CustomVector vector);
};




#endif //UNTITLED35_CUSTOMVECTOR_H
