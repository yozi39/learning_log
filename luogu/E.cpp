#include<bits/stdc++.h>
using namespace std;
long long he(int m){
    long long num=1;
    while(m>=1){
        num*=m;
        m--;
    }
    return num;
}
int main(){
    long long n;
    string word;
    cin>>n>>word;
    int wrd[30]={0};
    for(int i=0;i<word.size();i++){
        int temp=word[i]-'A'+1;
        wrd[temp]++;
    }
    long long sum=1;
    for(int i=0;i<30;i++){
        if(wrd[i] !=0 ){
            sum*=he(wrd[i]);
        }
    }
    long long ans=he(n)/sum;
    cout<<1<<'/'<<ans;
}