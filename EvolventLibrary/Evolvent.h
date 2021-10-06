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
        Point p;//�����. �.�.
        double r;
        inline double degToRad(int deg_angle) const{
            return M_PI * deg_angle / 180;
        }
    public:
        Evolvent(double rad = 1); //������ �����������, 
        //�� ��������� ������������ ���������� ���������� c �. � ������ ��������� � ������������ ��� �� ��������� ��������� ��������
        Evolvent(const Point& p0, double rad = 1); //���������������� ����������� 2
        Evolvent(double x0, double y0, double rad = 1);
        // �������:
        Evolvent& setP(const Point& p0) { p = p0; return *this; }
        Evolvent& setR(double r0);
        // �������:
        Point getP() const { return p; }
        double getR() const { return r; }
        // ������ ������
        double distanceToCenter(double angle) const; //�.3: ���������� �� ������ ���-�� �� ����� �� ����������
        double distanceToCenter(int angle) const; //�.3: ���������� �� ������ ���-�� �� ����� �� ����������
        Point cartesianFromAngle(double) const; // �.4: ���������� ���������� �� ����
        Point cartesianFromAngle(int) const; // �����������, ����� �� ��������� �������
        double ArcLenFromAngle(double angle) const { return r*angle*angle/2; }; // �.5: ����� ���� �� ���� ��������
        double ArcLenFromAngle(int angle) const { return r *degToRad(angle)*degToRad(angle)/2; }; // ����� �����������, ����� ����� ���� ������ � ��������
        double curvatureRadius(double arc_len) const { return sqrt(2 * r * arc_len); }; // �.6
        char* frm() const;
    };
}