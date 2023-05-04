#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;
#define INF 100001

struct Data {
	int n, w;
	Data() {};
	Data(int n, int w) :n(n), w(w) {};

	bool operator<(const Data d) const {
		return w > d.w;
	}
};

int N, X, M;
int u, v, w;
vector<Data> road[1001];
priority_queue<Data> pq;
int dist[1001];
bool isVisited[1001];
int cal[1001] = { 0 };

void init() {
	for (int i = 0; i <= N; i++) {
		road[i].clear();
		dist[i] = INF;
		isVisited[i] = false;
	}
	priority_queue<Data> new_pq;
	swap(pq, new_pq);
}

void init_i() {
	for (int i = 0; i <= N; i++) {
		dist[i] = INF;
		isVisited[i] = false;
	}
	priority_queue <Data> new_pq;
	swap(pq, new_pq);
}

int main(int argv, char** argc) {
	scanf("%d %d %d", &N, &M, &X);
	init();

	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &u, &v, &w);
		road[u].push_back(Data(v, w));
	}

	for (int i = 1; i <= N; i++) {
		if (i == X) continue;
		int h = 0;

		init_i();
		pq.push(Data(i, 0));
		dist[i] = 0;

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
					if (next.n != X)
						pq.push(Data(next.n, dist[next.n]));
				}
				if (next.n == X) break;
			}
		}
		h = 0;
		h = dist[X];
		// 만약 dist[X]가 INF 라면???






		init_i();
		pq.push(Data(X, 0));
		dist[X] = 0;

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
					if (next.n != i)
						pq.push(Data(next.n, dist[next.n]));
				}
				if (next.n == i) break;
			}
		}
		h += dist[i];
		// 만약 dist[X]가 INF 라면???
		cal[i] = h;
	}
	
	sort(cal + 1, cal + N + 1, greater<>());
	
	printf("%d\n", cal[1]); // 최대값 추출
}
