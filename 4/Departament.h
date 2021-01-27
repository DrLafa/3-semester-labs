#ifndef OOP4_DEPARTAMENT_H
#define OOP4_DEPARTAMENT_H
#include <string>
#include <map>
namespace oop4 {
    struct Location {
      int x;
      int y;
    };

    class Departament {
    private:
      std::string profile;
      int license;
      Location location;
      std::string type;

    public:
      friend std::ostream& operator << (std::ostream& out, const Departament&);

      Departament &setProfile(std::string profile);
      Departament &setLicense(int license);
      Departament &setLocation(int x, int y);
      Departament &setType(std::string type);

      Location getLocation() const;
      std::string getProfile() const ;
      int getLicense() const;
      std::string getType() const;

      // методы для Telecom
      virtual void setFreq(float) = 0;

      // методы для Radiostation
      virtual void changeFreqBand() = 0;

      // Методы для Printing
      virtual void setCirculation(int) = 0;
      virtual std::ostream &showPeriodicy(std::ostream &) const = 0;
      virtual void setPeriodicy(std::map<int, std::string> &) = 0;

      virtual std::ostream& show(std::ostream&)const = 0;
      virtual std::ostream &showOptions(std::ostream &)const = 0;
    };
}

#endif
