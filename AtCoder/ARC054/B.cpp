#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
using ll = long long;

#define all(c) (c).begin(), (c).end()
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fr first
#define sc second

const ll INF=1e18;
const ll MOD=1e9+7;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

double P;
double f(double x) {
    return -(x + P / pow(2.0, x/1.5));
}

int main() {
    cin>>P;
    double lb=0.0, ub=INF;
    rep(i,1000) {
        double x1 = (lb*2+ub)/3;
        double x2 = (lb+ub*2)/3;
        if(f(x1) > f(x2)) ub=x2;
        else lb=x1;
    }
    printf("%.8f\n", -f((ub+lb)/2));
    return 0;
}

