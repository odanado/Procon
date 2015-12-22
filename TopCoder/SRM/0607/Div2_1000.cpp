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
typedef pair<string , int> SP;
set<string> s;

class CombinationLockDiv2 {
    public:
        int minimumMoves(string S, string T) {
           queue<SP> que;
           que.push(mp(S,0));
           int ans=0;

           while(que.size()) {
               SP p = que.front();
               que.pop();

               string str = p.fr;
               if(s.find(str)!=s.end()) continue;
               cout<<str<<endl;
               s.insert(str);
               if(str == T) {
                   ans=p.sc;
                   break;
               }
               rep(i,str.size()) {
                   rep(j,str.size()+1) {
                       if(!j) continue;
                       if(j+i==str.size()+1) break;
                       
                       que.push(mp(plus(str,i,j),p.sc+1));
                       que.push(mp(minus(str,i,j),p.sc+1));

                   }
               }
           }
           return ans;
        }

        string plus(string str,int s,int t) {
            string ret = str;
            for(int i=s;i<t;i++) {
                if('0'<=ret[i] && ret[i] <='8') ret[i]+=1;
                else ret[i]='0';
            }
            return ret;
        }
        string minus(string str,int s,int t) {
            for(int i=s;i<t;i++) {
                if('1'<=str[i] && str[i] <='9') str[i]-=1;
                else str[i]='9';
            }
            return str;
        }

};

int main()
{
    return 0;
}


