#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
    int a[3][3]={{1,5,6},{8,25,9},{14,16,81}};
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%3d",a[i][j]);
        }
        cout<<'\n';
    }
}