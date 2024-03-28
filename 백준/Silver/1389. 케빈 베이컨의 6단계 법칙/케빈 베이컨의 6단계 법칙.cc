#include <iostream>
#include <vector>
#include <algorithm>
#include <queue> 
#include <cstring> 
#define INF 1e9 
#define MAX 101 
using namespace std; 

int n, m;
int graph[MAX][MAX]; // a에서 b로 가는 경로가 있으면 1, 없으면 0 
int paths[MAX];  // i에서 다른 모든 노드까지의 경로 길이 저장 
int bacons[MAX]; // 각 사람에 대한 케빈 베이컨 수 저장 
bool visited[MAX]; 

void bfs(int start){
	queue<int> q;
	q.push(start);
	visited[start] = true;

	while(!q.empty()){
		int i = q.front(); 
		q.pop();

		for(int j = 1; j <= n; j++){
			// i에서 j로 가는 경로가 있는데 아직 방문하지 않은 경우 
			if(graph[i][j] == 1 && !visited[j]){
				// 방문 처리 
				visited[j] = true;
				q.push(j);

				// i에서 j까지 가는 최단 거리 갱신 
				paths[j] = paths[i] + 1; 
			}
		}
	}
}

int getMinPerson(){
	int minBacon = bacons[1]; // 최소 케빈 베이컨 수  
	int answer = 1; // 최소 케빈 베이컨 수를 갖는 사람 번호 

	for(int i = 2; i <= n; i++){ 
		if(minBacon > bacons[i]){ 
			minBacon = bacons[i]; 
			answer = i; 
		}
	}

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		graph[x][y] = graph[y][x] = 1; 
	}

	for(int i = 1; i <= n; i++){
		bfs(i);

		// i에서 다른 모든 노드 j까지의 최단 거리를 모두 더하여 
		// 각 사람에 대한 케빈 베이컨 수 구하기 
		for(int j = 1; j <= n; j++){
			if(i == j) continue;
			bacons[i] += paths[j]; 
		}

		// 각 사람에 대한 데이터 초기화 
		fill(visited, visited + MAX, 0);
		fill(paths, paths + MAX, 0);
	}

	// 최소 케빈 베이컨 수를 갖는 사람의 번호 출력 
	cout << getMinPerson(); 

	return 0;
} 