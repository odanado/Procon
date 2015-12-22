#include <algorithm>
#include <functional>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <climits>

#define all(c) (c).begin(), (c).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fr first
#define sc second

const int INF=100000000;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
using namespace std;
typedef pair<int ,int > P;
typedef long long ll;

int a[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool ok(int y,int m,int d) {
    double t1;
    int t2;
    t1=y;
    t1=t1/m/d;
    t2=y;
    t2=t2/m/d;

    return t1==(double)t2;
}
int main() {
    int y,m,d;
    scanf("%d/%d/%d",&y,&m,&d);
    if((y%4==0&&y%100!=0)||y%400==0) a[2]++;
    for(int dd=d;dd<=a[m];dd++) if(ok(y,m,dd)) {
        printf("%d/%02d/%02d\n",y,m,dd);
        return 0;
    }
    m++;
    for(int mm=m;mm<=12;mm++) for(int dd=1;dd<=a[mm];dd++) {
        if(ok(y,mm,dd)) {
            printf("%d/%02d/%02d\n",y,mm,dd);
            return 0;
        }
    }
    printf("%d/01/01\n",y+1);
    return 0;
}

