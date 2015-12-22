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
#include <cassert>

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
typedef long long ll;
typedef pair<ll ,ll > P;

int N;
ll S[100005],C[100005];
void print(vector<P> vec) {
    printf("print\n");
    rep(i,vec.size()) cout<<vec[i].fr<<", "<<vec[i].sc<<endl;
}
int main() {
    // [,]
    vector<P> ranges;
    cin>>N;
    rep(i,N) cin>>S[i]>>C[i];
    ranges.push_back(P(S[0],S[0]+C[0]-1));
    cout<<S[0]+C[0]-1<<endl;

    rep(i,N) if(i) {
        //printf("[input] %d %d\n",S[i],S[i]+C[i]-1);
        //print(ranges);
        P p1=P(S[i],S[i]+C[i]-1);
        auto it = find_if(all(ranges),[p1](P p2) {
                return !(p1.sc<p2.fr||p2.sc<p1.fr);
                });

        if(ranges.end() == it) {
            //cout<<"not "<<endl;
            ranges.push_back(P(S[i],S[i]+C[i]-1));
            cout<<S[i]+C[i]-1<<endl;
        }
        else {
            P p2=*it;
            ranges.erase(it);
            if(p1.fr<=p2.fr) {
                //cout<<"case 1"<<endl;
                int d=p2.fr-p1.fr;
                ranges.push_back(P(p1.fr,p2.sc-d+C[i]));
                cout<<p2.sc-d+C[i]<<endl;
            }
            else if(p2.fr<=p1.fr) {
                //cout<<"case 2"<<endl;
                ranges.push_back(P(p2.fr,p2.sc+C[i]));
                cout<<p2.sc+C[i]<<endl;
            }
            else {
                //cout<<"????"<<endl;
            }
        }
        sort(all(ranges));

        auto it1 = ranges.begin();
        auto it2=it1;
        ++it2;
        while(1) {
            if(it2==ranges.end()) break;
            P p1=*it1;
            P p2=*it2;
            if(p1.sc+1==p2.fr) {
                it1=ranges.erase(it1);
                //printf("merge (%d,%d)->(%d,%d): %d %d\n",p1.fr,p1.sc,p2.fr,p2.sc,p1.fr,p2.sc);
                it1=ranges.erase(it1);
                ranges.push_back(P(p1.fr,p2.sc));
            }
            else {
                ++it1;
                ++it2;
            }
        }
    }


    return 0;
}

