#include "vector.h"
#include <cassert>
#include <cmath>
#include <iostream>
#include <ostream>
#include "getnum.h"


namespace oop3{
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
    };

    Vector::Vector(const Vector &vector){
      num_elem = vector.num_elem;
      arr = new double[num_elem];
      for (int i = 0; i < num_elem; i++)
        arr[i] = vector.arr[i];
    };

    Vector &Vector::operator= (const Vector &vector){
      delete arr;
      num_elem = vector.num_elem;
      arr = new double[num_elem];
      for (int i = 0; i < num_elem; i++)
        arr[i] = vector.arr[i];

      return *this;
    }

    Vector operator + ( const Vector &vector, const Vector &vector2){
      if ( vector.num_elem != vector2.num_elem ){
        throw std::length_error("Vectors should have the same length");
      }

      double * elements = new double[vector.num_elem];

      for (int i = 0; i < vector.num_elem; i++){
        elements[i] = vector.arr[i] + vector2.arr[i];
      }

      return Vector(vector.num_elem, elements);
    }

    Vector operator - ( const Vector &vector, const Vector &vector2){
      if ( vector.num_elem != vector2.num_elem ){
        throw std::length_error("Vectors should have the same length");
      }

      double * elements = new double[vector.num_elem];

      for (int i = 0; i < vector.num_elem; i++){
        elements[i] = vector.arr[i] - vector2.arr[i];
      }

      return Vector(vector.num_elem, elements);
    }

    Vector operator * ( const Vector &vector, const Vector &vector2){
      if ( vector.num_elem != vector2.num_elem ){
        throw std::length_error("Vectors should have the same length");
      }

      double * elements = new double[vector.num_elem];

      for (int i = 0; i < vector.num_elem; i++){
        elements[i] = vector.arr[i] * vector2.arr[i];
      }

      return Vector(vector.num_elem, elements);
    }

    Vector &Vector::operator += ( double elem){
      double * temp = new double[num_elem+1];
      std::copy(arr, arr + num_elem, temp);
      delete [] arr;
      arr = temp;
      arr[num_elem] = elem;
      num_elem++;

      return *this;
    }

    double Vector::getNorm(){
      if (num_elem == 0){
        throw std::length_error("Can't get norm of null vector");
      }
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
      std::cout << "(input amount of elements) >> ";
      int num = getNum<int>();
      double input;

      vector.num_elem = num;
      vector.arr = new double[num];

      for (int i = 0; i < num; i++){
        std::cout << "(input value of element " << i+1 << "/" << num << ") >> ";
        vector.arr[i] = getNum<double>();
      }
      return in;
    }
}
