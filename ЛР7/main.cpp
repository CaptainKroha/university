#include <iostream>
#include <windows.h>
#include <conio.h>
#define N 10

using namespace std;

template<class T>
int search(T* arr, T key){
    int i;
    for(i = 0; i < N; i++) if(arr[i] == key) return i;
    return -1;
}

template<class T>
T* fill(T* arr){
    arr = (T*)malloc(sizeof(T)*N);
    for(int i = 0; i<N; i++) cin>>arr[i];
    return arr;
}

template<class T>
void print(T* arr){
    for(int i = 0; i<N; i++) cout<<arr[i]<<" ";
    cout<<endl;
}

int main(){
    // int i_mas[]{1,6,4,9,23,4,19,20,3,7};
    // char c_mas[]{"fdgbshjht"};
    cout<<"Lets fill int array(10 items):";
    int *i_mas = fill(i_mas);
    cout<<"Lets fill char array(10 items):";
    char *c_mas = fill(c_mas);
    cout<<"Your int array:"<<endl;
    print(i_mas);
    cout<<"Your char array:"<<endl;
    print(c_mas);
    int i = search(i_mas, 9);
    if(i==-1) cout<<"Int key not found"<<endl;
    else cout<<"Int key ind is "<<i<<endl;
    i = search(c_mas, 'b');
    if(i==-1) cout<<"Char key not found"<<endl;
    else cout<<"Char key ind is "<<i<<endl;
    _getch();
    return 0;
}