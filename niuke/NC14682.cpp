#include<bits/stdc++.h>
using namespace std;

int n,sum;

int main(){
    cin>>n;
    for(int i=1;i<=n/2;i++)sum+=n/i;
    sum+=(n-(n/2));
    cout<<sum;
}