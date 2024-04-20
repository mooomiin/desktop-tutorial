#include <stdio.h>
#include <stdlib.h>		// 동적 배열 헤더파일

long long int compare(const void* a, const void* b);      // 배열의 오름차순을 위한 함수
long long int binarySearch(long long int num, long long int left, long long int right);      // 이진 탐색 함수

int n = 0;              // 첫째줄 자연수 n(1 <= n <= 100,000)
long long int* n_arr;   // 둘째줄 n개의 정수 배열(-2^31 <= n_arr <= 2^31)
int m = 0;              // 셋째줄 자연수 m(1 <= m <= 100,000)
long long int* m_arr;   // 넷째줄 m개의 정수 배열(-2^31 <= m_arr <= 2^31)

int main(void)
{
    // 첫째줄 자연수 n
    scanf("%d", &n);

    // 둘째줄 배열 초기화 입력
    n_arr = malloc(sizeof(long long int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &n_arr[i]);
    }// End of for()


    // 셋째줄 자연수 m
    scanf("%d", &m);

    // 둘째줄 배열 초기화 입력
    m_arr = malloc(sizeof(long long int) * m);
    for (int i = 0; i < m; i++)
    {
        scanf("%lld", &m_arr[i]);
    }// End of for()

    
    // 배열 오름차순 정렬
    qsort(n_arr, n, sizeof(long long int), compare);

	// 구해야할 정수에 따라 필요한 값 출력
	for (int i = 0; i < m; i++)
	{
		printf("%lld\n", binarySearch(m_arr[i], 0, n-1));
	} // End of for()

    // 동적 배열 메모리 해제
    free(n_arr);
    free(m_arr);

    return 0;
} // End of main()

// 배열의 오름차순을 위한 함수
long long int compare(const void* a, const void* b)
{
    long long int x = *(long long int*)a;
    long long int y = *(long long int*)b;

    if (x < y) {
        return -1;
    }
    else if (x > y) {
        return 1;
    }
    else {
        return 0;
    }// End of if()
} // End of compare()

// 이진 탐색 함수
long long int binarySearch(long long int num, long long int left, long long int right)
{
    if (right < left) {
        return 0;
    } // End of if()

    long long int mid = (left + right) / 2;

    if (num == n_arr[mid]) {
        return 1;
    }
    else if (num < n_arr[mid]) {
        binarySearch(num, left, mid - 1);
    }
    else {
        binarySearch(num, mid + 1, right);
    } // End of if()
} // End of binarySearch()
