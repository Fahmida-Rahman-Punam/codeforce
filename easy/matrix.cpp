#include<iostream>
using namespace std;
int main(){
    int matrix[5][5];
    int foundi;
     int foundj;
     int moves =0;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin>>matrix[i][j];

        }
    }
     for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(matrix[i][j]){
                foundi = i;
                foundj =j;
            }
        }      
}
 moves = abs(foundi - 2)+abs(foundj-2);
        cout<<moves<<endl;
        return 0;

}