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
    Vector &operator = (const Vector &vector);
    friend Vector operator + (const Vector &vector, const Vector &vector2);
    friend Vector operator - (const Vector &vector, const Vector &vector2);
    friend Vector operator * (const Vector &vector, const Vector &vector2);
    Vector &operator += ( double elem);

    double getNorm();

  };
}
#endif
