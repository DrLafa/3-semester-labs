#include <ostream>

#ifndef vector_H
#define vector_H

namespace oop3{
  class Vector{
  private:
    double * arr;     // статический массив для максимум 20 элементов
    int num_elem;             // количество элементов массива

  public:
    Vector();
    Vector(double first);
    Vector(int n, double * elements);
    ~Vector();
    Vector(const Vector &); // конструктор копирования

    friend std::ostream& operator<< (std::ostream &out, const Vector &vector);
    friend std::istream& operator>> (std::istream &in, Vector &vector);
    vector &operator = (const..)
    friend Vector operator + (const Vector &vector, const Vector &vector2);
    friend Vector operator - ( Vector &vector, Vector &vector2);
    friend Vector operator * ( Vector &vector, Vector &vector2);
    friend Vector operator += ( Vector &vector, double elem);

	  void addElem(double elem);

  	void addVector(Vector &vector);

  	void substractVector(Vector &vector);

  	void multiplyVector(Vector &vector);

    int length();

    double getElem(int n);

  	void clearVector();

    double getNorm();

  };
}
#endif
