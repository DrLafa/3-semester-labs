#ifndef OOP4_TABLE_H
#define OOP4_TABLE_H
#include <map>
#include <vector>
#include "Departament.h"
namespace oop4 {
  class Table {
    private:
      std::map<std::string, Departament*> map;
    public:
      Table();
      void Add(Departament *);

      friend std::ostream& operator<< (std::ostream &out, const Table &table);
      //Departament* Find_element(int key);
      //void Display();
      //Table &Add(Departament *);
      //void Show_element(int k);
      //Table &Del(int);
      //void QShow();*/
  };
}

#endif
