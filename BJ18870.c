#include <stdio.h>
#include <stdlib.h>		// 동적 배열 헤더파일

int compare(const void* a, const* b);			// 배열의 오름차순을 위한 함수
int unique(int* arr, int size);					// 중복 요소 제거 함수
int binarysearch(int* arr, int size, int key);	// 이진 탐색 함수

int main(void)
{
	int input_n = 0;		// 입력 받을 N 값 정의 및 초기화
	scanf("%d", &input_n);

	// 입력받은 N 만큼의 함수값, 정렬 배열 정의
	// 문자열을 읽어올때 문자열 끝에\0이라는 널문자가 존재하므로
	// size를 input_n에 1을 더해주어야한다.(heap corruption detected after normal block #78 오류 방지)
	int* func_value = (int*)calloc(input_n + 1, sizeof(int));
	int* sort_value = (int*)calloc(input_n + 1, sizeof(int));

	// 함수 입력
	for (int i = 0; i < input_n; i++) {
		scanf("%d", &func_value[i]);
		sort_value[i] = func_value[i];
	} // End of for()

	// qsort 배열을 정렬하는 함수
	// compare 오름차순 정렬을 위함
	qsort(sort_value, input_n, sizeof(int), compare);

	int cnt = unique(sort_value, input_n);

	// 출력
	for (int i = 0; i < input_n; i++) {
		int tmp = binarysearch(sort_value, cnt, func_value[i]);
		printf("%d ", tmp);
	} // End of for()

	// 할당한 메모리 해제
	free(func_value);
	free(sort_value);

	return 0;
} // End of main()

// 배열의 오름차순을 위한 함수
int compare(const void* a, const* b) {
	return *(int*)a - *(int*)b;
} // End of compare()

// 중복 요소 제거 함수
int unique(int* arr, int size) {
	int cnt = 0;
	for (int i = 0; i < size; i++) {
		if (arr[cnt] == arr[i]) {
			continue;
		} // End of if()

		arr[++cnt] = arr[i];
	} // End of for()
	return ++cnt;
} // End of unique()

// 이진 탐색 함수
int binarysearch(int* arr, int size, int key) {
	int left = 0;
	int right = size - 1;
	int mid = 0;

	while (left <= right) {
		mid = (left + right) / 2;
		if (arr[mid] < key) {
			left = mid + 1;
		}
		else if (arr[mid] > key) {
			right = mid - 1;
		}
		else {
			return mid;
		} // End of if()
	} // End of while()
} // End of binarysearch()
