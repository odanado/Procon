#include<stdio.h>
/*strlen(str) に必要*/
#include<string.h>

int main(void) {
  /*文字列は大きめに取ること(末尾に\0が挿入される)*/
  char str[10005];

  int i;
  int joi,ioi;
  int length;
  joi = 0;
  ioi = 0;
  
  scanf("%s",str); 

  length = strlen(str);

  for(i=0; i<length-2; i++) {
    if(str[i] == 'J' && str[i+1] == 'O' && str[i+2] == 'I')
      joi++;
    if(str[i] == 'I' && str[i+1] == 'O' && str[i+2] == 'I')
      ioi++;
  }

  printf("%d\n%d\n",joi,ioi);

  return 0;
}
