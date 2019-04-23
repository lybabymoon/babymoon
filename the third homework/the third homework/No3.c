
#include <stdio.h>

int main3()
{
	int i = 0, count = 0;
	for (i = 0; i < 100; i++){
		if (i % 10 == 9){
			count++;
		}
		if (i / 10 == 9){
			count++;
		}
}
	printf("%d", count);
	system("pause");
	return 0;
}