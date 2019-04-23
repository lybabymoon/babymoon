#include<stdio.h>
#include<stdlib.h>
  

int main(){
	double  sum=0;
	double  temp=1;
	for (int i = 1; i <= 100; i++){
		temp = 1.0 / i*(i % 2 ? 1 : -1);
		sum  += temp;
	}
	printf("%lf\n", sum);


	system("pause");
	return 0;
}