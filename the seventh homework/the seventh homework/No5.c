#include<stdio.h>
#include<stdlib.h>
//5.递归和非递归分别实现strlen
int Strlen(char* string){

	if ('\0' == *(string)){
		return 0;
	}
	return 1+Strlen(string+1);
}
int Strlen1(char* string){
	int i;
	for (i = 0; string[i]; i++);

	return i;
}
int main(){
	char str[] = "abcde";
	printf("%d\n", Strlen(str));
	printf("%d\n", Strlen1(str));
	system("pause");
	return 0;
}