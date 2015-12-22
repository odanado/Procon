#include<stdio.h>

int main(void) {

  int i;
  int h1,m1,s1;
  int h2,m2,s2;
  int sum;

  for(i=0; i<3; i++) {
    scanf("%d %d %d",&h1,&m1,&s1);
    scanf("%d %d %d",&h2,&m2,&s2);

    sum = (h2-h1)*3600 + (m2-m1)*60 + (s2-s1); 

    printf("%d ",sum/3600);
    sum %= 3600;
    printf("%d ",sum/60);
    sum %= 60;
    printf("%d\n",sum);

  }

  return 0;
}
