#include<stdio.h>

int main(void) {

	/*Aさんの点数*/
	int A1,A2,A3,A4;
	/*Bさんの点数*/
	int B1,B2,B3,B4;

	int S,T;
	S = 0;
	T = 0;

	scanf("%d %d %d %d",&A1,&A2,&A3,&A4);
	scanf("%d %d %d %d",&B1,&B2,&B3,&B4);

	/*合計を計算する*/
	S = A1 + A2 + A3 + A4;
	T = B1 + B2 + B3 + B4;

	if(T < S) {
		printf("%d\n",S);
	}
	else {
		printf("%d\n",T);
	}
	return 0;
}
