#include<algorithm>
#include<functional>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<bitset>
#include<climits>

#define all(c) (c).begin(), (c).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define FOR(itr,data) for(__typeof((data).begin()) itr=(data).begin();itr!=(data).end();++itr)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fr first
#define sc second

typedef unsigned long long UInt64;
typedef long long Int64;

const int INF=100000000;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

using namespace std;

typedef pair<int ,int > P;

int gcd(int a,int b) {
    return b ? gcd(b,a%b):a;
}

int main() {
    vector<int> vec;
    vec.pb(2);vec.pb(6);vec.pb(15);
    int x= 30;
    int a=1;
    rep(i,vec.size()) {
        if(x%vec[i]==0) {
            a=a/gcd(a,vec[i])*vec[i];
    }
    }
    cout<<a<<endl;
    return 0;
}



