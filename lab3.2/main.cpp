#include <cassert>
#include <iostream>
#include "vector.h"
#include "getnum.h"

/*bool is_number(const std::string& s){
    try{
        std::stod(s);
    }catch(...){
        return false;
    }
    return true;
}*/

void show_help(){
  std::cout << std::endl;
  std::cout << "1) Init default" << std::endl;
  std::cout << "2) Init with one element" << std::endl;
  std::cout << "3) Init" << std::endl;
  std::cout << "4) Sum vector" << std::endl;
  std::cout << "5) Substract vector" << std::endl;
  std::cout << "6) Multiply vector" << std::endl;
  std::cout << "7) Get norm" << std::endl;
  std::cout << "8) Add element" << std::endl;
  std::cout << "9) Show vector" << std::endl;
  std::cout << "10) exit" << std::endl;
  std::cout << " >>  ";
}

int main(){
  int menu;
  double input;
  oop3::Vector * vector = new oop3::Vector;
  oop3::Vector * vector_2 = new oop3::Vector;
  oop3::Vector * tmp_vector = new oop3::Vector;
  show_help();
  while(true){
    try{
      menu = oop3::getNum<int>();
    }catch(const std::invalid_argument &err){
      menu = 0;
    }

    switch(menu){
      case 1:
        delete vector;
        vector = new oop3::Vector;
        break;
      case 2:
        std::cout << "(input value of element) >> ";
        try {
          input = oop3::getNum<double>();
          delete vector;
          vector = new oop3::Vector(input);
        }catch(const std::invalid_argument &err){
          std::cout << "(error) Invalid input" << std::endl;
        }
        break;
      case 3:
        try {
          std::cin >> *tmp_vector;

          delete vector;
          vector = new oop3::Vector(*tmp_vector);
        }catch(const std::invalid_argument &err){
          std::cout << "(error) Invalid input: " << err.what() << std::endl;
        }
        break;
      case 4:
        try{
          std::cin >> *vector_2;

          *tmp_vector = *vector + *vector_2;

          delete vector;
          vector = new oop3::Vector(*tmp_vector);
        }catch(const std::invalid_argument &err){
          std::cout << "(error) Invalid input: " << err.what() << std::endl;
        }catch(const std::length_error &err){
          std::cout << "(error) Invalid input: " << err.what() << std::endl;
        }
        break;
      case 5:
        try{
          std::cin >> *vector_2;

          *tmp_vector = *vector - *vector_2;

          delete vector;
          vector = new oop3::Vector(*tmp_vector);
        }catch(const std::invalid_argument &err){
          std::cout << "(error) Invalid input: " << err.what() << std::endl;
        }catch(const std::length_error &err){
          std::cout << "(error) Invalid input: " << err.what() << std::endl;
        }
        break;
      case 6:
        try{
          std::cin >> *vector_2;

          *tmp_vector = *vector * *vector_2;

          delete vector;
          vector = new oop3::Vector(*tmp_vector);
        }catch(const std::invalid_argument &err){
          std::cout << "(error) Invalid input: " << err.what() << std::endl;
        }catch(const std::length_error &err){
          std::cout << "(error) Invalid input: " << err.what() << std::endl;
        }
        break;
      case 7:
        try{
          std::cout << vector->getNorm() << std::endl;
        }catch(const std::length_error &err){
          std::cout << "(error): " << err.what() << std::endl;
        }
        break;
      case 8:
        std::cout << "(input value of element) >> ";
        input = oop3::getNum<double>();

        *vector += input;
        break;
      case 9:
        std::cout << *vector << std::endl;
        break;
      case 10:
        delete vector;
        delete tmp_vector;
        return 0;
      default:
        break;
    }
    show_help();
  }
  return 0;
}
