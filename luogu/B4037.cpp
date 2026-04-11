#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    char pan[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            pan[i][j]='-';
    for(int i=0;i<n;i+=n-1){
        for(int j=0;j<n;j++){
            pan[j][i]='+';
        }
    }
    for(int i=0;i<n;i++){
        pan[i][i]='+';
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<pan[i][j];
        }
        cout<<'\n';
    }
}