#include "Departament.h"
#ifndef OOP4_TELECOM_H
#define OOP4_TELECOM_H

namespace oop4 {
    class Telecom : public Departament {

    private:
      std::string type = "telecom";
      float freq;
    public:
      Telecom();
      Telecom(std::string, int, int, int, float);

      virtual std::string getType() const override;
      void changeFreqBand(){};
    };
}

#endif
