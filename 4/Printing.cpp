#include <iostream>
#include "Printing.h"

namespace oop4 {
  Printing::Printing() = default;

  Printing::Printing(std::string profile, int license, int x, int y, int total){
    this->setProfile(profile);
    this->setLicense(license);
    this->setLocation(x, y);
    this->setType("printing");
    this->total = total;
  }

  int Printing::getCirculation() const{
    return this->total;
  }

  void Printing::setCirculation(int edition){
    this->total = edition;
  }

  std::ostream &Printing::showPeriodicy(std::ostream &out) const {
    out << "[ ";
    for (auto v : this->periodicy)
      std::cout << v << " " ;
    out << "]\n";
    return out;
  }


  void Printing::setPeriodicy(std::map<int, std::string> &daysMap){
    this->periodicy.clear();
    for (auto it = daysMap.begin(); it != daysMap.end(); ++it){
        this->periodicy.push_back( it->second );
    }
  }

  std::ostream &Printing::show(std::ostream &out) const {
    out << this->getProfile();
    out << ": {\n\ttype: ";
    out << this->getType();
    out << "\n\tlicense: ";
    out << this->getLicense();
    out << "\n\ttotal circulation: ";
    out << this->getCirculation();
    out << "\n\tlocation: {\n\t\tx: ";
    out << this->getLocation().x;
    out << "\n\t\ty: ";
    out << this->getLocation().y;
    out << "\n\t}";
    out << "\n\tperiodicy: ";
    showPeriodicy(out);
    out << "\n\t}";
    return out;
  }

  std::ostream &Printing::showOptions(std::ostream &out) const {
    out << "\t1) Edit total circulation\n";
    out << "\t2) Edit periodicty\n";
    return out;
  }
}
