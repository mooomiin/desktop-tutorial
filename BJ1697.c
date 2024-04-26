#include <stdio.h>

void bfs(int su_p, int br_p);		// 너비 우선 탐색

int n = 0;							// 수빈이 점
int k = 0;							// 동생 점
int map[100001] = { 0, };			// 지도 위치 배열
int que[200002] = { 0, };			// 큐 위치 배열
int start = 0;						// 시작점
int last = 0;						// 끝점
int pos = 0;						// 움직이는 위치값

int main(void)
{
	// 수빈이, 동생 점 입력
	scanf("%d %d", &n, &k);

	// 수빈과 동생 값이 같으면 리턴
	if (n == k) {
		printf("0\n");
		return 0;
	} // End of if()

	// 너비 우선 탐색
	bfs(n, k);

	// 연결 요소의 개수 출력
	printf("%d\n", map[k]);

	return 0;
} // End of main()

// 너비 우선 탐색
void bfs(int su_p, int br_p) {
	que[last++] = su_p;

	// 동생과 만날때 까지
	while (start < last && map[br_p] == 0) {
		pos = que[start++];

		// 수빈이 있는 위치 - 1 위치에 안가봤으면
		if (0 <= pos - 1 && map[pos - 1] == 0) {
			que[last++] = pos - 1;
			map[pos - 1] = map[pos] + 1;
		} // End of if()

		// 수빈이 있는 위치 + 1 위치에 안가봤으면
		if (pos + 1 <= 100000 && map[pos + 1] == 0) {
			que[last++] = pos + 1;
			map[pos + 1] = map[pos] + 1;
		} // End of if()

		// 수빈이 있는 위치 * 2 위치에 안가봤으면
		if (pos * 2 <= 100000 && map[pos * 2] == 0) {
			que[last++] = pos * 2;
			map[pos * 2] = map[pos] + 1;
		} // End of if()
	} // End of while()
} // End of dfs()
