#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int pos = 0;
    while(s[pos] == '0'){
        pos++;
    }
    for(int i = pos; i < s.size(); i++){
        cout << s[i];
    }
    return 0;
}