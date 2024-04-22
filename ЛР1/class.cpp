#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>

using namespace std;

class books{
	private:
		string author, name, publishing, genre;
		int data;
		float price;
	public:
		void set_fields();
		void outdata();
		void task();
};

void before_break();

int main(){
	books b1,b2;
	int i = 1;
	while(i){
		system("cls");
		cout<<"Menu:"<<endl<<
		"1 - Read data"<<endl<<
		"2 - Print data"<<endl<<
		"3 - Task"<<endl<<
		"0 - Exit"<<endl<<
		"Print number->";
		cin>>i;
		switch(i){
			case 1:{
				cout<<"Input fiels of 1st book:"<<endl;
				b1.set_fields();
				cout<<"Input fiels of 2nd book:"<<endl;
				b2.set_fields();
				before_break();
				break;
			}
			case 2:{
				cout<<"Choose 1st or 2nd book:";
				if( getch() == '1') {
					cout<<endl<<"First book:";
					b1.outdata();
					before_break();
					break;
				}
				else {
					cout<<endl<<"Second book:";
					b2.outdata();
					before_break();
					break;
				}
				break;
			}
			case 3:{
				cout<<"Choose 1st or 2nd book:";
				if( getch() == '1') {
					b1.task();
					before_break();
					break;
				}
				else {
					b2.task();
					before_break();
					break;
				}
				break;
			}
			case 0: return 0;
			default:{
				cout<<"You entered incorrect number"<<endl;
				before_break();
				break;
			}
		}
	}
}

void books::set_fields(){
	cout<<"Author->";
	cin>>author;
	cout<<"Name->";
	cin>>name;
	cout<<"Publishing->";
	cin>>publishing;
	cout<<"Genre->";
	cin>>genre;
	cout<<"Date->";
	cin>>data;
	cout<<"Price->";
	cin>>price;
	cout<<"Success"<<endl<<endl;
	return;
}

void books::outdata(){
	cout<<endl<<"Author->"<<author<<endl<<
	"Name->"<<name<<endl<<
	"Publishing->"<<publishing<<endl<<
	"Genre->"<<genre<<endl<<
	"Date->"<<data<<endl<<
	"Price->"<<price<<endl;
	return;
}

void books::task(){
	string ugenre;
	cout<<"Input genre->";
	cin>>ugenre;
	if(ugenre==genre){
		cout<<name<<endl;
		return;
	}
	else cout<<"Different genre=("<<endl;
	return;
}

void before_break(){
	cout<<"Press any key to continue...";
	getch();
}