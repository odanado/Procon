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

class Target {
public:
    vector <string> draw(int n) {
        vector<string> vec;
        int a = 0;
        char c = '#';
        rep(i,n/2+1) {
            
            string s;
            int x=i/2*2+1;
            if(i==n/2){
                x = n/2;
            }
            rep(k,x) {
                if(k&1) s+=" ";
                else s+="#";
            }

            rep(j,n-2*x) {
                s+=c;
            }
            rep(k,x) {
                bool f = k&1;
                if(i==n/2) {
                    f=!f;
                }
                if(f) s+=" ";
                else s+="#";
            }
            if(c=='#') c=' ';
            else c='#';
            vec.pb(s);
        }
        rep(i,n/2) {
            vec.pb(vec[n/2-i]);
        }

        return vec;
    }

};
int main() {
    return 0;
}

