#include <stdio.h>
#include <string.h>

int arr[10000];			// 1 <= N <= 10,000
int cnt = 0;			// 입력 순서에 따른 count

void push(int num);		// push() 함수
void pop();				// pop() 함수
void size();			// size() 함수
void empty();			// empty() 함수
void top();				// top() 함수

int main(void)
{
	int i_x = 0;		// 입력받은 X 값 정의 및 초기화
	char stack[10];		// 입력받은 char 값 정의

	char c_push[4] = "push";
	char c_pop[3] = "pop";
	char c_size[4] = "size";
	char c_empty[5] = "empty";
	char c_top[3] = "top";

	// 입력받은 정수 X
	scanf("%d", &i_x);

	// 정수 X만큼 반복해서 data를 받는다.
	for (int i = 0; i < i_x; i++) {
		memset(stack, "          ", sizeof(stack));	// 초기화
		scanf("%s", &stack);
		if (!strncmp(stack, &c_push, sizeof(c_push))) {
			int p_num = 0;
			scanf("%d", &p_num);
			push(p_num);
		}
		else if (!strncmp(stack, &c_pop, sizeof(c_pop))) {
			pop();
		}
		else if (!strncmp(stack, &c_size, sizeof(c_size))) {
			size();
		}
		else if (!strncmp(stack, &c_empty, sizeof(c_empty))) {
			empty();
		}
		else if (!strncmp(stack, &c_top, sizeof(c_top))) {
			top();
		}
	}

	return 0;
}

// push : 정수 X를 스택에 넣는 연산
void push(int p_num) {
	arr[cnt] = p_num;
	cnt++;
}

// pop : 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다.
//       만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
void pop() {
	if (cnt != 0) {
		cnt--;
		printf("%d\n", arr[cnt]);
		arr[cnt] = 0;
	}
	else {
		printf("%d\n", -1);
	}
}

// size : 스택에 들어있는 정수의 개수를 출력한다.
void size() {
	printf("%d\n", cnt);
}

// empty : 스택이 비어있으면 1, 아니면 0을 출력한다.
void empty() {
	if (cnt != 0) {
		printf("%d\n", 0);
	}
	else {
		printf("%d\n", 1);
	}
}

// top : 스택의 가장 위에 있는 정수를 출력한다.
//       만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
void top() {
	if (cnt != 0) {
		printf("%d\n", arr[cnt - 1]);
	}
	else {
		printf("%d\n", -1);
	}
}
