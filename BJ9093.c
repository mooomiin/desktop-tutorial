#include <stdio.h>
#include <string.h>


int main(void)
{
	int t_cnt = 0;			// 테스트 케이스의 수 정의 및 초기화
	char max_word[20];		// 단어의 길이 최대 20
	char leng_str[1000];	// 문장의 길이 최대 1000
	int end = 0;

	// 테스트 케이스 수 입력
	scanf("%d", &t_cnt);

	// 버퍼에 남아있는 첫 번째 문자를 반환
	getchar();

	// 테스트 케이스만큼 반복해서 값 입력 받기
	for (int i = 0; i < t_cnt; i++) {
		// '\n'이 올때까지 문자 읽어오기
		fgets(leng_str, 1000, stdin);

		// 문장 길이만큼을 반복해서 값 입력 받기
		// 문자열 끝에 \n이 들어가므로 -1을 해준다.
		for (int j = 0; j < strlen(leng_str) - 1; j++) {
			// 띄어쓰기가 아닐 경우 max_word에 문자 저장
			if (leng_str[j] != ' ') {
				max_word[end++] = leng_str[j];
			} // End of if()

			// 띄어쓰기이거나 문장 마지막 글자일때 조건
			if (leng_str[j] == ' ' || j == strlen(leng_str) - 2) {
				// 문자를 거꾸로 출력
				for (int k = end - 1; k >= 0; k--) {
					printf("%c", max_word[k]);
				} // End of for()

				printf(" ");
				end = 0;
			} // End of if()
		} // End of for()

		printf("\n");
	} // End of for()

	return 0;
} // End of main()
