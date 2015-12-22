#include<stdio.h>

int main(void) {

  int w,k;
  /*一番目に大きい点数*/
  int max1 = 0;
  /*二番目に大きい点数*/
  int max2 = 0;
  /*三番目に大きい点数*/
  int max3 = 0;
  int i;
  
  for(i=0; i<10; i++) {
    scanf("%d",&w);
    if(max1 <= w) {
      max3 = max2;
      max2 = max1;
      max1 = w;
    }
    else if(max2 <= w) {
      max3 = max2;
      max2 = w;
    }
    else if(max3 <= w) {
      max3 = w;
    }

  }
  printf("%d ",max1+max2+max3);

  /*初期化*/
  max1 = max2 = max3 = 0;
  for(i=0; i<10; i++) {
    scanf("%d",&k);
    if(max1 <= k) {
      max3 = max2;
      max2 = max1;
      max1 = k;
    }
    else if(max2 <= k) {
      max3 = max2;
      max2 = k;
    }
    else if(max3 <= k) {
      max3 = k;
    }

  }
  printf("%d\n",max1+max2+max3);

  return 0;
}
