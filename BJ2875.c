#include<stdio.h>

int n = 0;          // 여학생 수
int m = 0;          // 남학생 수
int k = 0;          // 인턴쉽에 참여해야하는 수

int main()
{
    scanf("%d %d %d", &n, &m, &k);

    int max = n / 2;

    if (max > m) {
        max = m;
    }
    else {
        max = n / 2;
    } // End of if()

    k = k - (n + m) - (3 * max);

    if (k > 0) {
        k--;
        max = max - (k / 3) + 1;
    } // End of if()

    printf("%d", max);
    return 0;
} // End of main()
