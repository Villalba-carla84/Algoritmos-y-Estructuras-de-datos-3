#include <stdio.h>
#include <cstdlib>
#include <iostream>
using namespace std;

class Motor { //clase abstracta
	public:
		Motor(){};
		virtual void encender() = 0;
		virtual void acelerar() = 0;
		virtual void apagar() = 0;		
};

class MotorComun : public Motor{
	public:
		MotorComun(){};
		void encender(){
			 cout <<"Se encendio el motor comun.\n";
		}
		void acelerar(){
			cout <<"El motor comun se acelero.\n";
		}
		void apagar(){
			cout <<"Se apago el motor comun.\n"<<endl;
		}
};

class MotorEconomico : public Motor{
	public:
		MotorEconomico(){};
		void encender(){
			cout<<"Se encendio el motor economico.\n";
		}
		void acelerar(){
			cout<<"El motor economico se acelero.\n";
		}
		void apagar(){
			cout<<"Se apago el motor economico.\n"<<endl;
		}
};

class MotorElectrico{
	public:
		MotorElectricoAdapter(){};
		void conectar(){
			cout<<"El motor electrico se ha conectado.\n";
		}
		void activar(){
			cout<<"El motor electrico ha sido activado.\n";
		}
		void moverMasRapido(){
			cout<<"El motor electrico se mueve mas rapido.\n";
		}
		void detener(){
			cout<<"El motor electrico se ha detenido.\n";
		}
		void desconectar(){
			cout<<"El motor electrico se ha detenido.\n"<< endl;
		}
};

class MotorElectricoAdapter : public Motor{
	private:
		MotorElectrico motorElectrico;
	public:
		MotorElectricoAdapter(){};
		void encender(){
			this->motorElectrico.conectar();
			this->motorElectrico.activar();
		}
		void acelerar(){
			this->motorElectrico.moverMasRapido();
		}
		void apagar(){
			this->motorElectrico.detener();
			this->motorElectrico.desconectar();
		}
};

int main(){
	Motor* myMotor = new MotorComun();
	cout<<"Motor Comun:\n";
	myMotor->encender();
	myMotor->acelerar();
	myMotor->apagar();
	
	delete myMotor;
	
	myMotor = new MotorEconomico();
	cout<<"\n Motor Economico:\n";
	myMotor->encender();
	myMotor->acelerar();
	myMotor->apagar();
	
	delete myMotor;
	
	myMotor = new MotorElectricoAdapter();
	cout <<"\nMotor Electrico:\n";
	myMotor->encender();
	myMotor->acelerar();
	myMotor->apagar();
	
	
	
	system("pause");
	return 0;
}