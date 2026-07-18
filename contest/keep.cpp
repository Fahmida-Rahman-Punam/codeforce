
#include<iostream>
#include<string>
using namespace std;
int main(){
    int n;
    cin>>n;
    int lost=0;
    for(int i=0;i<n;i++){
        int a,b;
        string s;
        cin>>a>>b>>s;
        if(s=="keep"){
            lost+=(b-a);
        }
    }
std:: cout<<lost<<endl;
   return 0;
}
