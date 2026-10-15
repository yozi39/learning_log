//用递归枚举所有的数01
//提示点:区间+数位+可能给的数范围极大=数位DP(个人暴论)
//附件一
#include<bits/stdc++.h>
using namespace std;

// #define advance
#define space

const int N = 15;

int n,a[N];
#ifdef advance
//优化,记忆化搜索
int f[N][2];
#endif
#ifdef space
//优化,记忆化搜索+空间
int f[N];
#endif


int dfs(int pos,bool limit){
    if(!pos)return 1;
    #ifdef advance
    if(~f[pos][limit])return f[pos][limit];
    #endif
    #ifdef advance
    if(~f[pos] && !limit)return f[pos];
    #endif
    int up = limit? a[pos]:9;
    int ret = 0;

    for(int i =0;i<=up;i++){
        ret+=dfs(pos-1,limit && (i==a[pos]));
    }
    #ifndef advance
    return ret;
    #endif

    #ifdef advance
    return f[pos][limit] = ret;
    #endif
    #ifdef space
    if(!limit)return f[pos] = ret;
    #endif
}

int calc(int x){
    #ifdef advance
    //初始化备忘录
    memset(f,-1,sizeof f);
    #endif
    #ifdef space
    memset(f,-1,sizeof f);
    #endif
    //拆分
    while (x)
    {
        a[++n] = x%10;
        x/=10;
    }
    
    return dfs(n,1);
}

int main(){
    int x;cin>>x;
    cout<<calc(x)<<'\n';
}


/*
附件一:
    这个题目和hydro_oj jaxu里面的week4 N题目数位不减的零件箱很像

#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

string s;
LL f[20][10][2];
bool vis[20][10][2];

LL dfs(int p,int pre,int lim,int st){
    if(p==(int)s.size())return st;

    if(!lim && vis[p][pre][st])
        return f[p][pre][st];

    int up=lim?s[p]-'0':9;
    LL ret=0;

    for(int d=0;d<=up;d++){
        int nlim=lim&&(d==up);

        if(!st){
            if(d==0)
                ret+=dfs(p+1,0,nlim,0);
            else
                ret+=dfs(p+1,d,nlim,1);
        } else {
            if(d>=pre)
                ret+=dfs(p+1,d,nlim,1);
        }
    }

    if(!lim){
        vis[p][pre][st]=1;
        f[p][pre][st]=ret;
    }

    return ret;
}

int main(){
    LL n;cin>>n;
    s=to_string(n);

    cout<<dfs(0,0,1,0);
}
*/