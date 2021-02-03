#ifndef OOP4_CONTAINER_H
#define OOP4_CONTAINER_H
#include <cassert>
#include <utility>
#include <iostream>
namespace oop4 {

  template <typename T1, typename T2>
  struct T{
      T1 first;
      T2 second;
  };

  template<typename T1, typename T2>
  class map{
  private:
      int size;
      T<T1, T2>* buff;

  public:
      typedef T<T1, T2> Iterator;

      map(): size(0), buff(nullptr){}

      ~map(){
        delete[] buff;
      }

      void remove(){
          delete[] buff;
          buff = nullptr;
          size = 0;
      }

      Iterator* begin(){
          return this->buff;
      }

      Iterator* end(){
          return (this->buff + this->size);
      }

      Iterator* find(T1 key){
          for (Iterator* i = begin(); i != end(); i++){
              if (i->first == key)
                  return i;
          }
          return nullptr;
      }

      std::pair<Iterator*, bool> insert(std::pair<T1, T2> elem){
          if (find(elem.first)){
              return std::pair<Iterator*, bool>(nullptr, false); //найден
          }

          Iterator * tmp_buf = new Iterator[size+1];
          for(int i = 0; i < size; i++){
            tmp_buf[i].first = buff[i].first;
            tmp_buf[i].second = buff[i].second;
          }
          tmp_buf[size].first = elem.first;
          tmp_buf[size].second = elem.second;

          delete[] buff;
          buff = tmp_buf;

          size++;
          return std::pair<Iterator*, bool>((this->buff + size-1), true);
      }

      bool erase(Iterator* elem){
          Iterator * tmp_buf = new Iterator[size-1];

          if (find(elem->first) == nullptr){
            return false;
          }
          for (int i,j = 0; i < size; i++){
            if ((buff[j].first != elem->first) && (buff[j].second != elem->second)){
              tmp_buf[i] = buff[j];
            }else{
              j++;
            }
            j++;
          }
          delete[] buff;
          buff = tmp_buf;
          return true;
      }

      T2& operator[](T1 key){
        std::cout << "bbbbbbbb\n";
          for (int i = 0; i < size; i++){
            if (buff[i].first == key)
              return buff[i].second;
          }

          throw "Not found";
      };

      Iterator& operator=(const Iterator& other) {
      	std::cout << "aaaaa\n";
      	return *this;
      }

      map<T1,T2>& operator[](std::pair<T1, T2> elem){
        std::cout << "aaaaa\n";
        //insert(elem);
        return *this;
      }
  };
}
#endif
