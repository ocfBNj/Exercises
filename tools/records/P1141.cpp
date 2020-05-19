#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int maxn = 1010;
int n, m, map[maxn][maxn], me[maxn][maxn];
int xx[5] = { 0,1,-1,0,0 },
yy[5] = { 0,0,0,1,-1 };
char s[maxn];
struct node {
	int x;
	int y;
}a;
struct tong {
	int x;
	int y;
}b[maxn * maxn];
bool flag[maxn][maxn];
queue<node> q;
void search(node a) {
	if (me[a.x][a.y]) {
		printf("%d\n", me[a.x][a.y]);
		return;
	}
	int cnt = 0;
	q.push(a);
	while (!q.empty()) {
		a = q.front();
		q.pop();
		for (int i = 1; i <= 4; i++) {
			node t;
			t.x = a.x + xx[i];
			t.y = a.y + yy[i];
			if (t.x >= 1 && t.x <= n && t.y >= 1 && t.y <= n && !flag[t.x][t.y] && map[a.x][a.y] + map[t.x][t.y] == 1) {
				flag[t.x][t.y] = 1;
				cnt++;
				b[cnt].x = t.x;
				b[cnt].y = t.y;
				q.push(t);
			}
		}
	}
	for (int i = 1; i <= cnt; i++)
		me[b[i].x][b[i].y] = cnt;
	if (cnt == 0) cnt++;
	printf("%d\n", cnt);
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		for (int j = 0; j < n; j++)
			map[i][j + 1] = s[j] - '0';
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &a.x, &a.y);
		search(a);
	}
	return 0;
}