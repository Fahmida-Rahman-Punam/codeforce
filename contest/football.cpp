#include<iostream>
using namespace std;
int main(){
string s;
cin>>s;
int count = 1;
bool found =false;
for(int i=1;i<s.length();i++){
    if(s[i]==s[i-1]){
        count++;
    }
    else {
        count=1;
    }
    if(count>=7){
        found=true;
    }
}
if(found){
    cout<<"YES"<<endl;
}
else{
    cout<<"NO"<<endl;
}
return 0;

}