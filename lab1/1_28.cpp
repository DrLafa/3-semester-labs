//  Из входного потока вводится прямоугольная сильно разреженная матрица целых чисел [aij], i = 1, …, m, j = 1, …, n.  Значения m и n заранее
//  не известны и вводятся из входного потока.
//  Сформировать вектор {bi}, i = 1, …, m, i-ый элемент которого равен сумме тех элементов i-ой строки исходной матрицы,
//  которые удовлетворяют некоторому критерию отбора (например, в записи которых не встречается цифра нуль).
//  Проверить работу программы для нескольких критериев отбора.
//  Исходную матрицу и полученный вектор вывести в выходной поток с необходимыми комментариями.

#include <iostream>
using namespace std;

struct notNull{
  int num, i, j;
};

struct matrix{
  int rows, columns;
  notNull *elements;
  int n;
};

int getInt(){
  int n;
  while (!(std::cin >> n)){
      std::cin.clear();
      std::cin.ignore();

      std::cout << "Bad input. Try again: ";
  }
  return n;
}

bool condition(int a){
  return (a > 0) ? true : false;
}

int * solve(matrix * a){
  int * result = new int[a->columns];
  notNull * vector = a->elements;
  int last = 0, s = 0;

  for (int i = 0; i < a->n;){
    if(vector[i].i == last){
      if(condition(vector[i].num))
        s += vector[i].num;
      i++;
    }else{
      result[last] = s;
      s=0;
      last++;
    }
  }
  result[last] = s;
  return result;
}

void printMatrix(matrix * a){
  for (int i = 0; i < a->rows; i++){
    for (int j = 0; j < a->columns; j++){
      for (int n = 0; n < a->n; n++){
        if ( (a->elements[n].i == i ) && (a->elements[n].j == j ) ){
          cout << a->elements[n].num << " ";
          break;
        }
        if (n == a->n-1) {
          cout << "0 ";
        }
      }
    }
    cout << endl;
  }
}

int main(){
  matrix * a = new matrix;
  notNull * elements;
  int m, n; // количество строк и столбцов матрицы
  int amount;

  std::cout<<"Enter number of rows [m]: ";
  m = getInt();

  std::cout << "Enter number of columns [n]: ";
  n = getInt();

  std::cout<< "Enter number of not null items: ";
  amount = getInt();
  if (amount > m*n){
    std::cout << "Bad input." << std::endl;
    exit(1);
  }

  a->rows = m;
  a->columns = n;
  a->elements = new notNull[amount];

  if (a->elements == 0){
    std::cout << "no values provided" << std::endl;
    return 0;
  }
  std::cout << "--- now input values ---" << std::endl;
  int input;
  for (a->n = 0; a->n < amount; a->n++){
    std::cout<< a->n + 1 << ")\titem: " << std::endl;
    std::cout<< "\tEnter value: ";

    //std::cin >> a->elements[a->n].num;
    a->elements[a->n].num = getInt();

    std::cout<< "\tEnter row:";
    //std::cin >> a->elements[a->n].i;
    a->elements[a->n].i = getInt();
    if (a->elements[a->n].i > a->rows-1){
      cout << "Bad input" << endl;
      return 1;
    }
    std::cout<< "\tEnter column:";
    //std::cin >> a->elements[a->n].j;
    a->elements[a->n].j = getInt();
    if (a->elements[a->n].j > a->columns-1){
      cout << "Bad input" << endl;
      return 1;
    }
  }
  cout << "\n" << endl;
  printMatrix(a);

  int *vector = solve(a);
  std::cout << "Result: ";
  for (int i = 0; i < a->rows; i++)
    std::cout<<vector[i]<<" ";
  std::cout<<std::endl;
  delete a->elements;
  delete a;
  delete vector;
  return 0;
}
