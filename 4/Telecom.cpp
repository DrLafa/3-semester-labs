#include <iostream>
#include "Telecom.h"

namespace oop4 {
  Telecom::Telecom() = default;

  Telecom::Telecom(std::string profile, int license, int x, int y, float frequency){
    this->setProfile(profile);
    this->setLicense(license);
    this->setLocation(x, y);
    this->setType("telecom");
    this->freq = frequency;
  }

  void Telecom::setFreq(float frequency){
    this->freq = frequency;
  }

  std::ostream &Telecom::show(std::ostream &out) const {
    out << this->getProfile();
    out << ": {\n\ttype: ";
    out << this->getType();
    out << "\n\tlicense: ";
    out << this->getLicense();
    out << "\n\tlocation: {\n\t\tx: ";
    out << this->getLocation().x;
    out << "\n\t\ty: ";
    out << this->getLocation().y;
    out << "\n\t\tfreqneucy: ";
    out << this->freq;
    out << "\n\t}";
    return out;
  }

  std::ostream &Telecom::showOptions(std::ostream &out) const {
    out << "\t1) Edit frequencty\n";
    return out;
  }
}
