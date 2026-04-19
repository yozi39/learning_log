#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int main(){
    int n,a[N];
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)cout<<a[i]<<' ';
}