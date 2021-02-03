#include "Departament.h"
#include <map>
#ifndef OOP4_RADIOSTATION_H
#define OOP4_RADIOSTATION_H

namespace oop4 {
    /*!
    \brief Класс департамента радиостанций
    \author godfuzz3r
    \version 1.0
    \date январь 2021 года

    Содержит  функции и реализацию методов, необходимых для департамента радиостанций
    */
    class Radiostation : public Departament {

    private:
      std::map<float, float> freqBand; // пара частота-полоса

      std::ostream &showPeriodicy(std::ostream &out) const {
        throw "This method not implemented here";
        return out;
      };
      void setPeriodicy(std::map<int, std::string> &){ throw "(err) Not implemented"; };
      void setCirculation(int){ throw "(err) Not implemented"; };
      void setFreq(float){ throw "(err) Not implemented"; };
    public:
      Radiostation();
      Radiostation(std::string profile, int license, int x, int y);

      void changeFreqBand() override;
      std::ostream & show(std::ostream &) const override ;
      std::ostream &showOptions(std::ostream &)const override;
    };
}

#endif
