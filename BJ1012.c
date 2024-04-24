#include <stdio.h>
#include <stdlib.h>

void dfs(int x, int y);				// 깊이 우선 탐색

int t_cnt = 0;                      // 테스트 케이스 개수
int wid_leng = 0;                   // 배추밭의 가로 길이
int hei_leng = 0;                   // 배추밭의 세로 길이
int cab_cnt = 0;                    // 배추가 심어져 있는 위치의 개수
int l_arr[51][51] = { 0 };          // 위치에 따른 배열
int v_arr[51][51] = { 0 };          // 위치에 따른 배열(방문 확인)
int worm_cnt = 0;					// 지렁이 수

int main(void)
{
	// 테스트 케이스 개수 입력
	scanf("%d", &t_cnt);

	// 배추 위치의 좌표 값
	int x = 0;
	int y = 0;

	// 배추 밭의 가로 길이, 세로 길이, 위치의 개수 입력
	for (int i = 0; i < t_cnt; i++) {
		scanf("%d %d %d", &wid_leng, &hei_leng, &cab_cnt);

		// 위치에 따른 배열 가로, 세로 길이에 따라 초기화
		worm_cnt = 0;
		for (int i = 0; i < wid_leng; i++) {
			for (int j = 0; j < hei_leng; j++) {
				l_arr[i][j] = 0;
				v_arr[i][j] = 0;
			} // End of for()
		} // End of for()

		// 위치의 개수 만큼 값 읽어와서 저장하기
		for (int k = 0; k < cab_cnt; k++) {
			scanf("%d %d", &x, &y);
			l_arr[x][y] = 1;
		} // End of for()

		// 깊이 우선 탐색 - 필요한 지렁이 수 구하기
		for (int m = 0; m < wid_leng; m++) {
			for (int n = 0; n < hei_leng; n++) {
				if (l_arr[m][n] && !v_arr[m][n]) {
					dfs(m, n);
					worm_cnt++;
				} // End of if()
			} // End of for()
		} // End of for()

		// 지렁이 수 출력
		printf("%d\n", worm_cnt);
	} // End of for()

	return 0;
} // End of main()

// 깊이 우선 탐색
void dfs(int x, int y) {
	v_arr[x][y] = 1;

	// 위
	if (l_arr[x][y + 1] == 1 && v_arr[x][y + 1] == 0) {
		dfs(x, y + 1);
	} // End of if()

	// 아래
	if (l_arr[x][y - 1] == 1 && v_arr[x][y - 1] == 0) {
		dfs(x, y - 1);
	} // End of if()

	// 좌
	if (l_arr[x - 1][y] == 1 && v_arr[x - 1][y] == 0) {
		dfs(x - 1, y);
	} // End of if()

	// 우
	if (l_arr[x + 1][y] == 1 && v_arr[x + 1][y] == 0) {
		dfs(x + 1, y);
	} // End of if()
} // End of dfs()
