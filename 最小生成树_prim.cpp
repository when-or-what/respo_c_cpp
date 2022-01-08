//最小生成树
//求最小权值之和
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 110;
const int inf = 0x3f3f3f3f;
int matr[N][N];
bool vis[N];
int dis[N];
int n, m;
int u, v, w;
void init() {
    memset(dis, 0x3f, sizeof(dis));
    memset(matr, 0x3f, sizeof(matr));
    memset(vis, false, sizeof(vis));
}
int prim(int pos) {
    int sum = 0;
    dis[pos] = 0;
    for (int i = 1; i <= n; i++) {
        int cur = -1;
        for (int j = 1; j <= n; j++) {
            if (!vis[j] && (cur == -1 || dis[j] < dis[cur])) {
                cur = j;
            }
        }
        if (dis[cur] >= inf) return inf;
        sum += dis[cur];
        vis[cur] = true;
        for (int k = 1; k <= n; k++) {
            if (!vis[k]) {
                dis[k] = min(dis[k], matr[cur][k]);
            }
        }
    }
    return sum;
}
int main(void) {
    while (~scanf("%d%d", &n, &m) && n) {
        init();
        while (m--) {
            scanf("%d%d%d", &u, &v, &w);
            matr[u][v] = min(matr[u][v], w);
            matr[v][u] = min(matr[v][u], w);
        }
        int temp = prim(1);
        if (temp >= inf) {
            puts("-1");
        } else {
            printf("%d\n", temp);
        }
    }
    return 0;
}