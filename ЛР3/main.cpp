#include <iostream>
#include <string>
#include <conio.h>

class Animal{
	private:
		float weight;
	public:
		Animal();
		Animal(float x);
		virtual void input();
		virtual void output();
		virtual void func() = 0;
		virtual ~Animal();

};

class Primates:public Animal{
	private:
		float height;
		bool goes;
	public:
		Primates();
		Primates(float x, float y, bool z);
		void input();
		void output();
		void func();
		~Primates();
};

class Chimpanzee:public Primates{
	private:
		int child;
		std::string sex;
	public:
		Chimpanzee();
		Chimpanzee(float x, float y, bool z, int k, std::string str);
		void input();
		void output();
		void func();
		~Chimpanzee();
};

int main(){
	Animal *ob=new Primates;
	while(1){
		std::cout<<"Menu:\n"
		"1-Input data\n"
		"2-Output data\n"
		"3-Virtual func\n"
		"4-Switch class\n"
		"0-Exit\n"
		"->";
		switch(getch()){
			case '1':{
				ob->input();
				break;
			}
			case '2':{
				ob->output();
				break;
			}
			case '3':{
				ob->func();
				break;
			} 
			case '4':{
				delete ob;
				ob=new Chimpanzee;
				break;
			}
			case '0':{
				delete ob;
				return 0;
			}
		}
	}
	return 0;
}
// функции базового класса
Animal::Animal(){
	weight = 100;
}
Animal::Animal(float x){
	weight = x;
}
void Animal::input(){
	std::cout<<"Input weight:";
	std::cin>>weight;
}
void Animal::output(){
	std::cout<<"Weight of this animal is "<<weight<<std::endl;
}
/*void Animal::func(){
	std::cout<<"Virtual fuc in main class"<<std::endl;
}*/
Animal::~Animal(){
	std::cout<<"Animal destructor"<<std::endl;
}
//функции первого производного класса
Primates::Primates():Animal(){
	height = 2;
	goes = false;
}
Primates::Primates(float x, float y, bool z):Animal(x){
	height = y;
	goes = z;
}
void Primates::input(){
	Animal::input();
	std::cout<<"Input height:";
	std::cin>>height;
	std::cout<<"Is this primate goes?(1 - True, 0 - False):";
	std::cin>>goes;
}
void Primates::output(){
	Animal::output();
	std::cout<<"Height of this primate is "<<height<<std::endl;
	if (goes == true){
		std::cout<<"This primate is goes"<<std::endl;
	}
	else{
		std::cout<<"This primate is not goes"<<std::endl;
	}
}
void Primates::func(){
	std::cout<<"Virtual func in first derived class"<<std::endl;
}
Primates::~Primates(){
	std::cout<<"Primates destructor"<<std::endl;
}
//функции второго производного класса
Chimpanzee::Chimpanzee():Primates(){
	child = 0;
	sex = "men";
}
Chimpanzee::Chimpanzee(float x, float y, bool z, int k, std::string str):Primates(x, y ,z){
	child = k;
	sex = str;
}
void Chimpanzee::input(){
	Primates::input();
	std::cout<<"Input mount of children:";
	std::cin>>child;
	std::cout<<"Input sex of this chimpanzee:";
	std::cin>>sex;
}
void Chimpanzee::output(){
	Primates::output();
	std::cout<<"Mount of children of this chimpanzee is "<<child<<std::endl<<
	"Sex of this chimpanzee is "<<sex<<std::endl;
}
void Chimpanzee::func(){
	std::cout<<"Virtual func in second derived class"<<std::endl;
}
Chimpanzee::~Chimpanzee(){
	std::cout<<"Chimpanzee destructor"<<std::endl;
}