#include <iostream>
#include <stdexcept>
#include <memory>
using namespace std;

class Chair{
    public:
        virtual bool hasLegs() = 0;
         virtual ~Chair(){};
};

class ModernChair : public Chair{
    public:
        virtual bool hasLegs()  {return true;}
        virtual ~ModernChair() {};
} ;

class VictorianChair : public Chair{
    public:
        virtual bool hasLegs()  {return true;}
        virtual ~VictorianChair() {};
} ;

class CoffeeTable{
    public:
        virtual bool hasLegs() = 0;
        virtual ~CoffeeTable(){};
};

class ModernCoffeeTable : public CoffeeTable{
    public:
        virtual bool hasLegs() {return true;}
        virtual ~ModernCoffeeTable() {};
} ;

class VictorianCoffeeTable : public CoffeeTable{
    public:
        virtual bool hasLegs()  {return true;}
        virtual ~VictorianCoffeeTable() {};
} ;

class Sofa{
    public:
        virtual bool hasLegs() = 0;
        virtual ~Sofa(){};
};

class ModernSofa : public Sofa{
    public:
        virtual bool hasLegs() {return true;}
        virtual ~ModernSofa() {};
} ;

class VictorianSofa : public Sofa{
    public:
        virtual bool hasLegs()  {return true;}
        virtual ~VictorianSofa() {};
} ;




class MuebleriaFactory {
public:
	virtual Chair* createChair()= 0;
    virtual CoffeeTable* createCoffeeTable() = 0;
    virtual Sofa* createSofa()= 0;
    virtual ~MuebleriaFactory() {};

};

class ModernFactory : public MuebleriaFactory {
public:

	Chair* createChair() {
        cout << " Modern Chair." ;
	    return new ModernChair();
	  };
    CoffeeTable* createCoffeeTable()  {
       cout << " Modern CoffeeTable.";
       return new ModernCoffeeTable();
     };
    Sofa* createSofa()  {
        cout << " Modern sofa.";
        return new ModernSofa();
    };

    virtual ~ModernFactory() {};
};

class VictorianFactory : public MuebleriaFactory {
public:

	Chair* createChair()   {
	    cout << " Victorian Chair.";
	    return new VictorianChair();
	    };
    CoffeeTable* createCoffeeTable() {
        cout << " Victorian CoffeeTable.";
        return new VictorianCoffeeTable();
         };
    Sofa* createSofa()  {
        cout << " Victorian Sofa.";
        return new VictorianSofa();
        };
    virtual ~VictorianFactory() {};
};



void ClientCode( MuebleriaFactory& creator) {

  std::cout << " \n Creando:" << std::endl
            << creator.createChair()->hasLegs() << std::endl
            << creator.createCoffeeTable()->hasLegs() << std::endl
            << creator.createSofa()->hasLegs() << std::endl;
  // ...
}

int main(){

    MuebleriaFactory* muebleriaFactoryModern = new ModernFactory();
  ClientCode(*muebleriaFactoryModern);

    MuebleriaFactory* muebleriaFactoryVirtorian = new VictorianFactory();
  ClientCode(*muebleriaFactoryVirtorian);



    return 0;
}
