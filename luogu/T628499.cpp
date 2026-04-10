#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a;
    cin>>a;
    cout<<a.length()<<'\n';
    for(int i=0;i+2<a.length();i++){
        cout<<a.substr(i,3)<<" ";
    }
}