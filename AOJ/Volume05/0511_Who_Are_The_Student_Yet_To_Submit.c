#include<stdio.h>

int main(void) {

	int i;
	int flag[31];
	int n;

	/*配列の初期化*/
	for(i=0; i<31; i++) {
		flag[i] = 0;
	}

	/*提出をしている生徒番号の場所に1を代入する*/
	for(i=0; i<28; i++) {
		scanf("%d",&n);
		flag[n] = 1;
	}

	/*生徒番号の場所が0ならば提出をしていない番号*/
	for(i=1; i<31; i++) {
		if(flag[i] == 0) {
			printf("%d\n",i);
		}
	}



	return 0;
}
