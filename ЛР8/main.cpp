#include <iostream>
#include <iomanip>
#include <windows.h>
#include <string.h>

class RHOMB{
    double d1, d2;
    char color[15];
    public:
        RHOMB(){d1 = 1.0; d2 = 1.0; strcpy(color, "Red");}
        double count_square();
        void fill_fields();
};

int main(){
    RHOMB o1;
    o1.fill_fields();
    o1.count_square();
    system("pause");
    return 0;
}

void RHOMB::fill_fields(){
    std::cout<<"You to need to input field of your rhomb:"<<std::endl;
    double temp;
    while(1){
        try{
            std::cout<<"Input first diag:";
            std::cin>>temp;
            if(!std::cin) throw '1';
            if(temp<0 || temp==0) throw 1;
            d1 = temp;
            break;
        }
        catch(char){std::cout<<"Incorrect symbols"<<std::endl;}
        catch(int){std::cout<<"Incorrect number"<<std::endl;}
        std::cin.clear();
        std::cin.ignore(MAXINT, '\n');
        system("pause && cls");
    }
    while(1){
        try{
            std::cout<<"Input second diag:";
            std::cin>>temp;
            if(!std::cin) throw '1';
            if(temp<0 || temp==0) throw 1;
            d2 = temp;
            break;
        }
        catch(char){std::cout<<"Incorrect symbols"<<std::endl;}
        catch(int){std::cout<<"Incorrect number"<<std::endl;}
        std::cin.clear();
        std::cin.ignore(MAXINT, '\n');
        system("pause && cls");
    }
    char temp_str[15];
    while(1){
        try{
            std::cin.ignore(MAXINT, '\n');
            std::cout<<"Input rhomb color:";
            std::cin.getline(temp_str, 15);
            for(int i = 0; i<15||temp_str[i]!='\0'; i++){
                if(temp_str[i]>='1'&&temp_str[i]<='0') throw 1;
            }
            strcpy(color, temp_str);
            break;
        }
        catch(int){std::cout<<"Incorrect symbols in string"<<std::endl;}
        std::cin.clear();
        std::cin.ignore(MAXINT, '\n');
        system("pause && cls");
    }
    std::cout<<std::endl<<d1<<'\t'<<d2<<'\t'<<color<<std::endl;
}

double RHOMB::count_square(){
    double S = 0.5 * (d1*d2);
    std::cout<<"Square of your romb:";
    std::cout.width(19);
    std::cout.precision(4);
    std::cout.setf(std::ios::left);
    std::cout<<std::setfill('?')<<S<<std::endl;
    return S;
}