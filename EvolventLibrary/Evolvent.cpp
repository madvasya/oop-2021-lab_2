// compile with: cl /c /EHsc Evolvent.cpp
// post-build command: lib Evolvent.
#include <strstream>
#include "Evolvent.h"
#include <stdio.h>
#include <string.h>

namespace lab_2{
    Evolvent::Evolvent(double rad) :p(0, 0) { //пустой конструктор и инициализирующий конструктор
        if (rad < 0)
            throw std::exception("Радиус не может принимать отрицательные значения!");
        r = rad;
    }

    Evolvent::Evolvent(const Point  &p0, double rad) : p(p0) { //ИК 2
        if (rad < 0)
            throw std::exception("Радиус не может принимать отрицательные значения!");
        r = rad;
    }

    Evolvent::Evolvent(double x0, double y0, double rad) : p(x0, y0) { //инициализирующий конструктор
        if (rad < 0)
            throw std::exception("Радиус не может принимать отрицательные значения!");
        r = rad;
    }

    //сеттеры: 
    Evolvent& Evolvent::setR(double r0) {
        if (r0 < 0)
            throw std::exception("Радиус не может принимать отрицательные значения!");
        r = r0;
        return *this; 
    }

    double Evolvent::distanceToCenter(double angle) const {//значение в точке
        Point result = cartesianFromAngle(angle);
        return sqrt(result.x * result.x + result.y * result.y);
    }
    double Evolvent::distanceToCenter(int angle) const {//значение в точке (градусы)
        Point result = cartesianFromAngle(angle);
        return sqrt(result.x * result.x + result.y * result.y);
    }

    Point Evolvent::cartesianFromAngle(double angle) const{
        Point result;
        result.x = r * (cos(angle) + angle * sin(angle)) + p.x;
        result.y = r * (sin(angle) - angle * cos(angle)) + p.y;
        return result;
    }

    Point Evolvent::cartesianFromAngle(int angle) const {
        double angle_rad = degToRad(angle);
        return Evolvent::cartesianFromAngle(angle_rad);
    }
    double Evolvent::curvatureRadius(double arc_len) const{
        if(arc_len < 0 )
            throw std::exception("Длина дуги не может быть отрицательной!");
        return sqrt(2 * r * arc_len);
    }

    char* Evolvent::frm() const {//формула эвольвенты: X = r*(cos(u)+u*sin(u)) + Xo\nY = r*(sin(u)-u*sin(u))+ Yo
        const char* s1 = "X = *(cos(t) + t*sin(t))  + | Y = *(sin(t) - t*cos(t))  + ";
        int l = strlen(s1) + 1;
        char num[20];
        sprintf_s(num, 20, "%.2f", p.x);
        l += strlen(num);
        sprintf_s(num, 20, "%.2f", p.y);
        l += strlen(num);
        sprintf_s(num, 20, "%.2f", r);
        l += 2 * strlen(num);
        char* s = new char[l];// выделяем память под наши буквицы

        sprintf_s(s, l, "X = ");
        int k = strlen(s);
        if (r != 0){
            sprintf_s(s + k, l - k, "%.2f*(cos(t) + t*sin(t))", r);
            k = strlen(s);
        }
        if (p.x != 0 && r != 0)
            sprintf_s(s + k, l - k, " + %.2f", p.x);
        else if(r == 0)
            sprintf_s(s + k, l - k, "%.2f", p.x);
        k = strlen(s);

        sprintf_s(s + k, l - k, " | Y = ");
        k = strlen(s);
        if (r != 0) {
            sprintf_s(s + k, l - k, "%.2f*(sin(t) - t*cos(t))", r);
            k = strlen(s);
        }
        if (p.y != 0 && r != 0)
            sprintf_s(s + k, l - k, " + %.2f", p.y);
        else if (r == 0)
            sprintf_s(s + k, l - k, "%.2f", p.y);
        return s;
    }
}