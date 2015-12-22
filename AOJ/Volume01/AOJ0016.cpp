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


int main() {
    int a,b;
    int theta = 90;
    double x=0,y=0;
    int idx = 0;
    while(~scanf("%d,%d",&a,&b)) {
        if(a==0 && b==0) break;
        y+=a*sin(theta/180.0*3.1415926535);
        x+=a*cos(theta/180.0*3.1415926535);

        theta += b;
    }
    cout<<(int)-x<<endl<<(int)y<<endl;
    return 0;
}

