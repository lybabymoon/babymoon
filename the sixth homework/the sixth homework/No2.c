#include<stdio.h>
#include<stdlib.h>
//��Ҫ�޸�
//2.ʹ�ú���ʵ���������Ľ�����
int Change(int *pa,int *pb){
	*pa = *pa + *pb;
	*pb = *pa - *pb;
	*pa = *pa - *pb;
}
int main2(){
	int a=10, b=20;
    printf("%d %d\n", Change(a, b));
    system("pause");
    return 0;
}