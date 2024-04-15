#include <stdio.h>
#include <string.h>

int tree_arr[1000000];	// 입력 받을 나무의 길이에 대한 배열 정의


int main(void)
{
	int t_cnt = 0;			// 나무의 수 정의 및 초기화
	int sht_leng = 0;		// 상근이가 집으로 가져가려고 하는 나무의 길이 정의 및 초기화
	//int tree_arr[1000000];	// 입력 받을 나무의 길이에 대한 배열 정의
	int max = 0;			// max 값 정의 및 초기화
	int max_leng = 0;		// 설정할 수 있는 높이의 최대값 정의 및 초기화

	// 나무의 수와 상근이가 집으로 가져가려는 나무의 길이 입력받기
	scanf("%d %d", &t_cnt, &sht_leng);

	// tree_arr[i] 초기화
	//for (int i = 0; i < sizeof(tree_arr); i++) {
	//	tree_arr[i] = 0;
	//} // End of for()

	// 입력한 나무의 수만큼 나무 길이 입력 받기
	for (int i = 0; i < t_cnt; i++) {
		scanf("%d", &tree_arr[i]);

		// max값 찾기
		if (max < tree_arr[i]) {
			max = tree_arr[i];
		} // End of if()
	} // End of for()

	int left = 0;		// 왼쪽으로 보낼 기준값
	int right = max;	// 오른쪽으로 보낼 기준값

	// 입력 받은 값 정렬
	while (left <= right) {
		int mid = (left + right) / 2;	// 중앙값 정의 및 값 넣기
		int sum = 0;					// 배열값 - 중앙값의 합

		for (int i = 0; i < t_cnt; i++) {
			// 중앙값이 배열값보다 작으면 더해주기
			if (mid < tree_arr[i]) {
				sum += tree_arr[i] - mid;
			} // End of if()
		} // End of for()
		
		// 합이 가져가려는 나무 길이보다 커지거나 같으면
		if (sum >= sht_leng) {
			// 중앙값보다 구하려는 값이 작으면 구하는 값은 중앙값이된다.
			if (max_leng < mid) {
				max_leng = mid;
			} // End of if()

			left = mid + 1;
		}
		else {
			right = mid - 1;
		} // End of if
	} // End of while()

	// 결과값 출력
	printf("%d", max_leng);

	return 0;
} // End of main()
