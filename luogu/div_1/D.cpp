#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int num[n+1];
    for(int i=1;i<=n;i++){
        cin>>num[i];
    }
    int max=0,cnt=0;
    for(int i=1;i<=n;i++){
        if(max<num[i]){
            max=num[i];
            cnt=i;
        }
    }
    if(num[1]>num[n]){
        swap(num[1],num[n]);
        for(int i=1;i<=n;i++){
            cout<<num[i]<<' ';
        }
    }
    else if(num[n]==max){
        for(int i=1;i<=n;i++){
            cout<<num[i]<<' ';
        }
    }
    else{
        swap(num[n],num[cnt]);
        for(int i=1;i<=n;i++){
            cout<<num[i]<<' ';
        }
    }
}