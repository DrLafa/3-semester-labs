#include "Departament.h"
#ifndef OOP4_PRINTING_H
#define OOP4_PRINTING_H

namespace oop4 {
    class Printing : public Departament {

    private:
      std::string type = "printing";
      int total;
    public:
      Printing();
      Printing(std::string, int, int, int, int);

      int getEdition();
      void changeEdition(int);
      virtual std::string getType() const override;
      void changeFreqBand(){};
    };
}

#endif
