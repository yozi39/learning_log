#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int num[n+1];
    for(int i=1;i<=n;i++)
        cin>>num[i];
    sort(num+1,num+1+n);
    for(int i=1;i<=n-1;i++)
        cout<<num[i]<<' ';
    cout<<num[n];
}