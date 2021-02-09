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

  template <class T1, class T2>
	class MapIterator : public std::iterator<std::random_access_iterator_tag, T<T1,T2>> {
	private:
		T<T1,T2>* buf;
	public:
		MapIterator(T<T1,T2>* c) : buf(c) {}

		bool operator =(MapIterator<T1,T2> it);
		bool operator ==(const MapIterator<T1,T2> it) const;
		bool operator !=(const MapIterator<T1,T2> it) const;
		MapIterator<T1,T2>& operator ++();
		MapIterator<T1,T2> operator ++(int);
		MapIterator<T1,T2>& operator --();//pfiks
		MapIterator<T1,T2> operator --(int);
		T<T1,T2>& operator *();
		T<T1,T2>* operator ->();
		MapIterator<T1,T2>& operator +=(int n);
		MapIterator<T1,T2> operator +(int n);
		MapIterator<T1,T2>& operator -=(int n);
		MapIterator<T1,T2> operator -(int n);
		int operator -(MapIterator<T1,T2> it);
		bool operator <(MapIterator<T1,T2> it);
		bool operator >(MapIterator<T1,T2> it);
	};

	template <typename T1, typename T2>
	MapIterator<T1,T2>& MapIterator<T1,T2>::operator++() {
		++buf;
		return *this;
	}

	template <typename T1, typename T2>
	MapIterator<T1,T2> MapIterator<T1,T2>::operator++(int) {
		MapIterator<T1,T2> tmp = buf;
		++buf;
		return tmp;
	}

	template <typename T1, typename T2>
	MapIterator<T1,T2>& MapIterator<T1,T2>::operator --() {
		--buf;
		return *this;
	}

	template <typename T1, typename T2>
	MapIterator<T1,T2> MapIterator<T1,T2>::operator --(int) {
		MapIterator<T1,T2> tmp = buf;
		--buf;
		return tmp;
	}

	template <typename T1, typename T2>
	T<T1,T2>& MapIterator<T1,T2>::operator *() {
		return *buf;
	}

	template <typename T1, typename T2>
	T<T1,T2>* MapIterator<T1,T2>::operator ->() {
		return buf;
	}

	template <typename T1, typename T2>
	bool MapIterator<T1,T2>::operator ==(const MapIterator<T1,T2> it) const {
		return buf == it.buf;
	}

	template <typename T1, typename T2>
	bool MapIterator<T1,T2>::operator !=(const MapIterator<T1,T2> it) const {
		return buf != it.buf;
	}

	template <typename T1, typename T2>
	MapIterator<T1,T2>& MapIterator<T1,T2>::operator +=(int n) {
		if (n > 0) {
			while (n > 0) {
				n--;
				++(*this);
			}
		}
		else {
			while (n < 0) {
				n++;
				--(*this);
			}
		}
		return(*this);
	}

	template <typename T1, typename T2>
	MapIterator<T1,T2> MapIterator<T1,T2>::operator +(int n) {
		MapIterator<T1,T2> tmp = *this;
		return tmp += n;
	}

	template <typename T1, typename T2>
	MapIterator<T1,T2>& MapIterator<T1,T2>::operator -=(int n) {
		return (*this += -n);
	}

	template <typename T1, typename T2>
	MapIterator<T1,T2> MapIterator<T1,T2>::operator -(int n) {
		MapIterator<T1,T2> tmp = *this;
		return tmp -= n;
	}

	template <typename T1, typename T2>
	int MapIterator<T1,T2>::operator -(MapIterator<T1,T2> it) {
		int counter = 0;
		if (buf <= it.buf) {
			while ((*this - counter) != it) counter--;
		}
		else {
			while ((*this - counter) != it) counter++;
		}
		return counter;
	}

	template <typename T1, typename T2>
	bool MapIterator<T1,T2>::operator < (MapIterator<T1,T2> it) {
		if (it - *this > 0) return true;
		else return false;
	}

	template <typename T1, typename T2>
	bool MapIterator<T1,T2>::operator >(MapIterator<T1,T2> it) {
		return it < *this;
	}

	template <typename T1, typename T2>
	bool MapIterator<T1,T2>::operator =(MapIterator<T1,T2> it) {
		buf = it.buf;
		return true;
	}


  template<class T1, class T2>
  class map{
  private:
      int size;
      T<T1, T2> * buff;

  public:
      typedef MapIterator<T1, T2> Iterator;

      map(): size(0), buff(nullptr){}

      ~map(){
        delete[] buff;
      }

      Iterator begin() {
  			return Iterator(this->buff);
  		}
  		Iterator end() {
  			return Iterator(this->buff + this->size);
  		}

      void remove(){
          delete[] buff;
          buff = nullptr;
          size = 0;
      }

      Iterator find(T1 key){
          for (Iterator i = begin(); i != end(); i++){
              if (i->first == key)
                  return i;
          }
          return nullptr;
      }

      Iterator insert(std::pair<T1, T2> elem){
          if (find(elem.first) != nullptr){
              return nullptr; //найден
          }

          T<T1, T2> * tmp_buf = new T<T1, T2>[size+1];
          for(int i = 0; i < size; i++){
            tmp_buf[i].first = buff[i].first;
            tmp_buf[i].second = buff[i].second;
          }
          tmp_buf[size].first = elem.first;
          tmp_buf[size].second = elem.second;

          delete[] buff;
          buff = tmp_buf;

          size++;
          return Iterator(this->buff);
      }

      bool erase(T1 key){
          if (size == 0)
            return false;
          if (find(key) == nullptr)
            return false;

          T<T1, T2> * tmp_buf = new T<T1, T2>[size-1];
          std::cout << "1\n";
          std::cout << "2\n";

          int i = 0;
          for (Iterator it = begin(); it != end(); it++){
            if (it->first != key){
              tmp_buf[i].first = it->first;
              tmp_buf[i].second = it->second;
              i++;
            }
          }

          delete[] buff;
          buff = tmp_buf;
          return true;
      }

      T2& operator[](T1 key){
          for (int i = 0; i < size; i++){
            if (buff[i].first == key)
              return buff[i].second;
          }

          throw "Not found";
      };
  };
}
#endif
