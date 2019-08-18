// MST+思维

#include <bits/stdc++.h>
int f[100001], n, m, sum, x, y, ans, cnt;
struct Edge { int u, v, w; } e[200001];
int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }
int main() {
    while(std::cin >> n >> m) {
        ans = sum = cnt = 0;
        for(int i = 0; i < n; i++)  std::cin >> x >> y;
        for(int i = 0; i < m; i++) {
            std::cin >> e[i].u >> e[i].v >> e[i].w;
            sum += e[i].w;
        }
        for(int i = 1; i <= n; i++) f[i] = i;
        std::sort(e, e+m, [](Edge a, Edge b)->bool{ return a.w > b.w; });
        for(int i = 0; i < m; i++)
            if(find(e[i].u) != find(e[i].v))
                cnt++, ans += e[i].w, f[find(e[i].u)] = find(e[i].v);
        std::cout << m-cnt << ' ' << sum-ans << std::endl;
    }
}