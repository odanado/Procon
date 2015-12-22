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

struct Node {
    int idx;
    string text;
    vector<Node*> children;
    Node(int idx,string text) :
        idx(idx),text(text){}
    ~Node() {
        for(auto child : children) {
            delete child;
        }
    }
};

Node* find(Node *node,int idx) {
    if(node->idx==idx) return node;
    for(auto child : node->children) {
        return find(child, idx);
    }

    return nullptr;
}

void print(Node *node, int indent) {
    cout<<string(indent,'.');
    cout<<node->text<<endl;
    for(auto child : node->children) {
        print(child,indent+1);
    }
}


int n;
void solve() {
    Node *root;
    map<int,Node*> nodes;
    rep(i,n) {
        int k;
        string m;
        cin>>k>>m;
        if(k==0) {
            root=new Node(i,m);
            nodes[0]=root;
        }
        else {
            k--;
            Node *node=nodes[k];
            nodes[i]=new Node(i,m);
            //cout<<node->text<<", "<<node->idx<<endl;
            node->children.push_back(nodes[i]);
        }
    }
    print(root,0);
}
int main() {
    while(cin>>n) {
        if(n==0) break;
        solve();
    }
    return 0;
}

