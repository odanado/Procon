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

ll A,B;
int main() {
    cin>>A>>B;
    ll t1 = A/4 - A/100 + A/400;
    ll t2 = B/4 - B/100 + B/400;
    ll a = 0;


    if(A%4==0&&A%100!=0||A%400==0) a++;
    cout<<a+t2-t1<<endl;
    return 0;
}

