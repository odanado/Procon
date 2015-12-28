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

typedef vector<char> Vector;
typedef vector<Vector> Matrix;

Matrix make(Matrix mat) {
    Matrix ret(mat.size()*2, Vector(mat.size()*2));
    rep(i,mat.size()) {
        rep(j,mat[i].size()) {
            ret[i][j]=mat[i][j];
            ret[i][j+mat[i].size()]=mat[i][j];
            ret[i+mat.size()][j]=mat[i][j];
            ret[i+mat.size()][j+mat[i].size()]=mat[i][j]=='+'?'*':'+';
        }
    }

    return ret;
}

int main() {
    int k;
    cin>>k;
    int n=1<<k;
    Matrix mat(1,Vector(1));
    mat[0][0]='+';
    while(mat.size()!=n) {
        mat = make(mat);
    }

    rep(i,mat.size()) {
        rep(j,mat[i].size()) {
            cout<<mat[i][j];
        }
        cout<<endl;
    }
    return 0;
}

