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


#include <iostream>
#include <string>
#include <cmath>
#include <cassert>
#include "catenary.h"

void show_help(){
  std::cout << std::endl;
  std::cout << "1) set center" << std::endl;
  std::cout << "2) set tension" << std::endl;
  std::cout << "3) get ordinate" << std::endl;
  std::cout << "4) get length" << std::endl;
  std::cout << "5) get radius" << std::endl;
  std::cout << "6) get square" << std::endl;
  std::cout << "7) get center of curvature" << std::endl;
  std::cout << "8) get properties" << std::endl;
  std::cout << "9) exit" << std::endl;
  std::cout << " >>  ";
}

bool is_number(const std::string& s){
    try{
        std::stod(s);
    }catch(...){
        return false;
    }
    return true;
}

double get_input(const std::string& message, const std::string& error){
  std::string line;
  double input;
  std::cout << message;
  while (std::getline(std::cin, line)){
    if (!is_number(line)){
      std::cout << error << std::endl;
      std::cout << message;
    } else {
      input = std::stod(line);
      break;
    }
  }
  return input;
}

int main(){
  Lab2Catenary::Catenary * catenary = new Lab2Catenary::Catenary();
  //Catenary catenary;
  std::string line;
  double input;
  double x1, x2;

  show_help();
  while (std::getline(std::cin, line)){
    if (!is_number(line)){
      show_help();
      continue;
    }

    switch(std::stoi(line)){
      case 1:
        input = get_input("(input new center) >> ", "(error) not a number");
        catenary->set_center(input);
        std::cout << "(+) catenary center was succesfully changed" << std::endl;
        break;
      case 2:
        input = get_input("(input new tension) >> ", "(error) not a number");
        if (input > 0){
          catenary->set_tension(input);
          std::cout << "(+) catenary tension was succesfully changed" << std::endl;
        }else{
          std::cout << "(-) tension must be greater than 0" << std::endl;
        }
        break;
      case 3:
        input = get_input("(enter abscissa) >> ", "(error) not a number");
        std::cout << "ordinate: " << catenary->get_ordinate(input) << std::endl;
        break;
      case 4:
        x1 = get_input("(enter X1) >> ", "(error) not a number");
        x2 = get_input("(enter X2) >> ", "(error) not a number");
        std::cout << "ordinate: " << catenary->get_length(x1, x2) << std::endl;
        break;
      case 5:
        input = get_input("(enter X) >> ", "(error) not a number");
        std::cout << "radius: " << catenary->get_radius(input) << std::endl;
        break;
      case 6:
        x1 = get_input("(enter X1) >> ", "(error) not a number");
        x2 = get_input("(enter X2) >> ", "(error) not a number");
        std::cout << "square: " << catenary->get_square(x1, x2) << std::endl;
        break;
      case 7:
        input = get_input("(enter X) >> ", "(error) not a number");
        catenary->get_center_of_curvature(input);
        break;
      case 8:
        catenary->get_proterties();
        break;
      case 9:
        delete catenary;
        return 0;
      default:
        break;
    }
    show_help();
  }

  delete catenary;
  return 0;
}
