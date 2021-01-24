#include <iostream>
#include "Telecom.h"

namespace oop4 {
  Telecom::Telecom() = default;

  Telecom::Telecom(std::string profile, int license, int x, int y, float frequency){
    this->setProfile(profile);
    this->setLicense(license);
    this->setLocation(x, y);
    this->freq = frequency;
  }

  const std::string Telecom::getType(){
    return this->type;
  }
}
