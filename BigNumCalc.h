#ifndef BIGNUMCALC_H
#define BIGNUMCALC_H
#include <string>
#include <iostream>
#include <list>

class BigNumCalc {
    protected:
        int num1;
        int num2;

    public:
        std::list<int> buildBigNum(std::string numString);
        std::list<int> add(std::list<int> num1, std::list<int> num2);
        std::list<int> sub(std::list<int> num1, std::list<int> num2);
        std::list<int> mul(std::list<int> num1, std::list<int> num2);
};



#endif