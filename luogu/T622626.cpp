#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10;
int num[N];

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>num[i];
    sort(num+1,num+1+n);
    int cnt=1;
    for(int i=1;i<=n;i++){
        if(cnt==1)cout<<num[i];
        if(num[i+1] == num[i]){
            cnt++;
        }
        else{
            cout<<' '<<cnt<<'\n';
            cnt=1;
        }
    }    
}