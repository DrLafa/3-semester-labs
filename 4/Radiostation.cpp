#include <iostream>
#include "Radiostation.h"
#include "getnum.h"

namespace oop4 {
  Radiostation::Radiostation() = default;

  Radiostation::Radiostation(std::string profile, int license, int x, int y){
    this->setProfile(profile);
    this->setLicense(license);
    this->setLocation(x, y);
    this->setType("radio");
  }

  void Radiostation::changeFreqBand() {
    std::cout << "\tinput count of bands: ";
    int count = oop3::getNum<int>();
    float freq, band;

    this->freqBand.clear();
    for (int i=0; i<count; i++){
      std::cout << "\t " << i+1 << ") frequency: ";
      freq = oop3::getNum<float>();
      std::cout << "\t " << i+1 << ") bandwidth: ";
      band = oop3::getNum<float>();

      this->freqBand[freq] = band;
    }
  }

  std::ostream &Radiostation::show(std::ostream &out) const {
    out << this->getProfile();
    out << ": {\n\ttype: ";
    out << this->getType();
    out << "\n\tlicense: ";
    out << this->getLicense();
    out << "\n\tlocation: {\n\t\tx: ";
    out << this->getLocation().x;
    out << "\n\t\ty: ";
    out << this->getLocation().y;
    out << "\n\t\tfrequencies: {\n";
    for (auto it = this->freqBand.begin(); it != this->freqBand.end(); ++it){
      out << "\t\t\t{ freq: ";
      out << it->first;
      out << "\n\t\t\t  bandwidth: ";
      out << it->second;
      out << " }\n";
    }
    out << "\t\t}\n\t}";
    return out;
  }

  std::ostream &Radiostation::showOptions(std::ostream &out) const {
    out << "\t1) Edit frequency and band list\n";
    return out;
  }
}
