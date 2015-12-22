#include<stdio.h>

int main(void) {
  int n,m;
  int a[1001];
  int b[1001];
  int c=0;
  int i;

  scanf("%d %d",&n,&m);

  for(i=0; i<n; i++) {
    scanf("%d",&a[i]);
  }

  for(i=0; i<m; i++) {
    scanf("%d",&b[i]);
  }
  for(i=0; i<m; i++) {
    c+=b[i];
    c+=a[c];
    
    if(c >= n-1) {
      printf("%d\n",i+1);
      return 0;
    }

  }

  return 0;
}
