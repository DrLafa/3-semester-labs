#include <iostream>
#include "Printing.h"

namespace oop4 {
  Printing::Printing() = default;

  Printing::Printing(std::string profile, int license, int x, int y, int total){
    this->setProfile(profile);
    this->setLicense(license);
    this->setLocation(x, y);
    this->total = total;
  }

  int Printing::getEdition(){
    return this->total;
  }
  void Printing::changeEdition(int edition){
    this->total = edition;
  }

  const std::string Printing::getType(){
    return this->type;
  }
}
