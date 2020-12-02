#include <cassert>
#include <iostream>
#include "vector.h"

#define MAX_SIZE 20

void showVector(Lab3Vector::Vector &vec){
  std::cout << "[  ";
  for (int i = 0; i < vec.count(); i++)
    std::cout << vec.getElem(i) << "  ";
  std::cout << "]" << std::endl;
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
  double arr[MAX_SIZE];

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
        //input = get_input("(input new center) >> ", "(error) not a number");
        //catenary->set_center(input);
        //std::cout << "(+) catenary center was succesfully changed" << std::endl;
        break;
      case 2:
        if (vec)
          delete vec;
        input = get_input("(input value of element) >> ", "(error) not a number");
        vec = new Lab3Vector::Vector(input);
        break;
      case 3:
        if (vec)
          delete vec;
        input = get_input("(enter amount of elements) >> ", "(error) not a number");
        n = (int)input;

        if (n < 0){
          std::cout << "Cannot create a vector with a negative number of elements." << std::endl;
          break;
        }

        for (int i = 0; i < n; i++){
          input = get_input("(input value of element) >> ", "(error) not a number");
          arr[i] = input;
        }
        vec = new Lab3Vector::Vector(n, arr);
        break;
      case 4:
        if (!vec){
          std::cout << "Vector is no initialized" << std::endl;
          break;
        }
        n = vec->count();
        for (int i = 0; i < n; i++){
          std::cout << "input vector value (" << i+1 << "/" << n << ")" << std::endl;
          input = get_input("", "(error) not a number");
          arr[i] = input;
        }
        tmp_vec = new Lab3Vector::Vector(n, arr);
        vec->addVector(*tmp_vec);
        delete tmp_vec;
        break;
      case 5:
        if (!vec){
          std::cout << "Vector is no initialized" << std::endl;
          break;
        }
        n = vec->count();
        for (int i = 0; i < n; i++){
          std::cout << "input vector value (" << i+1 << "/" << n << ")" << std::endl;
          input = get_input("", "(error) not a number");
          arr[i] = input;
        }
        tmp_vec = new Lab3Vector::Vector(n, arr);
        vec->substractVector(*tmp_vec);
        delete tmp_vec;
        break;
      case 6:
        if (!vec){
          std::cout << "Vector is no initialized" << std::endl;
          break;
        }
        n = vec->count();
        for (int i = 0; i < n; i++){
          std::cout << "input vector value (" << i+1 << "/" << n << ")" << std::endl;
          input = get_input("", "(error) not a number");
          arr[i] = input;
        }
        tmp_vec = new Lab3Vector::Vector(n, arr);
        vec->multiplyVector(*tmp_vec);
        delete tmp_vec;
        break;
      case 7:
        if (!vec){
          std::cout << "Vector is no initialized" << std::endl;
          break;
        }
        try{
          if (vec->count() == 0)
            throw 1;
          std::cout << "Norm of vector: " << vec->getNorm() << std::endl;
        }catch(int err){
          std::cout << "Can't get norm of null vector" << std::endl;
        }
        break;
      case 8:
        if (!vec){
          std::cout << "Vector is no initialized" << std::endl;
          break;
        }
        input = get_input("(input value of element) >> ", "(error) not a number");
        vec->addElem(input);
        break;
      case 9:
        if (!vec){
          std::cout << "Vector is no initialized" << std::endl;
          break;
        }
        showVector(*vec);
        break;
      case 10:
        delete vec;
        return 0;
      default:
        break;
    }
    show_help();
  }

  return 0;
}
