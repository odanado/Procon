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

string s1,s2,s3;
int t1['Z'+10];
int t2['Z'+10];
int t3['Z'+10];
int main() {
    cin>>s1>>s2>>s3;
    rep(i,s1.size()) t1[s1[i]]++;
    rep(i,s2.size()) t2[s2[i]]++;
    rep(i,s3.size()) t3[s3[i]]++;
    rep(i,26) {
        if(t1[i+'A']+t2[i+'A']<t3[i+'A']) {
            cout<<"NO"<<endl;
            return 0;
        }
        if(t3[i+'A']-t2[i+'A']>t1[i+'A']) {
            cout<<"NO"<<endl;
            return 0;
        }
        if(t3[i+'A']-t1[i+'A']>t2[i+'A']) {
            cout<<"NO"<<endl;
            return 0;
        }

    }
    cout<<"YES"<<endl;


    return 0;
}

