#include <iostream>
using namespace std;
int t[55][55], ans[55][55], n, m;
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> t[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) 
            for (int a = 1; a <= n; a++)
                for (int b = 1; b <= m; b++) 
                    if (!(a==i && b==j) && t[i][j] == t[a][b]) 
                        if ((i - a) * (i - a) + (j - b) * (j - b) > ans[i][j]) 
                            ans[i][j] = (i - a) * (i - a) + (j - b) * (j - b); 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            cout << ans[i][j] << ' ';
        cout << endl;
    }
    return 0;
}


