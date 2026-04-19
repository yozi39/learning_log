#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int num[n];
    for(int i=0;i<n;i++)
        cin>>num[i];
    int sort[10005]={0};
    for(int i=0;i<n;i++){
        int tmp=num[i];
        sort[tmp]++;
    }
    for(int i=0;i<10005;i++){
        for(int j=0;j<sort[i];j++){
            cout<<i<<' ';
        }
    }
}