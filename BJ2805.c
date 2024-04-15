#include <stdio.h>

long long total, mid, n, m, result, max = 0;

void	binary_search(long long arr[n], int left, int right)
{
	if (left > right)
		return ;
	total = 0;
	mid = (left + right) / 2;
    // mid 보다 초과된 길이 구하기
	for(int i = 0; i < n; i++)
	{
		if (arr[i] > mid)
			total += arr[i] - mid;
	}
    // 더 잘라야 할 때
	if (total < m)
		binary_search(arr, left, mid - 1);
    // 덜 자르거나 적당할 때
	else
	{
		result = mid;
		binary_search(arr, mid + 1, right);
	}
}

int main(void)
{
	scanf("%lld %lld", &n, &m);
	long long	trees[n];

	for(int i = 0; i < n; i++)
	{
		scanf("%lld", &trees[i]);
		if (max < trees[i])
			max = trees[i];
	}
	binary_search(trees, 0, max);
	printf("%lld", result);
	return (0);
}

// 출처: https://dpcks5959.tistory.com/53 [대해적시대:티스토리]
