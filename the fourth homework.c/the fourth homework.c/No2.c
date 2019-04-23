#include<stdio.h>
#include<stdlib.h>
  
int main2(){
	int i;
	int x, y, z;
    for (i = 100; i <= 999; i++){
		x = i % 10;   //个位		
		y = i / 10 % 10;  //十位
	 	z = i / 100;    //百位 
		if( i == x*x*x + y*y*y + z*z*z){
			printf(" %d", i);
		}
	}
	system("pause");
	return 0;
}