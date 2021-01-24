#include "Table.h"
#include "Departament.h"
#include "Radiostation.h"
#include "Printing.h"
#include "Telecom.h"
#include "dialog.h"
#include "getnum.h"

namespace oop4 {
  void show_help(){
    std::cout << std::endl;
    std::cout << "1) New departament" << std::endl;
    std::cout << "2) Show table" << std::endl;
    std::cout << "3) Get departament" << std::endl;
    std::cout << "4) Remove departament" << std::endl;
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
          std::getline(std::cin, profile);

          std::cout << "\t input license number: ";
          try{
            license = oop3::getNum<int>();
          }catch(const std::invalid_argument &err){
            std::cout << "(error) Error reading license" << std::endl;
            break;
          }catch(const char* msg){
            return 0;
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

          std::cout << "\tinput departament type:\t0 - Telecom\n\t\t\t\t1 - Radiostation\n\t\t\t\t2 - Printing\n ->\t>>> ";
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
                std::cout << "\tinput total printing";
                total = oop3::getNum<int>();
              }catch(const std::invalid_argument &err){
                std::cout << "(error) Error reading printing" << std::endl;
                break;
              }
              c = new Printing(profile, license, x, y, total);
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
          break;
        case 4:
          break;
        case 5:
          break;
        case 6:
          break;
        case 7:
          break;
        case 8:
          break;
        case 9:
          break;
        default:
          break;
      }
      show_help();
    }
    return 0;
  }
}
