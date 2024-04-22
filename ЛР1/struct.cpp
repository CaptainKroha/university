#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
using namespace std;
struct books{
	string author, name, publishing, genre;
	int data;
	float price;
};
void input_data(books& book);
void output_data(books& book);
void task(books& book);
void before_break();
books& choose(books& book1, books& book2);

main(){
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
				input_data(b1);
				cout<<"Input fiels of 2nd book:"<<endl;
				input_data(b2);
				before_break();
				break;
			}
			case 2:{
				output_data(choose(b1,b2));
				before_break();
				break;
			}
			case 3:{
				task(choose(b1,b2));
				before_break();
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
void input_data(books& book){
	cin.ignore();
	cout<<"Author->";
	getline(cin, book.author);
	cout<<"Name->";
	getline(cin,book.name);
	cout<<"Publishing->";
	getline(cin,book.publishing);
	cout<<"Genre->";
	getline(cin,book.genre);
	cout<<"Date->";
	cin>>book.data;
	cout<<"Price->";
	cin>>book.price;
	cout<<"Success"<<endl<<endl;
	return;
}
void output_data(books& book){
	cout<<endl<<"Author->"<<book.author<<endl<<
	"Name->"<<book.name<<endl<<
	"Publishing->"<<book.publishing<<endl<<
	"Genre->"<<book.genre<<endl<<
	"Date->"<<book.data<<endl<<
	"Price->"<<book.price<<endl;
	return;
}
void task(books& book){
	string genre;
	cout<<"Input genre->";
	getline(cin,genre);
	if(genre==book.genre){
		cout<<book.name<<endl;
		return;
	}
	else cout<<"Different genre=("<<endl;
	return;
}
void before_break(){
	cout<<"Press any key to continue...";
	getch();
}
books& choose(books& book1, books& book2){
	cout<<"Choose 1st or 2nd book:";
	if( getch() == '1') {
		cout<<endl<<"First book:";
		return book1;
	}
	else {
		cout<<endl<<"Second book:";
		return book2;
	}
}