#include "vector.h"
#include <cassert>
#include <cmath>
#include <iostream>
#include <ostream>


namespace Lab3Vector{
    Vector::Vector(){
      int num_elem = 0;
    };

    Vector::Vector(double first){
      num_elem = 1;
      arr = new double[num_elem];
      arr[0] = first;
    };

    Vector::Vector(int n, double * elements){
      num_elem = n;
      arr = new double[num_elem];
      for (int i = 0; i < num_elem; i++)
        arr[i] = elements[i];
    };

    Vector::~Vector(){
      delete [] arr;
    }

    Vector operator + ( Vector &vector, Vector &vector2){
      if ( vector.count() != vector2.count() ){
        std::cout << "[-] Vectors should have the same length";
        return vector;
      } else {
        for (int i = 0; i < vector.count(); i++){
          vector.arr[i] += vector2.arr[i];
        }
        return vector;
      }
    }

    Vector operator - ( Vector &vector, Vector &vector2){
      if ( vector.count() != vector2.count() ){
        std::cout << "[-] Vectors should have the same length";
        return vector;
      } else {
        for (int i = 0; i < vector.count(); i++){
          vector.arr[i] -= vector2.arr[i];
        }
        return vector;
      }
    }

    Vector operator * ( Vector &vector, Vector &vector2){
      if ( vector.count() != vector2.count() ){
        std::cout << "[-] Vectors should have the same length";
        return vector;
      } else {
        for (int i = 0; i < vector.count(); i++){
          vector.arr[i] *= vector2.arr[i];
        }
        return vector;
      }
    }

    void Vector::addElem(double elem){
        double * temp = new double[num_elem+1];
        std::copy(arr, arr + num_elem, temp);
        delete [] arr;
        arr = temp;
        arr[num_elem] = elem;
        num_elem++;
    }

    Vector operator += ( Vector &vector, double elem){
      vector.addElem(elem);
      return vector;
    }

    int Vector::count(){
      return num_elem;
    }

    double Vector::getElem(int n){
      assert(n < num_elem);
      return arr[n];
    }

    void Vector::clearVector(){
  		num_elem = 0;
  	}

    double Vector::getNorm(){
      assert(num_elem != 0 && "Can't get norm of null vector");
      double norm = arr[0];
      for (int i = 0; i < num_elem; i++)
        if (std::abs(arr[i]) > norm)
          norm = std::abs(arr[i]);

      return norm;
    }

    std::ostream& operator<< (std::ostream &out, const Vector &vector){
        out << "[  ";
        for (int i=0; i < vector.num_elem; i++){
          out << vector.arr[i] << "  ";
        }
        out << "]";
        return out;
    }

    std::istream& operator>> (std::istream &in, Vector &vector){
      int num;
      while (1) {
        std::cout << "(input value of element) >> ";
        if (in >> num) {
            // valid number
            in.clear();
            while (in.get() != '\n') ; // empty loop
            break;
        } else {
            // not a valid number
            std::cout << "(error) not a number" << std::endl;
            in.clear();
            while (in.get() != '\n') ; // empty loop
        }
      }
      vector.num_elem = num;
      vector.arr = new double[num];
      double input;
      std::cout << num << std::endl;
      for (int i = 0; i < num; i++){
        while (1) {
          std::cout << "(input value of element " << i+1 << "/" << num << ") >> ";
          if (in >> input) {
              // valid number
              in.clear();
              while (in.get() != '\n') ; // empty loop
              vector.arr[i] = input;
              break;
          } else {
              // not a valid number
              std::cout << "(error) not a number" << std::endl;
              in.clear();
              while (in.get() != '\n') ; // empty loop
          }
        }
      }
      return in;
    }
}
