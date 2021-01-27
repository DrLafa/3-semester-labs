#include "Table.h"
#include "Departament.h"
#include "Radiostation.h"
#include "Printing.h"
#include "Telecom.h"
#include "dialog.h"
#include "getnum.h"

namespace oop4 {
  void editmenu(Departament * c, int n){
      int total;
      float freq;

      if (c->getType() == "telecom"){
        std::cout << " ->\t input total new frequency: ";
        freq = oop3::getNum<float>();
        c->setFreq(freq);
      }else if (c->getType() == "radio"){
        switch(n){
          case 1:
          c->changeFreqBand();
          break;

          default:
          std::cout << " -> (err) Option not found\n";
        }
      }else if (c->getType() == "printing"){
        switch(n){
          case 1:
          std::cout << " ->\t input total circulation: ";
          total = oop3::getNum<int>();
          c->setCirculation(total);
          break;

          case 2:
          inputPrintingPeriodicy(c);
          break;

          default:
          std::cout << " -> (err) Option not found\n";
        }
      }
  }

  void inputPrintingPeriodicy(Departament * printing){
    std::string days[7] = { "Monday",
                            "Tuesday",
                            "Wednesday",
                            "Thursday",
                            "Friday",
                            "Saturday",
                            "Sunday"};
    std::map <int, std::string> periodicy;
    int n = 8;
    while (true){
      std::cout << "\t1) Add/remove Monday\n";
      std::cout << "\t2) Add/remove Tuesday\n";
      std::cout << "\t3) Add/remove Wednesday\n";
      std::cout << "\t4) Add/remove Thursday\n";
      std::cout << "\t5) Add/remove Friday\n";
      std::cout << "\t6) Add/remove Saturday\n";
      std::cout << "\t7) Add/remove Sunday\n";
      std::cout << "\t0) Save\n";

      std::cout << "Current periodicy: ";
      printing->showPeriodicy(std::cout);
      std::cout << "\n\t>>> ";
      try{
        n = oop3::getNum<int>();
      }catch(const std::invalid_argument &err){
        std::cout << err.what();
        return;
      }
      if (n == 0){
        return;
      }
      if ((n < 1) || (n > 7)){
        std::cout << "(err) Can't read this day\n";
        continue;
      }
      if ( periodicy.find(n-1) == periodicy.end() ) {
        periodicy[n-1] = days[n-1];
      } else {
        periodicy.erase(n-1);
      }
      printing->setPeriodicy(periodicy);
    }
  };

  void show_help(){
    std::cout << std::endl;
    std::cout << "1) New departament" << std::endl;
    std::cout << "2) Show table" << std::endl;
    std::cout << "3) Get departament" << std::endl;
    std::cout << "4) Remove departament" << std::endl;
    std::cout << "5) Edit" << std::endl;
    std::cout << "6) Exit" << std::endl;
    std::cout << " >>  ";
  }

  int dialog(){
    Table table;

    int menu, type;
    Departament * c = NULL;

    std::string profile;
    int license;
    int x,y;
    int total;
    float freq;

    show_help();
    while(true){
      try{
        menu = oop3::getNum<int>();
      }catch(const std::invalid_argument &err){
        menu = 0;
      }catch(const char* msg){
        return 0;
      }

      switch(menu){
        case 1:
          std::cout << "\t input profile name: ";
          std::cin.ignore();
          std::getline(std::cin, profile);
          if (table.NamePresent(profile)){
            std::cout << "(error) This key already used" << std::endl;
            break;
          }

          std::cout << "\t input license number: ";
          try{
            license = oop3::getNum<int>();
          }catch(const std::invalid_argument &err){
            std::cout << "(error) Error reading license" << std::endl;
            break;
          }

          try{
            std::cout << "\t input location (x): ";
            x = oop3::getNum<int>();
            std::cout << "\t input location (y): ";
            y = oop3::getNum<int>();
          }catch(const std::invalid_argument &err){
            std::cout << "(error) Error reading location" << std::endl;
            break;
          }catch(const char* msg){
            return 0;
          }

          std::cout << "\t input departament type:\n ->\t\t\t\t0 - Telecom\n\t\t\t\t1 - Radiostation\n\t\t\t\t2 - Printing\n ->\t>>> ";
          try{
            type = oop3::getNum<int>();
          }catch(const std::invalid_argument &err){
            std::cout << "(error) No such type" << std::endl;
            break;
          }catch(const char* msg){
            return 0;
          }

          switch(type){
            case 0: // telecom
              std::cout << " ->\t input frequency: ";
              freq = oop3::getNum<float>();
              c = new Telecom(profile, license, x, y, freq);
              table.Add(c);
              break;
            case 1: // radio
              c = new Radiostation(profile, license, x, y);
              c->changeFreqBand();
              table.Add(c);
              break;
            case 2: // printing
              try {
                std::cout << " ->\t input total printing: ";
                total = oop3::getNum<int>();
              }catch(const std::invalid_argument &err){
                std::cout << "(error) Error reading printing" << std::endl;
                break;
              }
              c = new Printing(profile, license, x, y, total);
              inputPrintingPeriodicy(c);
              table.Add(c);
              break;
            default:
              std::cout << " (error) No such type" << std::endl;
              break;
          }
          break;
        case 2:
          std::cout << table;
          break;
        case 3:
          std::cout << "\t input profile name: ";
          std::cin.ignore();
          std::getline(std::cin, profile);

          c = table.Find(profile);
          if (c)
            c->show(std::cout);
          else{
            std::cout << "(error) Departament not found" << std::endl;
          }
          break;
        case 4:
          std::cout << "\t input profile name: ";
          std::cin.ignore();
          std::getline(std::cin, profile);

          if (table.Delete(profile)){
            std::cout << " >>> Departament deleted" << std::endl;
          } else {
            std::cout << " (error) Can't delete departament" << std::endl;
          }
          break;
        case 5:
          std::cout << "\tinput profile name: ";
          std::cin.ignore();
          std::getline(std::cin, profile);

          c = table.Find(profile);
          if (c){
            c->showOptions(std::cout);
            std::cout << "\t0) Back <<\n";
            std::cout << "\t>>> ";
            menu = oop3::getNum<float>();
            if (menu == 0){
              break;
            }else{
              editmenu(c, menu);
            }
          }else{
            std::cout << "\t(error) Departament not found" << std::endl;
          }
          break;
        case 6:
          delete c;
          return 0;
      }
      show_help();
    }
    return 0;
  }
}
