#include<bits/stdc++.h>
using namespace std;

int main(){
    int socre,count=0;
    for(int i=0;i<3;i++){
        cin>>socre;
        if(socre<60)count++;
    }
    if(count==1)cout<<count<<'\n';
    else cout<<0<<'\n';
}