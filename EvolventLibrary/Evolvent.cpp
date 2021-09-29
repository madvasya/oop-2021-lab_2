// MathLibrary.cpp
// compile with: cl /c /EHsc Evolvent.cpp
// post-build command: lib Evolvent.obj

#include "Evolvent.h"

namespace Evolvent
{
    double Arithmetic::Add(double a, double b)
    {
        return a + b;
    }

    double Arithmetic::Subtract(double a, double b)
    {
        return a - b;
    }

    double Arithmetic::Multiply(double a, double b)
    {
        return a * b;
    }

    double Arithmetic::Divide(double a, double b)
    {
        return a / b;
    }
}