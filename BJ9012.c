#include <stdio.h>
#include <string.h>


int main(void)
{
	int cnt = 0;	// 입력하고 싶은 값 정의, 초기화
	char str[50];   // 입력하는 괄호를 배열로 정의
	memset(str, "", sizeof(str)); // 괄호 배열 초기화

	// 입력하고 싶은 개수 입력
	scanf("%d", &cnt);

	// 입력하고 싶은 cnt 개수만큼 입력받고 출력하기
	for (int i = 0; i < cnt; i++) {
		scanf("%s", &str);
		int s_cnt = 0;

		// 입력한 괄호수만큼 배열 확인
		for (int j = 0; j < strlen(str); j++) {
			// '('이면 s_cnt 1 증가, ')'이면 s_cnt 1 감소
			if (str[j] == '(') {
				s_cnt++;
			}
			else {
				s_cnt--;
			} // End of if()

			// ')' 개수가 더 많으면 NO 출력
			if (s_cnt < 0) {
				printf("NO\n");
				break;
			} // End of if()
		} // End of for()

		// '(', ')' 괄호 개수가 동일하면 YES 출력, '(' 개수가 남으면 NO 출력
		if (s_cnt == 0) {
			printf("YES\n");
		}
		else if (s_cnt > 0) {
			printf("NO\n");
		} // End of if()
	} // End of for()

	return 0;
} // End of main()
