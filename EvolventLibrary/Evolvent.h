#pragma once
#define _USE_MATH_DEFINES
#include <math.h>

namespace lab_2
{
    struct Point {
        double x, y;
        Point(double x0 = 0, double y0 = 0) :x(x0), y(y0){}
    };

    class Evolvent {
    private:
        Point p;//коорд. Ц.О.
        double r;
        inline double degToRad(int deg_angle) const{
            return M_PI * deg_angle / 180;
        }
    public:
        Evolvent(double rad = 1); //пустой конструктор, 
        //по умолчанию определяющий эвольвенту окружности c ц. в начале координат и произвольным или по умолчанию единичным радиусом
        Evolvent(const Point& p0, double rad = 1); //инициализирующий конструктор 2
        Evolvent(double x0, double y0, double rad = 1);
        // сеттеры:
        Evolvent& setP(const Point& p0) { p = p0; return *this; }
        Evolvent& setR(double r0);
        // геттеры:
        Point getP() const { return p; }
        double getR() const { return r; }
        // другие методы
        double distanceToCenter(double angle) const; //п.3: расстояние до центра окр-ти от точки на эвольвенте
        double distanceToCenter(int angle) const; //п.3: расстояние до центра окр-ти от точки на эвольвенте
        Point cartesianFromAngle(double) const; // п.4: Возвращаем координаты от угла
        Point cartesianFromAngle(int) const; // перегружаем, чтобы не радианами едиными
        double ArcLenFromAngle(double angle) const { return r*angle*angle/2; }; // п.5: длина дуги от угла поворота
        double ArcLenFromAngle(int angle) const { return r *degToRad(angle)*degToRad(angle)/2; }; // опять перегружаем, чтобы можно было задать в градусах
        double curvatureRadius(double arc_len) const { return sqrt(2 * r * arc_len); }; // п.6
        char* frm() const;
    };
}