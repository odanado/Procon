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

int N,K;
string ss;
map<string,int> data;

int main() {
    cin>>N>>K;
    cin>>ss;
    rep(i,N) {
        string s1 = ss.substr(i,K);
        sort(all(s1));
        data.insert(mp(s1,i));
    }

    rep(i,N) {
        string s1 = ss.substr(i,K);
        sort(all(s1));
        map<string,int>::iterator it = data.find(s1);
        if(it != data.end()) {
            if(!(i+K<(it->second) || (it->second+K)<=i)) continue;
           cout<<"YES"<<endl;
           return 0;
            
        }

    }


    cout<<"NO"<<endl;

    return 0;
}
