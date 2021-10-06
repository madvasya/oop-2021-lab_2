#include <iostream>
#include "Evolvent.h"
#include <locale.h>

int main(){
    setlocale(LC_ALL, "");
    lab_2::Evolvent e(1, 10, 2);
    lab_2::Point p(3);
    int fl1 = 1;
    double r;
    char* s = nullptr;
    std::cout << "ЗДРАВСТВУЙТЕ!!!" << std::endl;
    while (fl1) {
        std::cout << "Уравнение эвольвенты: " << std::endl;
        s = e.frm();
        std::cout << s << std::endl;
        delete[] s;

        int fl2 = 1;
        while (fl2) {
            std::cout << "Введите угол поворота в радианах и длину дуги:" << std::endl;
            double angle;
            double arc_len;
            std::cin >> angle;
            std::cin >> arc_len;
            fl2 = std::cin.good();
            if (!fl2)
                continue;
            try {
                double curvature_radius = e.curvatureRadius(arc_len);
                std::cout << "радиус кривизны при данной длине дуги = " << curvature_radius << std::endl;
            }
            catch (std::exception& ex) {
                std::cout << ex.what() << std::endl;
            }
            lab_2::Point p = e.cartesianFromAngle(angle);
            std::cout << "Декартовы координаты точки лежащей на эвольвенте при данном угле поворота: x = " << p.x << " y = " << p.y << std::endl;
            std::cout << "Длина дуги при заданном угле поворота = " << e.ArcLenFromAngle(angle) << std::endl;
            std::cout << "Расстояние до центра при данном угле поворота =  " << e.distanceToCenter(angle) << std::endl;
        }

        std::cin.clear();
        std::cout << "Введите новые координаты ц.о. и радиус окружности или ctrl+Z:" << std::endl;
        std::cin >> p.x >> p.y >> r;
        if (std::cin.good()) {
            e.setP(p);
            try {
                e.setR(r);
            }
            catch (std::exception& ex) {
                std::cout << ex.what() << std::endl;
            }
        }
        else
            fl1 = 0;
    }

    return 0;
}