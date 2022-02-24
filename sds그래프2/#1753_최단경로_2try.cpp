#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
#define INF 200001

struct Data {
	int n, w;
	Data() {};
	Data(int n, int w) :n(n), w(w) {};

	bool operator <(const Data d) const {
		return w > d.w;
	}
};

int V, E, K;
int u, v, w;
vector<Data> road[20001];
priority_queue<Data> pq;
bool isVisited[20001];
int dist[20001];

void init() {
	for (int i = 0; i <= V; i++) {
		road[i].clear();
		isVisited[i] = false;
		dist[i] = INF;
	}
	priority_queue<Data> new_pq;
	swap(pq, new_pq);
}

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

	while (true) {
		if (pq.empty()) break;
		Data d = pq.top();
		pq.pop();

		if (isVisited[d.n]) continue;
		isVisited[d.n] = true;

		for (int i = 0; i < road[d.n].size(); i++) {
			if (dist[road[d.n].at(i).n] > dist[d.n] + road[d.n].at(i).w) {
				dist[road[d.n].at(i).n] = dist[d.n] + road[d.n].at(i).w;
				pq.push(Data(road[d.n].at(i).n, dist[road[d.n].at(i).n]));
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		if (isVisited[i])
			printf("%d\n", dist[i]);
		else
			printf("INF\n");
	}
	return 0;
}
