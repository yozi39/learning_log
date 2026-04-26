#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        map<char,char> mp;
        mp['('] = ')';
        mp['['] = ']';
        mp['{'] = '}';
        for(auto x:s){
            if(x =='(' || x=='[' || x=='{'){
                st.push(x);
            }
            else {
                if(st.empty()) return false;
                if(mp[st.top()] != x){
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};
int main(){
    string s;
    cin>>s;
    Solution sol;
    if(sol.isValid(s)){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    return 0;
}