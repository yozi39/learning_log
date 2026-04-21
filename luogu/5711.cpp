#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,is=0;
    cin>>n;
    if(n%4 == 0 && n%100 != 0)is=1;
    else if(n%400==0)is=1;
    cout<<is;
}