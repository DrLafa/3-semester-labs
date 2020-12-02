#include "vector.h"
#include <cassert>
#include <cmath>
#include <iostream>

#define MAX_SIZE 20

namespace Lab3Vector{
    Vector::Vector(){
      num_elem = MAX_SIZE;
      arr = new double[MAX_SIZE];

      for (int i = 0; i < MAX_SIZE; i++)
        arr[i] = 0;
    };

    Vector::Vector(double first){
      num_elem = 1;
      arr = new double[MAX_SIZE];
      arr[0] = first;
    };

    Vector::Vector(int n, double * elements){
      num_elem = n;
      arr = new double[MAX_SIZE];
      for (int i = 0; i < num_elem; i++)
        arr[i] = elements[i];
    };

    void Vector::addElem(double elem){
        assert(num_elem+1 <= MAX_SIZE && "vector is too long");
    		arr[num_elem] = elem;
    		num_elem += 1;
    };

    void Vector::addVector(Vector &vector){
  		assert(vector.num_elem == num_elem && "Can't sum vectors with different lengths");
  		for (int i = 0; i < num_elem; i++)
  			arr[i] += vector.arr[i];
  	};

    void Vector::substractVector(Vector &vector){
  		assert(vector.num_elem == num_elem && "Can't substract vectors with different lengths");
  		for (int i = 0; i < num_elem; i++)
  			arr[i] -= vector.arr[i];
  	};

    void Vector::multiplyVector(Vector &vector){
  		assert(vector.num_elem == num_elem && "Can't multiply vectors with different lengths");
  		for (int i = 0; i < num_elem; i++)
  			arr[i] *= vector.arr[i];
  	};

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
}
