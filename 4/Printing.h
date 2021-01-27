#include "Departament.h"
#include <map>
#include <vector>
#ifndef OOP4_PRINTING_H
#define OOP4_PRINTING_H

namespace oop4 {
    class Printing : public Departament {

    private:
      int total;
      std::vector<std::string> periodicy;

      void changeFreqBand(){ throw "(err) Not implemented"; };
      void setFreq(float){ throw "(err) Not implemented"; };
    public:
      Printing();
      Printing(std::string, int, int, int, int);

      int getCirculation() const;
      void setCirculation(int);

      std::ostream &showPeriodicy(std::ostream &) const;
      void setPeriodicy(std::map<int, std::string> &);

      std::ostream &show(std::ostream &)const override;
      std::ostream &showOptions(std::ostream &)const override;
    };
}

#endif
