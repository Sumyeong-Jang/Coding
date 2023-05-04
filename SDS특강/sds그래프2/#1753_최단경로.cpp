#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 200001
int V, E, K;
int u, v, w;

struct Data {
	int n, w;
	Data() {};
	Data(int n, int w) :n(n), w(w) {};

	bool operator<(const Data d)const {
		return w > d.w;
	}
};

vector<Data> road[300001];
int dist[300001];
bool isVisited[300001];
priority_queue<Data> pq;

void init() {
	for (int i = 1; i <= V; i++) {
		road[i].clear();
		dist[i] = INF;
		isVisited[i] = false;
	}
	priority_queue<Data> new_pq;
	swap(pq, new_pq);
};

int main() {
	scanf("%d %d", &V, &E);
	scanf("%d", &K);

	init();

	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &u, &v, &w);
		road[u].push_back(Data(v, w));
	}

	pq.push(Data(K, 0));
	dist[K] = 0;

	for (int i = 1; i <= V; i++) {
		while (true) {
			if (pq.empty()) break;
			Data now = pq.top();
			pq.pop();

			if (isVisited[now.n]) continue;
			isVisited[now.n] = true;

			for (int k = 0; k < road[now.n].size(); k++) {
				Data next = road[now.n].at(k);
				if (dist[next.n] > dist[now.n] + next.w) {
					dist[next.n] = dist[now.n] + next.w;
					pq.push(Data(next.n, dist[next.n]));
				}
			}

		}
		if (isVisited[i]) {
			printf("%d\n", dist[i]);
		}
		else
			printf("INF\n");
	}
	return 0;
}
