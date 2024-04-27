#include <stdio.h>

int bfs();                          // 너비 우선 탐색

int dx[4] = { -1, 1, 0, 0 };        // 상하좌우 이동
int dy[4] = { 0, 0, -1, 1 };        // 상하좌우 이동
int n = 0;                          // 세로 미로 크기
int m = 0;                          // 가로미로 크기
int graph[101][101] = { 0, };       // 미로 저장
int que[10001][2] = { 0, };         // 현재 방문한 좌표(x, y) 저장
int ans = 0;                        // 답변 저장

int main()
{
    // 세로열, 가로열 값 입력
    scanf("%d %d", &n, &m);

    // 한칸씩 읽어오기
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%1d", &graph[i][j]);
        } // End of for()
    } // End of for()

    // 너비 우선 탐색
    ans = bfs();

    // 결과 출력
    printf("%d", ans);

    return 0;
} // End of main()

// 너비 우선 탐색
int bfs() {
    // 큐 front, rear
    int front = 0;
    int rear = 0;

    // 큐에 시작점 좌표 삽입
    que[front][0] = 1;
    que[front][1] = 1;
    rear++;

    // 큐가 빌 때 까지
    while (front < rear) {
        int x = que[front][0];  // x 좌표
        int y = que[front][1];  // y 좌표 
        front++;                // front 이동

        // 상하좌우 이동(인접칸)
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 범위를 벗어나는 경우
            if (nx < 1 || ny < 1 || nx > n || ny > m) {
                continue;
            } // End of if()

            // 길이 아닌 경우
            if (graph[nx][ny] != 1) {
                continue;
            } // End of if()

            // 이전 칸에서 이동한 칸 수 + 1
            graph[nx][ny] = graph[x][y] + 1;

            que[rear][0] = nx;
            que[rear][1] = ny;
            rear++;
        } // End of for()
    } // End of while()

    return graph[n][m];
} // End of bfs()
