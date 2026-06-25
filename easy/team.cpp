#include<iostream>
using namespace std;
int main(){
    int num=0;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int p,v,t;
        cin>>p;
        cin>>v;
        cin>>t;
        if(p==1&&v==1||p==1&&t==1||t==1&&v==1){
            num++;
        }
        else{
            num=num;
        }

    }
    cout<<num;
}