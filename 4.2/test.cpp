#include "container.h"
#include <iostream>

int main(){
  oop4::map<int, int> test;

  // добавляем
  test.insert(std::pair<int, int>(1,1));
  std::cout << test[1] << "\n";

  // ищем
  auto it = test.find(1);
  std::cout << it->second << "\n";

  // удаляем
  test.erase(it);
  try{
    std::cout << test[1] << "\n";
  }catch(const char * str){
    std::cout << "Exception: " << str << std::endl;
  }

  // добавляем
  test.insert(std::pair<int, int>(2,2));
  std::cout << test[2] << "\n";

  // удаляем всё
  test.remove();
  try{
    std::cout << test[1] << "\n";
  }catch(const char * str){
    std::cout << "Exception: " << str << std::endl;
  }

  std::cout << "[*] Testing assignment\n";
  test[3]=3;
  std::cout << "[*] Done\n";
  try{
    std::cout << test[3] << "\n";
  }catch(const char * str){
    std::cout << "Exception: " << str << std::endl;
  }
  return 0;
}
