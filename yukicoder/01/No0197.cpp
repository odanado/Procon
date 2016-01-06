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

string S1,S2;
ll N;
int cnt(string s) {
    int ret=0;
    rep(i,s.size()) if(s[i]=='o') ret++;
    return ret;
}

int main() {
    cin>>S1>>N>>S2;
    if(cnt(S1)!=cnt(S2)) {
        cout<<"SUCCESS"<<endl;
        return 0;
    }
    if(N==0) {
        if(S1==S2) cout<<"FAILURE"<<endl;
        else cout<<"SUCCESS"<<endl;
        return 0;
    }
    if(N>=2) {
        cout<<"FAILURE"<<endl;
        return 0;
    }

    swap(S1[0],S1[1]);
    if(S1==S2) {
        cout<<"FAILURE"<<endl;
        return 0;
    }
    swap(S1[0],S1[1]);
    swap(S1[1],S1[2]);
    if(S1==S2) {
        cout<<"FAILURE"<<endl;
        return 0;
    }
    cout<<"SUCCESS"<<endl;
    return 0;
}

