#include <stdio.h>
#include <string.h>


int main(void)
{
	int t_cnt = 0;	// 테스트케이스의 수 정의 및 초기화
	int n_cnt = 0;	// 문서의 개수 정의 및 초기화
	int q_num = 0;	// 궁금한 큐의 번지수 정의 및 초기화
	int queue[100]; // 입력받은 큐의 개수

	scanf("%d", &t_cnt);

	// 테스트 케이스만큼 반복해서 값 입력 받기
	for (int i = 0; i < t_cnt; i++) {
		scanf("%d %d", &n_cnt, &q_num);

		// 문서 개수만큼 중요도를 반복해서 값 입력 받기
		for (int j = 0; j < n_cnt; j++) {
			scanf("%d", &queue[j]);
		} // End of for()

		int count = 1;	// 번지수+1을 해줘야 우리가 생각하는 순서이므로 1로 초기화
		int front = 0;	// 번지수 정의 및 초기화
		int max = 0;	// 최댓값 정의 및 초기화

		// 반복문을 통해서 원하는 값 찾기
		while (1) {
			// 문서 개수만큼 큐[번지수]의 최댓값 찾기
			for (int k = 0; k < n_cnt; k++) {
				if (queue[k] > max) {
					max = queue[k];
				} // End of if()
			} // End of for()

			// queue[번지수]가 max와 같지 않을때 번지수 값을 1씩 증가
			while (queue[front] != max) {
				front = (front + 1) % n_cnt;
			} // End of while()

			// 궁금한 문서와 번지수가 같을때 while문을 탈출
			if (front == q_num) {
				break;
			} // End of if()

			// 번지수가 다를 경우 큐값 초기화후 재반복
			queue[front] = 0;				// queue[번지수] 초기화
			front = (front + 1) % n_cnt;	// 번지수 값에 1씩 증가
			max = 0;						// 최댓값 초기화
			count++;						// count 증가
		} // End of while()

		// 몇 번째로 인쇄되는지 출력
		printf("%d\n", count);
	} // End of for()

	return 0;
} // End of main()
