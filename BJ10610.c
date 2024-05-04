#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int compare(const void*, const void*);		// 정렬

char n[100001];

int main() {
	int sum = 0;
	int i = 0;
	scanf("%s", n);

	// 조건 - 0으로 시작하지 않는다.
	if (strchr(n, '0') == NULL || n[0] == '0') {
		printf("-1");

		return 0;
	} // End of if()

	// n값이 없을때까지 값을 넣어준다.
	while (n[i] != NULL) {
		sum += n[i] - 48;
		i++;
	} // End of while()

	// 30의 배수가 아니면 -1을 출력한다.
	if (sum % 3 != 0 || sum == 0) {
		printf("-1");

		return 0;
	}
	else {
		// qsort 정렬
		qsort(n, sizeof(n) - 1, sizeof(char), compare);
	} // End of if()

	printf("%s", n);
	return 0;
} // End of main()

// 정렬
int compare(const void* a, const void* b) {
	const char* n1 = (const char*)a;
	const char* n2 = (const char*)b;

	if (*n1 > *n2) {
		return -1;
	}
	else if (*n1 == *n2) {
		return 0;
	}
	else {
		return 1;
	} // End of if()
} // End of compare()
