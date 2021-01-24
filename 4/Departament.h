#ifndef OOP4_DEPARTAMENT_H
#define OOP4_DEPARTAMENT_H
#include <string>
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

    public:
      friend std::ostream& operator << (std::ostream& out, const Departament&);

      Departament &setProfile(std::string profile);
      Departament &setLicense(int license);
      Departament &setLocation(int x, int y);

      Location getLocation();
      std::string getProfile();
      const int getLicense();
      virtual const std::string getType() = 0;
      virtual void changeFreqBand() = 0;
    };
}

#endif
