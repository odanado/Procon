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

class EllysNumberGuessing {
    public:
        int getNumber(vector <int> guesses, vector <int> answers) {
            if(guesses.size() == 1) {
                int plus = guesses[0] + answers[0];
                int minus = abs(guesses[0] - answers[0]);

                //if(1 <= plus && plus <= 1000000001) return -1;
                //if(1 <= minus && minus <= 1000000001) return -1;
                if(minus <= 0) return plus;
                if(plus >= 1000000000) return minus; 
                return -1;

            }
            
            long long ans = -2;
            long long n = guesses.size();
            int ans1;
            int ans2;

            int tmp[] = {guesses[0]+answers[0],guesses[0]-answers[0]};

            rep(i,2) {
                bool flag=true;
                for(int j=1;j<guesses.size();j++) {
                    if(abs(tmp[i]-guesses[j])!=answers[j]) {
                        flag=false;
                    }
                }
                if(1<=tmp[i]&&tmp[i]<=1000000000 && flag) {
                    if(ans!=-2)
                        ans=-1;
                    else 
                        ans=tmp[i];

                }

            }


            return ans;
        }


};

int main()
{
    return 0;
}


