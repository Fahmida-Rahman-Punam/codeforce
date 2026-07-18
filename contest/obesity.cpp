
#include<iostream>
using namespace std;
int main(){
    int h , w;
    float bmi;
    cin>>h>>w;
    
    float uppper = 10000*w;
    float lower = 25*h*h;
   
    if (uppper>=lower){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}
