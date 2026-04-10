#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a,b;
    cin>>a>>b;
    if(a<=b){
        for(int i=a;i<=b;i++){
            cout<<i<<'\n';
        }
    }
    else{
        cout<<"Error!";
    }
}