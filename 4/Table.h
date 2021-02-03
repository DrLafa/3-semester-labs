#ifndef OOP4_TABLE_H
#define OOP4_TABLE_H
#include <map>
#include <vector>
#include "Departament.h"
namespace oop4 {
  /*!
  \brief Класс, реализующий хранение информации о всех департаментах
  \author godfuzz3r
  \version 1.0
  \date январь 2021 года
  */
  class Table {
    private:
      std::map<std::string, Departament*> map;
    public:
      Table();

      bool NamePresent(std::string name);
      void Add(Departament *);
      Departament * Find(std::string name);
      bool Delete(std::string name);

      friend std::ostream& operator<< (std::ostream &out, const Table &table);
      //Departament* Find_element(int key);
      //Table &Add(Departament *);
      //void Show_element(int k);
      //Table &Del(int);
      //void QShow();*/
  };
}

#endif
