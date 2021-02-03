#ifndef OOP4_DEPARTAMENT_H
#define OOP4_DEPARTAMENT_H
#include <string>
#include <map>
namespace oop4 {
    /*!
      \brief структура для хранения координат департамента
    */
    struct Location {
      int x;
      int y;
    };

    /*!
    \brief Абстрактный базовый класс
    \author godfuzz3r
    \version 1.0
    \date январь 2021 года
    \warning не возможно создать объект данного класса, не используя наследниеов

    Содержит чистые виртуальные функции и реализацию методов, общих для всех дочерних классов
    */
    class Departament {
    private:
      std::string profile; ///< название профиля департамента
      int license;        ///< номер лицензии
      Location location;  ///< местоположение департамента, определяется двумя целочисленными координатами
      std::string type;   ///< тип департамента, может принимать значение radio, telecom или printing

    public:
      friend std::ostream& operator << (std::ostream& out, const Departament&);

      /*!
        устанавливает имя профиля
        \param[in] profile - имя профиля
      */
      Departament &setProfile(std::string profile);

      /*!
        устанавливает номер лицензии
        \param[in] profile - номер лицензии
      */
      Departament &setLicense(int license);

      /*!
        устанавливает местоположении департамента
        \param[in] x - первая координата
        \param[in] y - вторая координата
      */
      Departament &setLocation(int x, int y);

      /*!
        устанавливает тип департамента
        \param[in] type - тип департамента. telecom, radio или printing
      */
      Departament &setType(std::string type);

      /*!
        Возвращает местоположение департамента
        \return возвращает местоположении в виде двух координат в структуре Location
      */
      Location getLocation() const;

      /*!
        \return Возвращает имя профиля департамента
      */
      std::string getProfile() const ;

      /*!
        \return Возвращает номер лицензии
      */
      int getLicense() const;

      /*!
        \return Возвращает тип лепартамента (telecom, radio или printing)
      */
      std::string getType() const;

      /*!
        Частоту вещания для telecom
        \param[in] частота
      */
      virtual void setFreq(float) = 0;

      // методы для Radiostation
      /*!
        Изменяет количество пар частота-ширина канала для radio
      */
      virtual void changeFreqBand() = 0;

      // Методы для Printing
      /*!
        Устанавливает общий объем тиража печатного издания
        \param[in] тираж
      */
      virtual void setCirculation(int) = 0;

      /*!
        Возвращает периодичность выпусков печатного издания
        \return список дней недели
      */
      virtual std::ostream &showPeriodicy(std::ostream &) const = 0;

      /*!
        Устанавливает периодичность выпусков печатного издания
        \param[in] список дней недели
      */
      virtual void setPeriodicy(std::map<int, std::string> &) = 0;

      /*!
        \return Возвращает информацию о департаменте
      */
      virtual std::ostream& show(std::ostream&)const = 0;

      /*!
        \return Возвращает список опций, доступных для изменения в департаменте
      */
      virtual std::ostream &showOptions(std::ostream &)const = 0;
    };
}

#endif
