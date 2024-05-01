#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b);

int n = 0;				// 회의의 수 n
int count = 0;

// greed 구조 정의 선언
typedef struct
{
	int x;
	int y;
} greed;

int main()
{
	greed arr[100010];

	// 회의의 수 입력
	scanf("%d", &n);

	int i = 0;
	// 회의 수만큼 반복
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &arr[i].x, &arr[i].y);
	} // End of for()

	// 정렬
	// void qsort (void *base, size_t nel, size_t width, int (*compare)(const void *, const void *);
	qsort(arr, n, sizeof(greed), compare);

	int j = 0;
	// (1, 4)는 확정, 1부터 시작
	count = 1; 

	for (int i = 1; i < n; i++) {
		if (arr[j].y <= arr[i].x) // 임의로 j잡아주고
		{
			j = i; // 조건에 만족하면 i값으로 업데이트
			count++; // 갯수 세줌
		} // End of if()
	} // End of for()

	printf("%d", count);
} // End of main()

// 시간을 비교하기 위한 함수 
int compare(const void* a, const void* b)
{
	greed A = *(greed*)a;
	greed B = *(greed*)b;

	if (A.y > B.y) {
		return 1;
	}
	else if (A.y == B.y) {
		if (A.x > B.x)
			return 1;
		else
			return -1;
	}
	else {
		return -1;
	} // End of if()
} // End of compare()
