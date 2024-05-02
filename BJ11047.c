#include<stdio.h>

int n = 0;                  // 준규가 가지고 있는 동전의 종류
int k = 0;                  // 준규가 가지고 있는 동전의 가치
int n_arr[10] = { 0, };     // 배열의 개수(1 <= n <= 10)
int cnt = 0;                // 동전 개수 세기(최솟값 찾기)

int main()
{
    // 동전 종류 개수, 가치의 합
    scanf("%d %d", &n, &k);

    for (int i = 0; i < 10; i++) {
        scanf("%d", &n_arr[i]);
    } // End of for()
    
    for (int i = n - 1; i >= 0; i--) {
        if (n_arr[i] <= k) {
            cnt += k / n_arr[i];
            k %= n_arr[i];
        }
        else if (i == 0 && k > 0) {
            cnt++;
        } // End of if()
    } // End of for()

    printf("%d", cnt);

    return 0;
} // End of main()
