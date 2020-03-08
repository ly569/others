#include <stdio.h>
#include <string.h>
#define MAX_N 10

int arr[MAX_N + 5][MAX_N + 5];
int dir[8][2] = {
    {-2, 1}, {-2, -1}, {2, -1}, {2, 1},
    {-1, -2}, {-1, 2}, {1, -2}, {1, 2}
};
int ans = 0;
int T, n, m, sx, sy;

void dfs(int x, int y, int cnt) {
    if (x < 0 || x >= n || y < 0 || y >= m) return ;
    if(arr[x][y]) return ;
    if (cnt >= n * m) {
        ans += 1;
        return ;
    }
    arr[x][y] = 1;
    for (int k = 0;k < 8; k++) {
        int dx = x + dir[k][0];
        int dy = y + dir[k][1];
        dfs(dx, dy, cnt + 1);
    }
    arr[x][y] = 0;
    return ;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        memset(arr, 0, sizeof(arr));
        scanf("%d%d%d%d", &n, &m, &sx, &sy);
        int cnt = 1;
        dfs(sx, sy, cnt);
        printf("%d\n", ans);
        ans = 0;
    }
    return 0;
}