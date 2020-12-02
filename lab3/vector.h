#ifndef vector_H
#define vector_H
#define MAX_SIZE 20

namespace Lab3Vector{
  class Vector{
  private:
    double * arr;     // статический массив для максимум 20 элементов
    int num_elem = MAX_SIZE;                    // количество элементов массива

  public:
    Vector();
    Vector(double first);
    Vector(int n, double * elements);

	  void addElem(double elem);

  	void addVector(Vector &vector);

  	void substractVector(Vector &vector);

  	void multiplyVector(Vector &vector);

    int count();

    double getElem(int n);

  	void clearVector();

    double getNorm();

  };
}
#endif
