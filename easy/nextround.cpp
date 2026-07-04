#include<iostream>
using namespace std;
int main(){
    int n;
    int k;
    int value[50];
    int sum=0;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>value[i];

    }
    int kth=value[k-1];
    for(int i=0;i<n;i++){
        if(value[i]>=kth&&value[i]>0){
            sum++;
        }
    }
    cout<<sum<<endl;
    return 0;
  

}
