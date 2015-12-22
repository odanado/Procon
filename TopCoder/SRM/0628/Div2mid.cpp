#include <algorithm>
#include <functional>
#include <cmath>
#include <cstdio>
#include <cstdint>
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

class BracketExpressions {
public:
    vector<int> vec;
    string s1 = "({[";
    string s2 = ")}]";
    string s3 = s1+s2;
    string ifPossible(string expression) {
        rep(i,expression.size()) if(expression[i]=='X') vec.push_back(i);

        bool ans = dfs(expression,0);
        if(ans) {
            return "possible";
        }
        else {
            return "impossible";
        }

    }
    bool dfs(string expression,int depth) {
        if(depth == vec.size()) return f(expression);
        bool ret = false;

        rep(i,s3.size()) {
            char t = expression[vec[depth]];
            expression[vec[depth]] = s3[i];
            cout<<"s3 = "<<s3[i]<<endl;
            ret |= dfs(expression,depth+1);
            cout<<depth<<endl;
            cout<<vec[depth]<<endl;
            cout<<expression[vec[depth]]<<endl;
            expression[vec[depth]] = t;
        }

        return ret;
    }
    bool f(string expression) {
        cout<<expression<<endl;
        stack<char> st;
        rep(i,expression.size()) {
            cout<<expression[i]<<endl;
            if(s1.find(expression[i])!=string::npos) {
                st.push(expression[i]);
            }
            else {
                if(st.empty()) return false;
                char c = st.top(); st.pop();
                if(s1.find(c)!=s2.find(expression[i])) {

                    return false;
                }
            }

        }

        return st.empty();
    }
};

int main() {
    BracketExpressions obj;
    cout<<obj.ifPossible("()X");

    return 0;
}

