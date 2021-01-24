#include "Departament.h"
#include <iostream>

namespace oop4 {
  std::ostream& operator << (std::ostream& out, const Departament& dep){
      out << "profile -> " << dep.profile << std::endl;
      out << "type -> " << dep.getType() << std::endl;
      out << "license -> " << dep.license << std::endl;
      out << "location -> (" << dep.location.x << ", " << dep.location.y << ")" << std::endl;
      //dep.show(out);
      return out;
  }

  Departament &Departament::setProfile(std::string profile)  {
    this->profile = profile;
    return *this;
  }

  Departament &Departament::setLicense(int license)  {
    this->license = license;
    return *this;
  }

  Departament &Departament::setLocation(int x, int y)  {
    this->location.x = x;
    this->location.y = y;
    return *this;
  }

  Location Departament::getLocation() {
    return this->location;
  }

  std::string Departament::getProfile() {
    return this->profile;
  }
  const int Departament::getLicense() {
    return this->license;
  }
}
