#include "BigNumCalc.h"
#include "LinkedList.h"
#include "Node.h"
#include <iostream>
#include <list>
#include <string>

BigNumCalc::BigNumCalc() {}

BigNumCalc::~BigNumCalc() {}

std::list<int> BigNumCalc::buildBigNum(std::string numString) {
    std::list <int> bigNum;

    for (char c : numString) {
        if(c>='0' && c<='9') {
            bigNum.push_back(c-'0');
        }
    }
    while(bigNum.front()==0) {
        bigNum.pop_front();
    }
    return bigNum;
}
   

std::list<int> add(std::list<int> num1, std::list<int> num2) {
    std::list<int> result;
    int carry = 0;
    while(!num1.empty() || !num2.empty() || carry) {
        int sum = carry;

        if(!num1.empty()) {
            sum = sum + num1.back();
            num1.pop_back();
        }
        if(!num2.empty()) {
            sum = sum + num2.back();
            num2.pop_back();
        }
        carry = sum/10;
        sum = sum%10;
        result.push_front(sum);
    }
    return result;
}

std::list<int> sub(std::list<int> num1, std::list<int> num2) {
    std::list<int> result;
    int carry = 0;

        while(!num1.empty() || !num2.empty()){
            int x = carry;  

        if(!num1.empty()) {
            x = x + num1.back();
            num1.pop_back();
        }
        if(!num2.empty()) {
            x = x + num2.back();
            num2.pop_back();
        }
        if(x<0) {
            x = x+10;
            carry = -1;
        } else {
            carry = 0;
        }
        result.push_front(x);
        }

        while(result.front()==0) {
            result.pop_front();
        }

}

std::list<int> mul(std::list<int> num1, std::list<int> num2) {
std::list<int> result;
int carry = 0;
while(!num1.empty() || carry) {
    int mult = carry;

    if(!num1.empty()) {
        mult = mult + num1.back() * num2.back();
        num1.pop_back();
    }
    carry = mult / 10;
    mult = mult%10;

    result.push_front(mult);
}
return result;
}
