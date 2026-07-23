#include<iostream>
using namespace std;
int main(){
    int n,m,a,b;
    cin>>n>>m>>a>>b;
   int full = n/m;
   int rem = n%m;
   int total = full* min(m*a,b)+min(rem*a,b);
   cout<<total<<endl;
    return 0;
}