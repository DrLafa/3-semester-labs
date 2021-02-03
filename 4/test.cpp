#include <gtest/gtest.h>
#include "Departament.h"
#include "Radiostation.h"
#include "Printing.h"
#include "Telecom.h"

using namespace oop4;

TEST(DepartamentConstructor, DefaultConstructor){
    std::string profile = "test";
    int license = 1234;
    int x = 123, y = 123;

    Departament * radio = new Radiostation(profile, license, x, y);
    ASSERT_NO_THROW(radio);

    Departament * telecom = new Telecom(profile, license, x, y, 100.2);
    ASSERT_NO_THROW(telecom);

    Departament * printing = new Printing(profile, license, x, y, 1000);
    ASSERT_NO_THROW(printing);
}

TEST(DepartamentConstructor, SettersCommon){
    std::string profile = "test";
    int license = 1234;
    int x = 123, y = 123;

    Departament * radio = new Radiostation(profile, license, x, y);
    ASSERT_NO_THROW(radio->setProfile(profile));
    ASSERT_NO_THROW(radio->setLicense(license));
    ASSERT_NO_THROW(radio->setLocation(x, y));
    ASSERT_NO_THROW(radio->setType("radio"));

    Departament * telecom = new Telecom(profile, license, x, y, 100.2);
    ASSERT_NO_THROW(telecom->setProfile(profile));
    ASSERT_NO_THROW(telecom->setLicense(license));
    ASSERT_NO_THROW(telecom->setLocation(x, y));
    ASSERT_NO_THROW(telecom->setType("telecom"));

    Departament * printing = new Printing(profile, license, x, y, 1000);
    ASSERT_NO_THROW(printing->setProfile(profile));
    ASSERT_NO_THROW(printing->setLicense(license));
    ASSERT_NO_THROW(printing->setLocation(x, y));
    ASSERT_NO_THROW(printing->setType("printing"));
}

TEST(DepartamentConstructor, GettersCommon){
  std::string profile = "test";
  int license = 1234;
  int x = 123, y = 123;

  Departament * radio = new Radiostation(profile, license, x, y);
  ASSERT_NO_THROW(radio->getLicense());
  ASSERT_NO_THROW(radio->getProfile());
  ASSERT_NO_THROW(radio->getLocation());
  ASSERT_NO_THROW(radio->getType());

  Departament * telecom = new Telecom(profile, license, x, y, 100.2);
  ASSERT_NO_THROW(telecom->getLicense());
  ASSERT_NO_THROW(telecom->getProfile());
  ASSERT_NO_THROW(telecom->getLocation());
  ASSERT_NO_THROW(telecom->getType());

  Departament * printing = new Printing(profile, license, x, y, 1000);
  ASSERT_NO_THROW(printing->getLicense());
  ASSERT_NO_THROW(printing->getProfile());
  ASSERT_NO_THROW(printing->getLocation());
  ASSERT_NO_THROW(printing->getType());
}

TEST(DepartamentConstructor, SettersTelecom){
    std::string profile = "test";
    int license = 1234;
    int x = 123, y = 123;

    Departament * telecom = new Telecom(profile, license, x, y, 100.2);
    ASSERT_NO_THROW(telecom->setFreq(100.3));
}

TEST(DepartamentConstructor, SettersPrinting){
    std::string profile = "test";
    int license = 1234;
    int x = 123, y = 123;

    Departament * printing = new Printing(profile, license, x, y, 1000);

    std::map<int, std::string> periodicy;
    periodicy[0] = "monday";
    ASSERT_NO_THROW(printing->setPeriodicy(periodicy));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
