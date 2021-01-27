#include <iostream>
#include "Table.h"

namespace oop4 {
    Table::Table() = default;

    bool Table::NamePresent(std::string name){
      if (this->map.count(name) > 0){
        return true;
      }else{
        return false;
      }
    }

    void Table::Add(Departament * dep){
      map.insert(std::make_pair(dep->getProfile(), dep));
    }

    Departament * Table::Find(std::string name){
      if (this->NamePresent(name)){
        return this->map.find(name)->second;
      }else{
        return NULL;
      }
    }

    bool Table::Delete(std::string name){
      Departament * c = NULL;

      if (this->NamePresent(name)){
        c = this->Find(name);
        this->map.erase(name);
        delete c;
        return true;
      } else{
        return false;
      }
    }

    std::ostream& operator<< (std::ostream &out, const Table &table){
        out << "table: {\n";
        for (auto it = table.map.begin(); it != table.map.end(); ++it){
          out << "\t\t";
          out << it->first;
          out << ": {\n\t\t\t\ttype: ";
          out << it->second->getType();
          out << "\n\t\t\t\tlicense: ";
          out << it->second->getLicense();
          out << "\n\t\t\t\tlocation: {\n\t\t\t\t\t\tx: ";
          out << it->second->getLocation().x;
          out << "\n\t\t\t\t\t\ty: ";
          out << it->second->getLocation().y;
          out << "\n\t\t\t\t}\n\t\t}\n";
        }
        out << "}";
        return out;
    }
}
