// Разработать класс, определяющий цепную линию
// Цепная линия - линия, по которой провешивается однородная нерастяжимая нить,
// закрепленная в двух её концах
//
//  1) Определить состояние класса
//  2) Разработать конструкторы и методы получения и изменения параметров
//  3) Вернуть ординату цепной линии по значению абсциссы
//     Начало координат находится ниже вершины цепной линии
//     на длину такого отрезка, вес которого равен горизонтальной составляющей натяжений нити (равен коеффициенту a)
//  4) Вернуть длину дуги цепной линии от её проекци на оси абсцисс
//  5) Вернуть радиус кривизны цепной линии относительно координаты по оси абсцисс
//  6) Вернуть координаты центра кривизны цепной линии в декартовой системе координат относительно координаты по оси абсцисс
//  7) Вернуть площадь криволинейной трапеции образованной цепной линией и её проекцией на ось абсцисс
//
//  Разработать диалоговую программу для тестирования класса
#ifndef catenary_H
#define catenary_H
#include <cmath>

namespace Lab2Catenary{
  class Catenary{
      private:
        double center;
        double a;       // коеффициент натяжения

      public:
        Catenary(double _center=0, double _a = 1){
            set_center(_center);
            set_tension(_a);
        }

        void set_center(double _center){
          center = _center;
        }

        void set_tension(double tension){
          a = tension;
          assert(a > 0);
        }

        double get_center(){
          return center;
        }

        double get_tension(){
          return a;
        }

        void get_proterties(){
          std::cout << "Catenary properties:" << std::endl;
          std::cout << "\tcenter:  " << get_center() << std::endl;
          std::cout << "\ttension: " << get_tension() << std::endl;
          std::cout << "\tY apex:  " << get_tension() << std::endl;
        }

        double get_ordinate(double x){
            return a * std::cosh((x-center)/a);
        }

        double get_length(double x1, double x2){
            // http://cyclowiki.org/wiki/%D0%94%D0%BB%D0%B8%D0%BD%D0%B0_%D0%B4%D1%83%D0%B3%D0%B8_%D1%86%D0%B5%D0%BF%D0%BD%D0%BE%D0%B9_%D0%BB%D0%B8%D0%BD%D0%B8%D0%B8#:~:text=M%20%3D%20(x%2C%20y),%D1%86%D0%B5%D0%BF%20%E2%80%94%20%D0%B4%D0%BB%D0%B8%D0%BD%D0%B0%20%D0%B4%D1%83%D0%B3%D0%B8%20%D1%86%D0%B5%D0%BF%D0%BD%D0%BE%D0%B9%20%D0%BB%D0%B8%D0%BD%D0%B8%D0%B8.
            // R = a по определению
            return std::abs( a * (std::sinh((x2-center)/a) - std::sinh((x1-center)/a)) );
        }

        double get_radius(double x){
            return a * std::pow(std::cosh((x-center)/a), 2);
        }

        void get_center_of_curvature(double x){
          // Xc = x - y' * (1 + (y')^2) / y''
          // Yc = y + ( 1 + (y')^2 ) / y''
          double X = x - a * std::sinh((x-center)/a) * (1 + std::pow(std::sinh((x-center)/a), 2))/std::cosh((x-center)/a);
          double Y = get_ordinate(x) + a * (1 + std::pow(std::sinh((x-center)/a), 2))/std::cosh((x-center)/a);

          std::cout << "Center of curvature: (" << X << ", " << Y << ")" << std::endl;
        }

        double get_square(double x1, double x2){
          return a*a * (std::sinh((x2-center)/a)-std::sinh((x1-center)/a));
        }
  };
}
#endif
