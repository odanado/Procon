#include <stdio.h>

int main(void) {
  int sum;
  int a,i;
  scanf("%d",&sum);
  for(i=0; i<9; i++) {
    scanf("%d",&a);
    sum-=a;
  }

  printf("%d\n",sum);

  return 0;
} 
