#include <bits/stdc++.h>
using namespace std;
int r, c;
array<int, 5> Ly = {3, 0, 1, 1, 2}, Lx = {0, 2, 1, 2, 1};
array<array<int, 34>, 54> D;
int push(int x, int y, int t){
    for(; x; x--){
        if(t == 0 && (D[x][y] || D[x][y - 1] || D[x][y - 2] || D[x][y - 3])) break;
        else if(t == 1 && D[x][y]) break;
        else if(t == 2 && (D[x][y] || D[x][y - 1])) break;
        else if(t == 3 && (D[x][y] || D[x + 2][y - 1])) break;
        else if(t == 4 && (D[x][y] || D[x][y - 1] || D[x + 1][y - 2])) break;
    }
    x++;
    if(x + Lx[t] > c) return 1;
    if(t == 0) D[x][y] = D[x][y - 1] = D[x][y - 2] = D[x][y - 3] = 1;
    else if(t == 1) D[x][y] = D[x + 1][y] = D[x + 2][y] = 1;
    else if(t == 2) D[x][y] = D[x][y - 1] = D[x + 1][y] = D[x + 1][y - 1] = 1;
    else if(t == 3) D[x][y] = D[x + 1][y] = D[x + 2][y] = D[x + 2][y - 1] = 1;
    else D[x][y] = D[x][y - 1] = D[x + 1][y] = D[x + 1][y - 1] = D[x + 1][y - 2] = 1;
    return 0;
}
signed main(){
    int n, y, up = 0, sum = 0;
    char t;
    cin >> r >> c >> n;
    for(int i = 1; i <= n; i++){
        cin >> t >> y, y += 1 + Ly[t - 'A'];
        up += push(c, y, t - 'A');
    }
    for(int i = 1; i <= c; i++){
        for(int j = 1; j <= r; j++){
            sum += !D[i][j];
        }
    }
    cout << sum << " " << up << "\n";
    return 0;
}
