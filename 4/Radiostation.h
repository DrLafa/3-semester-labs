#include "Departament.h"
#include <map>
#ifndef OOP4_RADIOSTATION_H
#define OOP4_RADIOSTATION_H

namespace oop4 {
    class Radiostation : public Departament {

    private:
      std::string type = "radio";
      std::map<float, float> freqBand; // пара частота-полоса
    public:
      Radiostation();
      Radiostation(std::string profile, int license, int x, int y);

      virtual std::string getType() const override;
      virtual void changeFreqBand() override;
    };
}

#endif
