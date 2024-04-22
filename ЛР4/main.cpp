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
	protected:
		int force;
		int age;
	public:
		Chimera();
		Chimera(int, int, float, int, int);
		~Chimera();
		void bite();
		void show();
};

int main(){
	SetConsoleOutputCP(65001);
	int i, size, tox, force, age;
	float speed;
	cout<<"Lets create our creatures!"<<endl;
	cout<<"Enter the size, toxicity, speed, force and age of new Chimera->";
	cin>>size>>tox>>speed>>force>>age;
	Chimera c1;
	Chimera c2(size, tox, speed, force, age);
	cout<<"Creature are created successfully!"<<endl;
	system("pause");
	while(1){
		system("cls");
		cout<<"Menu\n"
		"1 - Вызов уникальных методов базовых классов для обеих химер\n"
		"2 - Вызов переопределнных методов для обеих химер\n"
		"0 - Выход\n"
		"->";
		cin>>i;
		switch(i){
			case 1:{
				c1.roar();
				c1.hiss();
				c1.punch();
				c1.bite();
				c2.roar();
				c2.hiss();
				c2.punch();
				c2.bite();
				system("pause");
				break;
			}
			case 2:{
				c1.Lion::show();
				c1.Snake::show();
				c1.Goat::show();
				c1.Chimera::show();
				c2.Lion::show();
				c2.Snake::show();
				c2.Goat::show();
				c2.Chimera::show();
				system("pause");
				break;
			}
			case 0:{
				return 0;
				break;
			}
		}
	}
	
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