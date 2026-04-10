#include<bits/stdc++.h>
using namespace std;

int all(int num){
    num=(num%1000000)/100000+(num%100000)/10000+(num%10000)/1000+(num%1000)/100+(num%100)/10+(num%10);
    return num;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,num,temp=1;
    queue<int> yes;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num;
        temp=all(num)%7;
        if(temp==0){
            yes.push(0);
        }
        else{
            yes.push(1);
        }
    }
    int end=yes.size();
    for(int i=0;i<end;i++){
        if(yes.front() == 0)cout<<"Yes"<<'\n';
        else{
            cout<<"No"<<'\n';
        }
        yes.pop();
    }
}