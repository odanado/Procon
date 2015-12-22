#include<stdio.h>

int solve(int m) {

}

int main(void) {
  int m,n;

  int result = 0;
  int tmp = 0;
  int array[5] = {500,100,50,10,5};
  int i;

  scanf("%d",&n);

  m = 1000 - n;

  for(i=0; i<5; i++) {
    tmp = m / array[i];
    m -= tmp * array[i];
    result += tmp;
  }

  printf("%d\n",result + m);

  return 0;
}
