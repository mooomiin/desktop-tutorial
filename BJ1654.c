#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>		// 동적 배열 헤더파일

// 동적 배열을 이용한다.
// 동적 배열을 프로그램이 실행되는 동안 메모리의 크기를 힙 메모리에 할당한다.
// 힙 영역 : 할당해야할 메모리의 크기를 프로그램이 실행되는 동안 결정해야하는 경우 사용되는 공간
// 데이터타입 *포인터변수 = (데이터타입*)malloc(sizeof(데이터타입)*배열의 크기);
// ex) int* arr = (int*)malloc(sizeof(int)*n);

int main(void)
{
	int oys_cnt = 0;	// 오영식이 이미 가지고 있는 랜선의 개수 정의 및 초기화
	int need_cnt = 0;	// 필요한 랜선의 개수 정의 및 초기화
	int lan_max = 0;	// 최대값 정의 및 초기화
	

	// 가지고 있는, 필요한 랜선의 개수 입력
	scanf("%d %d", &oys_cnt, &need_cnt);
	
	// 랜선의 길이 2^31 - 1 길이때문에 long long int type 사용
	int* lan_leng = (int*)malloc(sizeof(int)*oys_cnt);

	// 가기고 있는 랜선 개수만큼 길이 입력
	for (int i = 0; i < oys_cnt; i++) {
		scanf("%d", &lan_leng[i]);

		if (lan_leng[i] > lan_max) {
			lan_max = lan_leng[i];
		} // End of if()
	} // End of for()

	long long int min = 1;				// 최소값 정의 및 초기화
	long long int max = lan_max;		// 최대값 정의 및 초기화
	long long int mid = 0;				// 중앙값 정의 및 초기화
	long long int result = 0;			// 결과값 정의 및 초기화
	int cnt = 0;						// 필요한 개수 정의 및 초기화

	// 최소값이 최대값보다 커질때까지 반복
	while (min <= max) {
		mid = (min + max) / 2;
		cnt = 0;

		// 갖고 있는 랜선 개수만큼 반복
		for (int i = 0; i < oys_cnt; i++) {
			cnt += (lan_leng[i] / mid);

			// 필요한 개수가 같아졌을때
			if (cnt >= need_cnt) {
				// 중앙값보다 결과값이 작으면 결과값에 중앙값 넣어주기
				if (result < mid) {
					result = mid;
				}
				min = mid + 1;
			}
			else {
				max = mid - 1;
			} // End of if()
		} // End of for()
	} // End of while()

	// 결과값 출력
	printf("%lld", result);

	// 할당한 메모리 해제
	free(lan_leng);

	return 0;
} // End of main()
