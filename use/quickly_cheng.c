#include<stdio.h>

int q(int base,int n){
    int ans=1;
    while(n>0){
        if(n%2 == 1) ans *= base; 
        base *= base;
        n /= 2;
    }
    return ans;
}

int main(){
    int base,num;
    scanf("%d %d",&num,&base);
    printf("%d",q(base,num));
}
/*#include <stdio.h>

long long quick(long long a, long long n){
    if(n == 0) return 1;

    long long half = quick(a, n / 2);

    if(n % 2 == 0)
        return half * half;
    else
        return half * half * a;
}

int main(){
    long long a, n;
    scanf("%lld %lld", &a, &n);
    printf("%lld\n", quick(a, n));
    return 0;
}*/