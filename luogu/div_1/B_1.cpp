#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin >> a >> b;
    if(8 <= a && b <= 12) cout << 'M';
    else if(13 <= a && b <= 17) cout << 'A';
    else if(18 <= a && b <= 21) cout << 'E';
    else cout << 'F';
}