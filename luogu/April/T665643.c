#include <stdio.h>
#define INF 4000000000000000000LL
#define LCM 2520LL

long long gcdll(long long a, long long b) {
    while (b != 0) {
        long long t = a % b;
        a = b;
        b = t;
    }
    return a;
}

long long my_min(long long a, long long b) {
    return a < b ? a : b;
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n + 1];
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    long long dp[n + 1];
    for (int i = 1; i <= n; i++) {
        dp[i] = INF;
    }
    dp[1] = 0;
    for (int i = 1; i <= n; i++) {
        if (dp[i] == INF) continue;
        for (int j = 1; j <= a[i] && i + j <= n; j++) {
            long long cost = 1LL * j * LCM / a[i];
            dp[i + j] = my_min(dp[i + j], dp[i] + cost);
        }
        for (int k = i + 1; k <= n; k++) {
            if (a[k] == a[i]) {
                dp[k] = my_min(dp[k], dp[i] + LCM);
                break;
            }
        }
    }
    long long ans = dp[n];
    long long g = gcdll(ans, LCM);
    printf("%lld %lld\n", ans / g, LCM / g);
}