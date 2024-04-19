#include <stdio.h>
#include <stdlib.h>		// 동적 배열 헤더파일

int compare(const void* a, const void* b);      // 배열의 오름차순을 위한 함수
int binarySearch(int a[], int n, int key);      // 이진 탐색 함수

int main(void)
{
    int n = 0;          // 숫자 카드의 개수
    int* cards;         // 숫자 카드에 적혀있는 정수
    int m = 0;          // 숫자 카드인지 구해야할 정수
    int to_find = 0;    // 몇개 가지고 있는지의 정수

    // 숫자 카드 n개
    scanf("%d", &n);

    // 동적 배열 초기화
    cards = malloc(sizeof(int) * n);

    // 숫자 카드 입력
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &cards[i]);
    }// End of for()

    // 배열 오름차순 정렬
    qsort(cards, n, sizeof(int), compare);
    scanf("%d", &m);

	// 구해야할 정수에 따라 필요한 값 출력
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &to_find);
		printf("%d ", binarySearch(cards, n, to_find));
	} // End of for()

    // 동적 배열 메모리 해제
    free(cards);

    return 0;
} // End of main()

// 배열의 오름차순을 위한 함수
int compare(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
} // End of compare()

// 이진 탐색 함수
int binarySearch(int a[], int n, int key)
{
    int left = 0;
    int right = n;
    int mid;

    while (right > left) {
        mid = (left + right) / 2;

        // key값과 a[mid]가 같을 때는 검색범위를 왼쪽에서부터 index가 가장 큰 key값
        if (a[mid] > key) {
            right = mid;
        }
        else {
            left = mid + 1;
        } // End of if()
    } // End of while()

    int upper = right;
    left = 0;
    right = n;

    while (right > left) {
        mid = (left + right) / 2;

        // key값과 a[mid]가 같을 때는 검색범위를 오른쪽에서부터 index가 가장 작은 key값
        if (a[mid] >= key) {
            right = mid;
        }
        else {
            left = mid + 1;
        } // End of if()
    } // End of while()

    // 개수 반환
    return upper - right;
} // End of binarySearch()
