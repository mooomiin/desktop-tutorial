#include <stdio.h>

int n = 0;                  // 카드의 개수
int arr[1000] = { 0, };     // 카드의 레벨 배열
int max = 0;                // 카드의 최댓값
int idx = 0;                // 골드의 최댓값 위치 저장
int sum = 0;                // 골드의 최댓값

int main()
{
    // 카드의 개수 입력받기
    scanf("%d", &n);

    // 카드 래벨 입력받고 최댓값 구하기
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        if (arr[i] > max){
            max = arr[i];
            idx = i;
        } // End of if()
    } // End of for()

    // 카드로 얻을 수 있는 골드의 최댓값 구하기
    for (int i = 0; i < n; i++){
        if (idx != i) {
            sum += arr[i] + max;
        } // End of if()
    } // End of for()

    printf("%d", sum);
    return 0;
} // End of main()
