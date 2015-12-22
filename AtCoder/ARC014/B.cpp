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

set<string> used;
int main() {
    int n;
    string s,p;
    cin>>n;
    cin>>s;
    used.insert(s);
    p=s;
    rep(i,n-1) {
        cin>>s;
        if(i%2==0) {
            if(used.count(s)) {
                cout<<"WIN"<<endl;
                return 0;
            }
            if(p[p.size()-1]!=s[0]) {
                cout<<"WIN"<<endl;
                return 0;
            }
            used.insert(s);
        }
        else {
            if(used.count(s)) {
                cout<<"LOSE"<<endl;
                return 0;
            }
            if(p[p.size()-1]!=s[0]) {
                cout<<"LOSE"<<endl;
                return 0;
            }
            used.insert(s);
        }
        p=s;
    }
    cout<<"DRAW"<<endl;
    return 0;
}

