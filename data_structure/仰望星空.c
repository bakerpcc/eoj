int f[105];
int d[105];
int n;

void dfs(int depth) {
	if (depth >= n) {
		for (int i = 0; i < n; ++i){


		}
		return;
	}
	for (int i = 0; i < n; ++i) {
		if (f[i] == 0) {
			d[depth] = i;
			f[i] = 1;
			dfs(depth + 1);
			f[i] = 0;
		}
	}
}

int main() {
	memset(f, 0, sizeof(f));
	dfs(0);

}




struct node{
	int x, y;
}
int mark[205][205];

int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1}

int bfs(node cur) {
	queue<node>q;
	int cnt = 0;
	q.push(cur);
	while (!q.empty()) {
		cur = q.font();
		cnt++;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			node next;
			next.x = cur.x + dir[i][0];
			next.y = cur.y + dir[i][1];
			if (next.x >= 0 && next.x < n && next.y >= 0 && next.y < m) {
				if (gra[next.x][next.y] == 1 && mark[next.x][next.y] == 0) {
					q.push(next);
					mark[next.x][next.y] = 1;
				}
			}
		}
	}
	return cnt;

}