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

int K;
string iso[101];
string naka[101];

string solve() {
    int pow1=0,pow2=0;
    rep(i,K) {
        if(iso[i]=="tameru") pow1++;
        if(naka[i]=="tameru") pow2++;
        pow1=min(pow1,5);
        pow2=min(pow2,5);
        if(iso[i]=="kougekida"&&naka[i]=="kougekida") {
            if(pow1==pow2) {
                pow1=pow2=0;
                continue;
            }
            else if(pow1<pow2) {
                pow1=pow2=0;
                return "Nakajima-kun";
            }
            else {
                pow1=pow2=0;
                return "Isono-kun";
            }
        }
        if(iso[i]=="kougekida"&&pow1==0) return "Nakajima-kun";
        if(naka[i]=="kougekida"&&pow2==0) return "Isono-kun";

        if(iso[i]=="kougekida"&&naka[i]=="tameru") {
            return "Isono-kun";
        }
        if(iso[i]=="kougekida"&&naka[i]=="mamoru") {
            if(pow1==5) return "Isono-kun";
            pow1=0;
        }
        if(iso[i]=="mamoru"&&naka[i]=="kougekida") {
            if(pow2==5) return "Nakajima-kun";
            pow2=0;
        }
        if(iso[i]=="tameru"&&naka[i]=="kougekida") {
            return "Nakajima-kun";
        }
    }

    return "Hikiwake-kun";
}
int main() {
    cin>>K;
    rep(i,K) cin>>iso[i];
    rep(i,K) cin>>naka[i];
    cout<<solve()<<endl;
    return 0;
}

