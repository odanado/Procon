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
 
class PalindromicSubstringsDiv2 {
    public:
        string S;
        int count(vector <string> S1, vector <string> S2) {
            string A,B;
            rep(i,S1.size()) A+=S1[i];
            rep(i,S2.size()) B+=S2[i];

            S = A+B;
            int ans=0;
            rep(i,S.size()) {
                ans+=count(i,i);
                ans+=count(i,i+1);
            }

            return ans;
            

        }
        int count(int l,int r) {
            int res=0;

            while(0<=l && r<S.size()) {
                if(S[l]!=S[r]) break;
                res++;
                l--;
                r++;
            }

            return res;


        }

};

int main()
{
    PalindromicSubstringsDiv2 obj;
    vector<string> vec1;
    vec1.pb("zaz");
    vector<string> vec2;
    cout<<obj.count(vec1,vec2)<<endl;;
    return 0;
}


