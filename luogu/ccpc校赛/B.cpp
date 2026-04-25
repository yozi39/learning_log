#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;
    int pan[n+5][m+5];
    for(int i=1;i<=n;i++){
        for(int j =1;j<=m;j++){
            cin>>pan[i][j];
        }
    }
    int q;
    cin>>q;
    int r[q+5],t[q+5],h[q+5];
    for(int i=1;i<=q;i++){
        cin>>r[i]>>t[i]>>h[i];
    }
    int cnt=0;
    int dead=0;
    int hp[q+5],locate[q+5],alive[q+5];
    memset(alive, 0, sizeof(alive));
    memset(hp, 0, sizeof(hp));
    memset(locate, 0, sizeof(locate));
    int plant[n+5];//不变成O(n*m*cnt) 防止TLE
    memset(plant,0,sizeof(plant));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(pan[i][j] == 1)plant[i]++;
        }
    }
    while(true){
        cnt++;
        bool lose=false;
        //part 1. 僵尸出现
        for(int i=1;i<=q;i++){
            if(t[i]==cnt){
                alive[i] = 1;
                hp[i] = h[i];
                locate[i] = m+1;
            }
        }
        //part 2. saki,移动
        for(int i=1;i<=q;i++){
            if(alive[i] == 1){
                locate[i]--;
                if(locate[i] <= 0)lose=true;
            }
        }
        //part 3. 伤害判定
        int leftz[n+5];
        memset(leftz,0,sizeof(leftz));
        for(int i=1;i<=q;i++){
            if(alive[i]==1){
                int row=r[i];
                if(leftz[row] == 0 || locate[i]<locate[leftz[row]]){//找最左边僵尸, == 0用来初始化后面用来更新
                    leftz[row]=i;
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(leftz[i] != 0){
                hp[leftz[i]] -= plant[i];
            }    
        }
        //part 4. 死亡判断
        for(int i=1;i<=q;i++){
            if(hp[i]<=0 && alive[i] == 1/*要判断是不是活得再修改*/){
                dead++;
                alive[i]=0;
            }
        }
        //part 5 肘开
        for(int i=1;i<=q;i++){
            if(alive[i] == 0)
                continue;
            int row=r[i];
            int col=locate[i];
            if(col<1 || col>m)
                continue;
            if(pan[row][col] == 0)
                continue;   
            int L = col;
            while(L > 1 && pan[row][L - 1] == 1){
                L--;
            }
            // 先清空这一段
            for(int j = L; j <= col; j++){
                pan[row][j] = 0;
            }
            // 如果最左边会被推出边界，就死一个植物
            if(L == 1){
                plant[row]--;
            }
            // 再把剩下的植物整体左移一格
            for(int j = max(1, L - 1); j <= col - 1; j++){
                pan[row][j] = 1;
            }
        }
        //终局判断
        if(lose){
            cout<<cnt<<"\n";
            cout<<"Zombies eat your brain!";
            return 0;
        }
        else if(dead==q){
            cout<<cnt<<"\n";
            cout<<"You eat the zombie's brain!";
            return 0;
        }
    }
}