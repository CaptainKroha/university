#include <iostream>
#include <windows.h>

using namespace std;


class Lion{
	protected:
		int size;
	public:
		Lion();
		Lion(int);
		~Lion();
		void roar();
		void show();
};

class Snake{
	protected:
		int toxicity;
	public:
		Snake();
		Snake(int);
		~Snake();
		void hiss();
		void show();
};

class Goat{
	protected:
		float speed;
	public:
		Goat();
		Goat(float);
		~Goat();
		void punch();
		void show();
};

class Chimera:public Lion, public Snake, public Goat{
	private:
		string name;
	protected:
		int force;
		int age;
	public:
		Chimera();
		Chimera(int, int, float, int, int);
		~Chimera();
		void bite();
		void show();
		friend void f(Chimera ob);
};

void f(Chimera ob){
	cout<<"Its name is "<<ob.name<<endl;
}

int main(){
	SetConsoleOutputCP(65001);
	Chimera c1;
	cout<<"Creature was created successfully!"<<endl;
	system("pause");
	cout<<"Lets see private fiels"<<endl;
	f(c1);
	return 0;
}

//Lion
Lion::Lion(){
	cout<<"constr_lion"<<endl;
	size = 10;
}
Lion::Lion(int _x){
	cout<<"constr_lion1"<<endl;
	size = _x;
}
Lion::~Lion(){
	cout<<"destr_lion"<<endl;
}
void Lion::roar(){
	cout<<"Roooar!!!"<<endl;
}
void Lion::show(){
	cout<<"U, it is lion! Its size is "<< size <<endl;
}
//
//Snake
Snake::Snake(){
	cout<<"constr_snake"<<endl;
	toxicity = 3;
}
Snake::Snake(int _x){
	cout<<"constr_snake1"<<endl;
	toxicity = _x;
}
Snake::~Snake(){
	cout<<"destr_snake"<<endl;
}
void Snake::hiss(){
	cout<<"Hissssss...."<<endl;
}
void Snake::show(){
	cout<<"U, it is shake! Its toxicity is "<< toxicity<<endl;
}
//Goat
Goat::Goat(){
	cout<<"constr_goat"<<endl;
	speed = 50;
}
Goat::Goat(float _x){
	cout<<"constr_goat1"<<endl;
	speed = _x;
}
Goat::~Goat(){
	cout<<"destr_goat"<<endl;
}
void Goat::punch(){
	cout<<"Punch!"<<endl;
}
void Goat::show(){
	cout<<"U, it is goat! Its speed is "<<speed<<endl;
}
//Chimera
Chimera::Chimera(){
	cout<<"constr_chimera"<<endl;
	name = "John";
	force = 100;
	age = 25;
}
Chimera::Chimera(int size, int tox, float speed, int f, int a):Lion(size), Snake(tox), Goat(speed){
	cout<<"constr_chimera1"<<endl;
	force = f;
	age = a;
}
Chimera::~Chimera(){
	cout<<"destr_chimera"<<endl;
}
void Chimera::bite(){
	cout<<"Bite!"<<endl;
}
void Chimera::show(){
	cout<<"WOW, it is CHIMERA!!! Its force is "<<force<<" and its age is "<<age<<endl;
}