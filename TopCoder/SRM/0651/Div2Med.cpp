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

class FoxAndSouvenirTheNext {
public:
    int dp[51][51][51*51];
    vector<int> value;
    int sum;
    int dfs(int pos,int cnt,int s) {
        // printf("%d %d %d\n",pos,cnt,s);
        if(pos==value.size()) {
            return cnt==value.size()/2 && s==sum/2;
        }
        if((value.size()-pos)+cnt<value.size()/2) {
            return 0;
        }
        if(dp[pos][cnt][s]!=-1) return dp[pos][cnt][s];
        //*/
        int res=0;
        res |= dfs(pos+1,cnt+1,s+value[pos]);
        res |= dfs(pos+1,cnt,s);
        return dp[pos][cnt][s]=res;
    }
    string ableToSplit(vector <int> v) {
        memset(dp,-1,sizeof(dp));
        value = v;
        sum=0;
        rep(i,v.size()) sum+=v[i];
        cout<<sum<<endl;
        if(value.size()%2==0 && sum%2==0 && dfs(0,0,0)) {
            return "Possible";
        }
        else {
            return "Impossible";
        }


    }
};
int main() {
    FoxAndSouvenirTheNext obj;
    cout<<obj.ableToSplit({1,2,3,4})<<endl;

    return 0;
}

