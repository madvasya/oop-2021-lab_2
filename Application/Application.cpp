#include <iostream>
#include "Evolvent.h"


int main(){
    lab_2::Evolvent e(2, 1, 2);
    lab_2::Point p(3);
    int fl1 = 1;
    double r;
    char* s = nullptr;
    while (fl1) {
        std::cout << "Уравнение эвольвенты: " << std::endl;
        s = e.frm();
        std::cout << s << std::endl;
        delete[] s;

        int fl2 = 1;
        while (fl2) {
            std::cout << "Enter x for calc. value y(x) or press ctrl+z to quit:" << std::endl;
            double x;
            lab_2::Point y;
            std::cin >> x;
            fl2 = std::cin.good();
            if (!fl2)
                continue;
            /*try {
                y = e.f(x);
                std::cout << "y1 = " << y.x << ", y2 = " << y.y << std::endl;
            }
            catch (std::exception& ex) {
                std::cout << ex.what() << std::endl;
            }*/
        }

        std::cin.clear();
        std::cout << "Enter new x, y and r to continue or press ctrl+Z:" << std::endl;
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