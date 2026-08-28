#include <iostream>
#include <vector>
#include "Linearization.h"
#include "CustomVector.h"
#include "GaussNewton.h"
#include <fstream>
#include <sstream>

std::pair<std::vector<double>, std::vector<double>> readVectors(std::string string);

int main() {
    std::pair<std::vector<double>, std::vector<double>> values = readVectors("C:\\Users\\workstation\\CLionProjects\\untitled35\\DC.txt");

    CustomVector D { values.first };
    CustomVector C { values.second };

    Linearization l(D, C);
    l.calc();
    l.print();

    return 0;
}

std::pair<std::vector<double>, std::vector<double>> readVectors(std::string string) {
    std::vector<double> D, C;
    std::ifstream file(string);

    if (file.is_open()) {
        std::string line;
        getline(file, line);
        std::stringstream ss1(line);
        double val;
        while (ss1 >> val) {
            D.push_back(val);
        }

        getline(file, line);
        std::stringstream ss2(line);
        while (ss2 >> val) {
            C.push_back(val);
        }

        file.close();
    }

    return {D, C};
}
