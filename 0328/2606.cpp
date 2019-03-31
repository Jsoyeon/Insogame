#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void bfs(int start, vector<int> adj_nodes[], bool check[]) {
	queue<int> q;

	q.push(start);
	check[start] = true;

	while (!q.empty()) {
		int temp = q.front();
		q.pop();

		for (int i = 0; i < adj_nodes[temp].size(); i++) {
			if (check[adj_nodes[temp][i]] == false) {
				q.push(adj_nodes[temp][i]);
				check[adj_nodes[temp][i]] = true;
			}
		}
	}

}


int main() {
	// n : number of vertex
	// m : number of edges
	// start : start node entry
	int n, m, start;
	cin >> n >> m;
	start = 1;

	vector<int> *adj_nodes = new vector<int>[n + 1];
	bool *check = new bool[n + 1];
	fill(check, check + n + 1, false);


	for (int i = 0; i < m; i++) {
		// u : node 1
		// v : node 2
		int u, v;
		cin >> u >> v;

		adj_nodes[u].push_back(v);
		adj_nodes[v].push_back(u);
	}

	// 노드 정렬 수행
	for (int i = 0; i <= n; i++)
		sort(adj_nodes[i].begin(), adj_nodes[i].end());

	// BFS 실행
	bfs(start, adj_nodes, check);
	
	int cnt = 0;
	for (int i = 0; i <= n; i++) {
		if (check[i] == true)
			cnt++;
	}

	if (cnt <= 0)
		cout << 0;
	else
		cout << cnt-1;


	// 메모리 해제
	delete[] adj_nodes;
	delete[] check;
}