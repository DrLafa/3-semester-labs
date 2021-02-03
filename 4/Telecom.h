#include "Departament.h"
#ifndef OOP4_TELECOM_H
#define OOP4_TELECOM_H

namespace oop4 {
    /*!
    \brief Класс департамента телекоммуникаций
    \author godfuzz3r
    \version 1.0
    \date январь 2021 года

    Содержит  функции и реализацию методов, необходимых для департамента телекомуникаций
    */
    class Telecom : public Departament {

    private:
      float freq;

      void changeFreqBand(){ throw "(err) Not implemented"; };
      std::ostream &showPeriodicy(std::ostream &out) const {
        throw "(err) Not implemented";
        return out;
      };
      void setPeriodicy(std::map<int, std::string> &){ throw "(err) Not implemented"; };
      void setCirculation(int){ throw "(err) Not implemented"; };
    public:
      Telecom();
      Telecom(std::string, int, int, int, float);

      void setFreq(float);

      std::ostream & show(std::ostream &) const override ;
      std::ostream &showOptions(std::ostream &)const override;
    };
}

#endif
