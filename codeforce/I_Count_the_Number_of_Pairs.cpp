#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=0;

int main(){
    int T;cin>>T;
    while(T--){
        int n,k;cin>>n>>k;
        string s;cin>>s;
        int ret=0,origin=0,hope=0;
        unordered_map<char,int> mp;

        for(auto ch:s){
            mp[ch]++;
        }

        for(auto v:mp){//求出来了原生数量
            char ch=v.first;
            int t=v.second;

            if(ch>='A' && ch<='Z' && mp.count(tolower(ch))){
                origin+=min(t,mp[tolower(ch)]);
            }
        }

        for(int i='a';i<='z';i++){
            hope+=(mp[i]+mp[toupper(i)])/2;
        }


        if(k+origin<hope){
            cout<<origin+k<<'\n';
        } else {
            cout<<hope<<'\n';
        }
    }
}


/*
    max = (a+A)/2
    奇数自动取整
    偶数刚好是max

    统计一个是差值,一个是原生
    本身是  差值-原生=k  最理想

    so true  k+原生<差值
    如果 >了   原生变成差值


    a 4  A 2
    b 1  B 1
    c 1  C 1
    e 0  E 1    
*/
