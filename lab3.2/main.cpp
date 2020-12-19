#include <cassert>
#include <iostream>
#include "vector.h"

#define MAX_SIZE 20

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
  Lab3Vector::Vector * vec = NULL;
  Lab3Vector::Vector * tmp_vec = NULL;
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
        while (1) {
          std::cout << "(input value of element) >> ";
          if (std::cin >> input) {
              // valid number
              std::cin.clear();
              while (std::cin.get() != '\n') ; // empty loop
              break;
          } else {
              // not a valid number
              std::cout << "(error) not a number" << std::endl;
              std::cin.clear();
              while (std::cin.get() != '\n') ; // empty loop
          }
        }
        if (vec)
          delete vec;
        vec = new Lab3Vector::Vector(input);
        break;
      case 3:
        if (vec)
          delete vec;
        vec = new Lab3Vector::Vector();
        std::cin >> *vec;
        break;
      case 4:
        if (!vec){
          std::cout << "Vector is no initialized" << std::endl;
          break;
        }
        tmp_vec = new Lab3Vector::Vector();

        std::cin >> *tmp_vec;
        *vec = *vec + *tmp_vec;

        delete tmp_vec;
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
        if (vec->count() == 0){
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
