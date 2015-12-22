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

struct Square{
    int w1,h1;
    int w2,h2;

    Square(int w1=0,int h1=0,int w2=0,int h2=0) :
        w1(w1),h1(h1),w2(w2),h2(h2){}

    bool operator<(const Square& rth) const {
        int w=abs(this->w1-this->w2);
        int rth_w=abs(rth.w1-rth.w2);

        int h=abs(this->h1-this->h2);
        int rth_h=abs(rth.h1-rth.h2);
        return (w<rth_w)||(!(rth_w<w)&&(h<rth_h));
    }
        
};
void dump(set<Square> S) {
    puts("dump");
    for(auto s : S) {
        printf("%d %d %d %d\n",s.w1,s.h1,s.w2,s.h2);

    }
    puts("finish\n");
}
int w,h,k;
int main() {
    cin>>w>>h>>k;
    set<Square> S;
    S.insert(Square(0,0,w,h));
    while(k-->0) {
        char c;
        int t;
        cin>>c>>t;
        dump(S);
        Square s=*S.begin();
        S.erase(S.begin());
        if(c=='H') {
            int h1=abs(t);
            int h2=abs(t-s.h2);
            S.insert(Square(s.w1,s.h1,s.w2,h1));
            S.insert(Square(s.w1,h1,s.w2,s.h2));
        }
        else {
            int w1=abs(t);
            int w2=abs(t-s.w2);
            S.insert(Square(s.w1,s.h1,w1,s.h2));
            S.insert(Square(w1,s.h1,s.w2,s.h2));
        }
        dump(S);
        s=*S.begin();
        cout<<abs((s.w1-s.w2)*(s.h1-s.h2))<<endl;

    }
    return 0;
}

