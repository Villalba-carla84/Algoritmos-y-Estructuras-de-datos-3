#include <iostream>
using namespace std;

class IHotel {
 public:
  virtual ~IHotel() {}
  virtual string Price() const = 0;
};
class ConcreteHotel : public IHotel {
 public:
 string Price() const override {
    return "Hotel 3 estrella. $7.000 el dia ) ";
  }
};

class Decorator : public IHotel {
 protected:
  IHotel* hotel_;
 public:
  Decorator(IHotel* hotel) : hotel_(hotel) {}
 string Price() const override {
    return this->hotel_->Price();
  }
};

class ConcreteDecoratorApartamento: public Decorator {
   public:
  ConcreteDecoratorApartamento(IHotel* hotel) : Decorator(hotel) {
  }
 string Price() const override {
    return " apartamento:$5.000 el dia. (" + Decorator::Price() + " )";
  }
};

class ConcreteDecoratorHostel: public Decorator {
   public:
  ConcreteDecoratorHostel(IHotel* hotel) : Decorator(hotel) {}
 string Price() const override {
    return " Hostel:$3.000 el dia. (" + Decorator::Price() + " )";
  }
};







void FindHotel(IHotel* hotel) {
 cout << " PRESUPUESTO: " << hotel->Price();
  };

int main() {
  IHotel * basic = new ConcreteHotel;
  cout << " BUSQUEDA:  Hotel de 3 estrella:  \n";
  FindHotel (basic);
 cout << "\n\n";

  IHotel* decorator1 = new ConcreteDecoratorApartamento(basic);
  IHotel* decorator2 = new ConcreteDecoratorHostel(decorator1);
  cout << " BUSQUEDA:ahora tengo mas opciones \n";
  FindHotel (decorator2);
  cout << "\n";

  delete basic;
  delete decorator1;
  delete decorator2;

  return 0;

}