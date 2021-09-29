#include <iostream>
#include "Evolvent.h"

int main()
{
    double a = 7.4;
    int b = 99;

    std::cout << "a + b = " <<
        Evolvent::Arithmetic::Add(a, b) << std::endl;
    std::cout << "a - b = " <<
        Evolvent::Arithmetic::Subtract(a, b) << std::endl;
    std::cout << "a * b = " <<
        Evolvent::Arithmetic::Multiply(a, b) << std::endl;
    std::cout << "a / b = " <<
        Evolvent::Arithmetic::Divide(a, b) << std::endl;

    return 0;
}