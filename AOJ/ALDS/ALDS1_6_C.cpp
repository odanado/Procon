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

struct Card {
    char suit;
    int value;

    bool operator<(const Card& c) const {
        return this->value < c.value;
    }
    bool operator<=(const Card& c) const {
        return this->value <= c.value;
    }
    Card& operator=(int val) {
        this->value = val;
        return *this;
    }
};
#define MAX 100000
#define SENTINEL 2000000000
Card L[MAX/2+2],R[MAX/2+2];
void merge(Card *a,int n, int l,int mid,int r) {
    int n1=mid-l;
    int n2=r-mid;
    rep(i,n1) L[i]=a[l+i];
    rep(i,n2) R[i]=a[mid+i];
    L[n1]=SENTINEL;
    R[n2]=SENTINEL;
    int i,j;
    i=j=0;
    for(int k=l;k<r;k++) {
        if(L[i]<=R[j]) a[k]=L[i++];
        else a[k]=R[j++];
    }
}
void merge_sort(Card *a,int n,int l,int r) {
    if(l+1<r) {
        int mid=(l+r)/2;
        merge_sort(a,n,l,mid);
        merge_sort(a,n,mid,r);
        merge(a,n,l,mid,r);
    }
}
int partition(Card *a,int p,int r) {
    int i,j;
    Card x;
    x=a[r];
    i=p-1;
    for(int j=p;j<r;j++) {
        if(a[j]<=x) {
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[r]);
    return i+1;
}

void quick_sort(Card *a,int n,int p,int r) {
    int q;
    if(p < r) {
        q = partition(a,p,r);
        quick_sort(a,n,p,q-1);
        quick_sort(a,n,q+1,r);
    }
}

Card A[MAX],B[MAX];
int main() {
    int n;
    cin>>n;
    rep(i,n) {
        cin>>A[i].suit>>A[i].value;
        B[i]=A[i];

    }

    merge_sort(A,n,0,n);
    quick_sort(B,n,0,n-1);
    bool is_stable = true;

    rep(i,n) is_stable &= A[i].suit == B[i].suit;

    if(is_stable) cout<<"Stable"<<endl;
    else cout<<"Not stable"<<endl;
    rep(i,n) cout<<B[i].suit<<" "<<B[i].value<<endl;

    return 0;
}

