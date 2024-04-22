#include <iostream>
#include <string>

class Animal{
	private:
		float weight;
	public:
		Animal();
		Animal(float x);
		void input_1();
		void output_1();
		void func();

};

class Primates:public Animal{
	private:
		float height;
		bool goes;
	public:
		Primates();
		Primates(float x, float y, bool z);
		void input_2();
		void output_2();
		void func();
};

class Chimpanzee:public Primates{
	private:
		int child;
		std::string sex;
	public:
		Chimpanzee();
		Chimpanzee(float x, float y, bool z, int k, std::string str);
		void input_3();
		void output_3();
		void func();
};

int main(){
	Chimpanzee ob1, ob2(1.23, 1.8, true, 4, "women");
	ob1.input_3();
	ob1.output_1();
	ob1.output_2();
	ob1.output_3();
	ob2.output_3();
	ob1.func();
	ob2.func();
	ob1.Primates::func();
	ob1.Animal::func();
	return 0;
}
// функции базового класса
Animal::Animal(){
	weight = 100;
}
Animal::Animal(float x){
	weight = x;
}
void Animal::input_1(){
	std::cout<<"Input weight:";
	std::cin>>weight;
}
void Animal::output_1(){
	std::cout<<"Weight of this animal is "<<weight<<std::endl;
}
void Animal::func(){
	std::cout<<"Redefined fuc in main class"<<std::endl;
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
void Primates::input_2(){
	Animal::input_1();
	std::cout<<"Input height:";
	std::cin>>height;
	std::cout<<"Is this primate goes?(1 - True, 0 - False):";
	std::cin>>goes;
}
void Primates::output_2(){
	Animal::output_1();
	std::cout<<"Height of this primate is "<<height<<std::endl;
	if (goes == true){
		std::cout<<"This primate is goes"<<std::endl;
	}
	else{
		std::cout<<"This primate is not goes"<<std::endl;
	}
}
void Primates::func(){
	std::cout<<"Redefined func in first derived class"<<std::endl;
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
void Chimpanzee::input_3(){
	Primates::input_2();
	std::cout<<"Input mount of children:";
	std::cin>>child;
	std::cout<<"Input sex of this chimpanzee:";
	std::cin>>sex;
}
void Chimpanzee::output_3(){
	Primates::output_2();
	std::cout<<"Mount of children of this chimpanzee is "<<child<<std::endl<<
	"Sex of this chimpanzee is "<<sex<<std::endl;
}
void Chimpanzee::func(){
	std::cout<<"Redefined func in second derived class"<<std::endl;
}