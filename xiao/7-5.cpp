#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int num[n+1];
    for(int i=1;i<=n;i++)
        cin>>num[i];
    for(int i=n;i>=2;i--){
        cout<<num[i]<<' ';
    }
    cout<<num[1];
}