#include <iostream>
#include "Table.h"

namespace oop4 {
    Table::Table() = default;

    void Table::Add(Departament * dep){
      map.insert(std::make_pair(dep->getProfile(), dep));
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
