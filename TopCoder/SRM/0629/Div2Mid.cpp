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

class CandyMaking {
public:
    double findSuitableDensity(vector <int> containerVolume, vector <int> desiredWeight) {
        double ret = 0;
        int sumV=0;
        int sumW=0;
        rep(i,containerVolume.size()) {
            sumV += containerVolume[i];
            sumW += desiredWeight[i];
        }

        double lb=0.0,ub=INF;
        for(int i=0;i<100000;i++) {
            double mid = (lb+ub)/2.0;
            if(sumW-mid*sumV>0) lb = mid;
            else ub = mid;
        }

        return sumW-ub*sumV;
    }

};

int main() {
    return 0;
}

