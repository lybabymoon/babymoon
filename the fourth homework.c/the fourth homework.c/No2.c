#include<stdio.h>
#include<stdlib.h>
  
int main2(){
	int i;
	int x, y, z;
    for (i = 100; i <= 999; i++){
		x = i % 10;   //��λ		
		y = i / 10 % 10;  //ʮλ
	 	z = i / 100;    //��λ 
		if( i == x*x*x + y*y*y + z*z*z){
			printf(" %d", i);
		}
	}
	system("pause");
	return 0;
}