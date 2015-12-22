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

int k,n;
int even,odd;
int main() {
    cin>>n>>k;
    rep(i,n) {
        int a;
        cin>>a;
        if(a&1) odd++;
        else even++;
    }
    rep(i,n-k) {
        if(i%2==0) {
            if(odd%2==0&&odd!=0) odd--;
            else even--;
        }
        else {
            if(odd%2==1||even==0) odd--;
            else even--;
        }
    }
    if(odd%2==0) {
        cout<<"Daenerys"<<endl;
    }
    else {
        cout<<"Stannis"<<endl;
    }
    return 0;
}

