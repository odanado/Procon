#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

string formula;
int not_[3] = {2,1,0};
int and_[3][3] = { {0,0,0},{0,1,1},{0,1,2}};
int or_[3][3] = { {0,1,2},{1,1,2},{2,2,2}};
int R,Q,P;

int parse(int &pos) {
    int ret;
    if(formula[pos] == 'R') ret = R;
    else if(formula[pos] == 'Q') ret = Q;
    else if(formula[pos] == 'P') ret = P;
    else if('0'<=formula[pos] && formula[pos] <= '9') ret = formula[pos] - '0'; 
    else if(formula[pos] == '(') {
        ret = parse(++pos);
        if(formula[pos] == '+') ret = or_[ret][parse(++pos)];
        else if(formula[pos] == '*') ret = and_[ret][parse(++pos)];
    }
    else if(formula[pos] == '-') return not_[parse(++pos)];

    pos++;

    return ret;

} 

void solve() {
    int pos = 0;
    int ans = 0;
    for(P=0;P<=2;P++) {
        for(Q=0;Q<=2;Q++) {
            for(R=0;R<=2;R++) {
                pos = 0;
                if(parse(pos) == 2) ans++;
            }
        }
    }

    cout<<ans<<endl;

}
int main() {
    while(cin>>formula) {
        if(formula==".") return 0;

        solve();
    }


    return 0;
}
