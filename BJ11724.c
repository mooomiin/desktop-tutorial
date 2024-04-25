#include <stdio.h>
#include <stdlib.h>

void dfs(int chk);					// 깊이 우선 탐색

int n_cnt = 0;						// 정점의 개수 n
int m_cnt = 0;						// 간선의 개수 m
int u_point = 0;					// 간선의 끝점 u
int v_point = 0;					// 간선의 끝점 v
int p_graph[1001][1001] = { 0, };	// 정점에 대한 그래프
int v_graph[1001] = { 0, };			// 방문한 정점에 대한 그래프
int con_cnt = 0;					// 연결 요소의 개수
		
int main(void)
{
	// 테스트 케이스 개수 입력
	scanf("%d %d", &n_cnt, &m_cnt);

	// 간선을 배열에 입력
	for (int i = 1; i <= m_cnt; i++) {
		scanf("%d %d", &u_point, &v_point);

		// 각 점끼리 연결
		p_graph[u_point][v_point] = 1;
		p_graph[v_point][u_point] = 1;
	} // End of for()

	// 깊이 우선 탐색
	for (int i = 1; i <= n_cnt; i++) {
		if (v_graph[i] == 0) {
			dfs(i);
			con_cnt++;
		} // End of if()
	} // End of for()

	// 연결 요소의 개수 출력
	printf("%d", con_cnt);

	return 0;
} // End of main()

// 깊이 우선 탐색
void dfs(int chk) {
	// 확인을 위한 flag
	v_graph[chk] = 1;

	// 값이 같은지를 확인
	for (int i = 1; i <= n_cnt; i++) {
		if (p_graph[chk][i] == 1 && v_graph[i] == 0) {
			dfs(i);
		} // End of if()
	} // End of for()
} // End of dfs()
