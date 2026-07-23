#include<iostream>
using namespace std;
int main(){
    int k,n,w;
    cin>>k>>n>>w;
    int p;
    int sum=0;
    for(int i=1;i<=w; i++){
        p=k*i;
        sum=sum+p;
    }
    if(n>=sum){
        cout<<"0"<<endl;
       
    }
    else{
        
         int rem=sum-n;
        cout<<rem<<endl;
    }
    return 0;
}