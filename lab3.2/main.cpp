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

          //delete tmp_vector;
          //tmp_vector = NULL;

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
        break;
      case 6:
        break;
      case 7:
        break;
      case 8:
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

/*
int main(){
  Lab3Vector::Vector * vec = NULL;
  Lab3Vector::Vector * tmp_vec = NULL;
  Lab3Vector::Vector * vec1 = NULL;
  Lab3Vector::Vector * vec2 = NULL;
  std::string line;
  double input;
  int n;

  show_help();
  while (std::getline(std::cin, line)){
    if (!is_number(line)){
      show_help();
      continue;
    }

    switch(std::stoi(line)){
      case 1:
        if (vec)
          delete vec;
        vec = new Lab3Vector::Vector();
        break;
      case 2:
        try{
          std::cout << "(input value of element) >> ";
          if (std::cin >> input) {
              // valid number
              std::cin.clear();
              while (std::cin.get() != '\n') ; // empty loop
          } else {
              // not a valid number
              std::cin.clear();
              while (std::cin.get() != '\n') ; // empty loop
              throw std::invalid_argument("invalid argument");
          }
        } catch (std::invalid_argument &err){
          std::cout << "Exception detected: " << err.what() << std::endl;
          break;
        }

        if (vec)
          delete vec;
        vec = new Lab3Vector::Vector(input);
        break;
      case 3:
        if (vec)
          delete vec;
        vec = new Lab3Vector::Vector();

        try {
          std::cin >> *vec;
        } catch (std::invalid_argument &err){
          std::cout << "Exception detected: " << err.what() << std::endl;
          delete vec;
          vec = NULL;
        }
        break;
      case 4:
        if (!vec){
          std::cout << "Vector is no initialized" << std::endl;
          break;
        }
        vec1 = new Lab3Vector::Vector(*vec);
        std::cout << *vec1 << std::endl;
        vec2 = new Lab3Vector::Vector();
        try {
          std::cin >> *vec2;
        } catch (std::invalid_argument &err){
          std::cout << "Exception detected: " << err.what() << std::endl;
          delete vec2;
          vec2 = NULL;
          break;
        }
        std::cout << *vec2 << std::endl;
        try {
          *vec = *vec1 + *vec2;
          std::cout << *vec << std::endl;
          delete vec1;
          vec1 = NULL;
          break;
        } catch (const char* exception){
          std::cout << "Exception detected: " << exception << std::endl;
          vec = vec1;
        }

        delete vec2;
        vec2 = NULL;
        break;

      case 5:
        if (!vec){
          std::cout << "Vector is no initialized" << std::endl;
          break;
        }
        tmp_vec = new Lab3Vector::Vector();

        std::cin >> *tmp_vec;
        *vec = *vec - *tmp_vec;

        delete tmp_vec;
        break;
      case 6:
        if (!vec){
          std::cout << "Vector is no initialized" << std::endl;
          break;
        }
        tmp_vec = new Lab3Vector::Vector();

        std::cin >> *tmp_vec;
        *vec = *vec * *tmp_vec;

        delete tmp_vec;
        break;
      case 7:
        if (!vec){
          std::cout << "Vector is no initialized" << std::endl;
          break;
        }
        if (vec->length() == 0){
          std::cout << "Can't get norm of null vector" << std::endl;
          break;
        }
        std::cout << "Norm of vector: " << vec->getNorm() << std::endl;
        break;
      case 8:
        if (!vec){
          std::cout << "Vector is no initialized" << std::endl;
          break;
        }
        *vec += get_input("(input value of element) >> ", "(error) not a number");
        break;
      case 9:
        if (!vec){
          std::cout << "Vector is no initialized" << std::endl;
          break;
        }
        std::cout << *vec << std::endl;
        break;
      case 10:
        return 0;
      default:
        break;
    }
    show_help();
  }

  return 0;
}
*/
