#include "container.h"
#include <iostream>
#include <string>

int main(){
  oop4::map<int, std::string> test;

  // добавляем
  test.insert(std::pair<int, std::string>(1,"kek"));

  // вывод через перегрузку
  std::cout << "overloaded output: " << test[1] << "\n";

  // ищем
  auto it = test.find(1);
  std::cout << "search with iterators: " << it->second << "\n";

  // добавим ещё
  test.insert(std::pair<int, std::string>(2,"asdasdasd"));
  test.insert(std::pair<int, std::string>(4,"chetire"));

  //выводим всё
  std::cout << "\n";
  for (auto it = test.begin(); it != test.end(); it++){
    std::cout << it->first << ": " << it->second << "\n";
  }

  // удаляем
  test.erase(1);
  std::cout << "Check after remove...\n";
  try{
    std::cout << test[1] << "\n";
  }catch(const char * str){
    std::cout << "[+] Exception: " << str << std::endl;
  }

  // удаляем всё
  test.remove();
  std::cout << "\n";
  for (auto it = test.begin(); it != test.end(); it++){
    std::cout << it->first << ": " << it->second << "\n";
  }

  return 0;
}
