#include <iostream>
#include "Radiostation.h"
#include "getnum.h"

namespace oop4 {
  Radiostation::Radiostation() = default;

  Radiostation::Radiostation(std::string profile, int license, int x, int y){
    this->setProfile(profile);
    this->setLicense(license);
    this->setLocation(x, y);
  }

  const std::string Radiostation::getType(){
    return this->type;
  }

  void Radiostation::changeFreqBand() {
    std::cout << "\tinput count of bands: ";
    int count = oop3::getNum<int>();
    float freq, band;

    freqBand.clear();
    for (int i=0; i<count; i++){
      std::cout << "\t " << i+1 << ") frequency: ";
      freq = oop3::getNum<float>();
      std::cout << "\t " << i+1 << ") bandwidth: ";
      band = oop3::getNum<float>();

      freqBand[freq] = band;
    }
  }
}
