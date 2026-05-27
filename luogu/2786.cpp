#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int n,MOD;
map<string,int> mp;

int main(){
    string tmp;
    cin>>n>>MOD;for(int i=1;i<=n;i++)cin>>tmp>>mp[tmp];

    char ch;
    string word="";
    long long ans=0;

    while(cin.get(ch)){
        if(isalnum(ch)){
            word+=ch;
        }
        else{
            if(word.size()){
                if(mp.count(word)){
                    ans=(ans+mp[word])%MOD;
                }
                word="";
            }
        }
    }

    if(word.size()){
        if(mp.count(word)){
            ans=(ans+mp[word])%MOD;
        }
    }

    cout<<ans;
}