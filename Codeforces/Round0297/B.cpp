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

int a[200005];
int m;
void func(string line) {
    rep(i,m) reverse(line.begin()+a[i]-1,line.begin()+(line.size()-a[i]+1));
    cout<<line<<endl;
}
string line;
int sum[200005];

int main() {
    cin>>line;
    cin>>m;
    int n=line.size();
    rep(i,m) cin>>a[i];
    // func(line);
    rep(i,m) {
        sum[a[i]-1]++;
        sum[line.size()-a[i]+1]--;
    }
    rep(i,n) if(i) sum[i]+=sum[i-1];
    rep(i,n/2) {
        if(sum[i]%2==1) swap(line[i],line[n-i-1]);
    }
    cout<<line<<endl;

    return 0;
}

