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

class ListeningSongs {
public:
    int listen(vector <int> durations1, vector <int> durations2, int minutes, int T) {
        if(durations1.size() < T) return -1;
        if(durations2.size() < T) return -1;
        int sec = minutes * 60;
        sort(all(durations1));
        sort(all(durations2));
        int sum = 0, ans=0;

        rep(i,T) sum+=durations1[i];
        rep(i,T) sum+=durations2[i];
        if(sum > sec) return -1;
        ans+=T+T;
        vector<int> vec;
        rep(i,durations1.size()) if(i>=T) vec.pb(durations1[i]);
        rep(i,durations2.size()) if(i>=T) vec.pb(durations2[i]);
        sort(all(vec));
        rep(i,vec.size()) {
            if(sum+vec[i]>sec) {
                break;
            }
            sum+=vec[i];
            ans++;
        }

        return ans;

    }
};

int main() {
    return 0;
}

