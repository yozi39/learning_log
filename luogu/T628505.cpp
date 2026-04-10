#include<bits/stdc++.h>
using namespace std;
int main(){
    int m,n;
    cin>>n>>m;
    int sum=0;
    int temp[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>temp[i][j];
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            sum+=temp[j][i];
        }
        cout<<sum<<'\n';
        sum=0;
    }
}