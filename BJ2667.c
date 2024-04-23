#include <stdio.h>
#include <stdlib.h>

void dfs(int x, int y);                         // 깊이 우선 탐색
int compare(const void* a, const void* b);      // 오름차순 정렬

int map_size = 0;                   // 지도의 크기 N
int map_data[26][26] = { 0, };      // 집이 있는지 없는지의 배열
int visit_data[26][26] = { 0, };    // 방문했는지 확인하는 배열
int count[26*26] = { 0 };           // 단지내 집의 개수
int cnt = 0;                        // 총 단지수 count

int main(void)
{
    // 지도의 크기 N
    scanf("%d", &map_size);

    // 집이 있는지 없는지 입력
    for (int i = 1; i <= map_size; i++) {
        for (int j = 1; j <= map_size; j++) {
            scanf("%1d", &map_data[i][j]);
        }
    }

    // 깊이 우선 탐색
    for (int i = 1; i <= map_size; i++) {
        for (int j = 1; j <= map_size; j++) {
            if (map_data[i][j] == 1 && visit_data[i][j] == 0) {
                dfs(i, j);
                cnt++;
            } // End of if()
        } // End of for()
    } // End of for()

    // 오름차순 정렬
    qsort(count, cnt, sizeof(int), compare);
    
    // 총 단지수 출력
    printf("%d\n", cnt);

    // 단지내 집의 수 출력
    for (int i = 0; i < cnt; i++) {
        printf("%d\n", count[i]);
    } // End of for()
    
    return 0;
} // End of main()

// 깊이 우선 탐색
void dfs(int x, int y) {
    visit_data[x][y] = 1;
    count[cnt]++;

    // 위
    if (map_data[x][y - 1] == 1 && visit_data[x][y - 1] == 0) {
        dfs(x, y - 1);
    } // End of if()

    // 아래
    if (map_data[x][y + 1] == 1 && visit_data[x][y + 1] == 0) {
        dfs(x, y + 1);
    } // End of if()

    // 좌
    if (map_data[x - 1][y] == 1 && visit_data[x - 1][y] == 0) {
        dfs(x - 1, y);
    } // End of if()

    // 우
    if (map_data[x + 1][y] == 1 && visit_data[x + 1][y] == 0) {
        dfs(x + 1, y);
    } // End of if()

} // End of dfs()

// 오름차순 정렬
int compare(const void* a, const void* b) {
    int num1 = *(int*)a;
    int num2 = *(int*)b;

    if (num1 < num2) {
        return -1;
    }else if (num1 > num2) {
        return 1;
    } // End of if()

    return 0;
} // End of compare()
