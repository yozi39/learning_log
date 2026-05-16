#include<bits/stdc++.h>
using namespace std;

map<char,int> mp;
unordered_map<char,int> cnt;

int main(){
    string a;
    cin>>a;
    int tmp;
    for(char i='a';i<='z';i++){
        cin>>tmp;
        mp[i]=tmp;
    }
    int score=0;
    for(auto x:a){
        cnt[x]++;
        score+=mp[x];
    }
    for(char i='a';i<'z';i++){
        cout<<cnt[i]<<' ';
    }
    cout<<cnt['z'];
    cout<<'\n';
    cout<<score;
}