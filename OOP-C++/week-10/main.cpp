#include <iostream>
#include "MyString.h"
#include <exception>
class Interface {
public:
    virtual ~Interface() = default;
    virtual void print() const = 0;
    virtual double calcExp() = 0;

};

class Number : public Interface {
private:
    double num;
public:
    Number(double num) : num(num) { }

    void print() const override {
        std::cout << num << std::endl;
    }

    double calcExp() override {
        return num;
    }
};

class Expression : public Interface {
private:
    Interface* num1;
    Interface* num2;
    char oper;
public:
    Expression(Interface* num1, const char oper, Interface* num2) : num1(num1), num2(num2), oper(oper) { }

    void print() const final {
        num1->print();
        std::cout << oper;
        num2->print();
    }

    double calcExp() final {
        if (oper == '+') {
            return num1->calcExp() + num2->calcExp();
        }
        else if (oper == '-'){
            return num1->calcExp() - num2->calcExp();
        }
        else if (oper == '*'){
            return num1->calcExp() * num2->calcExp();
        }
        else if (oper == '/'){
            return num1->calcExp() / num2->calcExp();
        }
        else {
            throw std::invalid_argument("Invalid operation");
        }
    }
};

int main() {
//    MyString str1("Hello");
//    str1.append(" World");
//    str1[0] = 'p';
//    std::cout << str1.length() << std::endl;
//    std::cout << str1 << std::endl;

    Interface* num1 = new Number(2.4);
    Interface* num2 = new Number(3);

    Interface* exp = new Expression(num1, '+', num2);

    exp->print();
    std::cout << exp->calcExp() << std::endl;

    Interface* nextExp = new Expression(num1, '+', exp);
    std::cout << exp->calcExp() << std::endl;

    delete num1;
    delete num2;
    delete exp;
    delete nextExp;
    return 0;
}
