#include <stdio.h>
#include <string.h>

int i_n = 0;			// 입력받을 N값 정의 및 초기화
int i_k = 0;			// 입력받을 K값 정의 및 초기화
int arr[5000] = { 0 };	// 배열 arr[5000] 정의 및 초기화

int main(void)
{
	int i = 0;
	int j = 1;
	int cnt = 0;

	scanf("%d %d", &i_n, &i_k);	// N, K 입력값

	// 1<=K<=N<=5000 조건이 맞지 않을 경우 다시 입력
	if (i_k < 1 || i_n < i_k || 5000 < i_n) {
		scanf("%d %d", &i_n, &i_k);	// N, K 입력값
	} // End of if()

	// 출력 <
	printf("<");

	// 요세푸스 순열
	for(i = 0; i < i_n; i++){
		cnt = 0;

		while (1) {
			if (arr[j] == 0) {
				cnt++;
			} // End of if()

			if (cnt == i_k) {
				arr[j] = -1;
				
				if (i == i_n - 1) {
					printf("%d>", j);
				}
				else {
					printf("%d, ", j);
				}
				break;

			} // End of if()

			j++;
			if (j > i_n) {
				j = 1;
			} // End of if()
		} // End of while()
	} // End of while()

	return 0;
} // End of main()
