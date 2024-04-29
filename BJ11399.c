#include <stdio.h>

int main()
{
	int People = 0;
	int time[1000] = { 0, };
	int swap = 0;
	int Sum = 0;
	scanf("%d", &People);

	for (int i = 0; i < People; i++)
	{
		scanf("%d", &time[i]);
	} // End of for()

	// 정렬해주는 부분
	for (int i = 0; i < People; i++)
	{
		for (int j = 0; j < People-1; j++)
		{
			if (time[j] > time[j + 1])
			{
				swap = time[j];
				time[j] = time[j + 1];
				time[j + 1] = swap;
			} // End of if()
		} // End of for()
	} // End of for()

	// 앞으로 나아가며 합산
	for (int i = 0; i < People; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			Sum = Sum + time[j];
		}
		if(i == People-1){
					printf("%d", Sum);
			} // End of if()
	}// End of for()
}// End of for()
