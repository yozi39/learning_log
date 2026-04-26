#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%4d",j+i);
        }
        cout<<'\n';
    }
}