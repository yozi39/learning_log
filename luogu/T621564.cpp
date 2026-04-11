#include<bits/stdc++.h>
using namespace std;
int main(){
    int cnt=0;
    int n;
    cin>>n;
    int num[n];
    for(int i=0;i<n;i++)
        cin>>num[i];
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int sum=num[i]+num[j];
            if(int(sqrt(sum))*int(sqrt(sum))==sum)cnt++;
        }
    }
    cout<<cnt;
}