#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[5]={0},n;
    cin>>n;
    if(n%2==0 && n>4 && n<=12)a[1]=1;
    if(n%2==0 || (n>4 && n<=12))a[2]=1;
    if((n%2==0 && !(n>4 && n<=12)) || (!(n%2==0) && (n>4 && n<=12)))a[3]=1;
    if(!(n%2==0 || (n>4 && n<=12)))a[4]=1;
    for(int i=1;i<=4;i++)
        cout<<a[i]<<' ';
}