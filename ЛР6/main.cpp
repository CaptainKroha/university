#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>

using namespace std;

class BOOKS{
	private:
		string author, name, publishing, genre;
		int date;
		float price;
	public:
        BOOKS();
        BOOKS(string, string, string, string, int, float);
        ~BOOKS();
        friend ostream & operator<<(ostream &out, BOOKS &ob);
        friend istream & operator>>(istream &in, BOOKS &ob);
        BOOKS operator!();
        friend void operator++(BOOKS ob);
        bool operator*(BOOKS ob);
        friend int operator-(BOOKS ob1, BOOKS ob2);
};

int main(){
    BOOKS ob1, ob2;
    cout<<"Input data for the second book:"<<endl;
    cin>>ob2;
    cout<<ob1<<ob2;
    _getch();
    cout<<"Let's change genre of the first object."<<endl;
    !ob1;
    cout<<ob1;
    _getch();
    cout<<"Let's change price of the second object."<<endl;
    ++ob2;
    cout<<"Input data for the first book(next oper will compare authors of books and minus prices):"<<endl;
    cin>>ob1;
    cout<<ob1*ob2<<endl<<ob1-ob2<<endl;
    _getch();
}

BOOKS :: BOOKS(){
    author = "Tom B."; name = "Jimbo"; publishing = "SaintPrint"; genre = "S_Fiction"; date = 2020; price = 5.0;
}

BOOKS :: BOOKS(string a, string n, string p, string g, int d, float _p){
    author = a; name = n; publishing = p; genre = g; date = d; price = _p;
}

BOOKS :: ~BOOKS(){
}
ostream & operator<<(ostream &out, BOOKS &ob){
    out<<"Author: "<<ob.author<<endl<<
    "Name: "<<ob.name<<endl<<
    "Publishing: "<<ob.publishing<<endl<<
    "Genre: "<<ob.genre<<endl<<
    "Date: "<<ob.date<<endl<<
    "Price: "<<ob.price<<endl;
    return out;
}
istream & operator>>(istream &in, BOOKS &ob){
    cout<<"Input author:";
    in>>ob.author;
    cout<<"Input name for book:";
    in>>ob.name;
    cout<<"Input publishing of book:";
    in>>ob.publishing;
    cout<<"Input genre:";
    in>>ob.genre;
    cout<<"Input date:";
    in>>ob.date;
    cout<<"Input price:";
    in>>ob.price;
    return in;
}

BOOKS BOOKS::operator!(){
    this->genre = "None";
    return *this;
}

void operator++(BOOKS ob){
    if(ob.price<100){
    ob.price = 0;
    return;
    }
    ob.price = ob.price - 100;
    cout<<ob;
    return;
}

bool BOOKS::operator*(BOOKS ob){
    if(this->author == ob.author) return true;
    return false;
}

int operator-(BOOKS ob1, BOOKS ob2){
    float a = ob1.price-ob2.price;
    return a>0?a:-a;
}