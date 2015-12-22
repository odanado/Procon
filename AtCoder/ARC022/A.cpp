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


string str;

int find(int s,char c) {
    for(int i=s;i<str.size();i++) {
        if(c==str[i]) return i;
    }
    return INF;
}

int main() {
    cin>>str;
    int a = min(find(0,'i'),find(0,'I'));
    if(a==INF) {
        cout<<"NO"<<endl;
        return 0;
    }

    a = min(find(a+1,'c'),find(a+1,'C'));
    if(a==INF) {
        cout<<"NO"<<endl;
        return 0;
    }
    a = min(find(a+1,'t'),find(a+1,'T'));
    if(a==INF) {
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    

    return 0;
}

/* 2014/05/03 AC */

