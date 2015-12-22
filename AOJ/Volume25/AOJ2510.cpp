#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int N;

struct Book {
    int r,w;
    Book() {}
    Book(int r,int w) : r(r),w(w) {}
    bool operator<(const Book& b) const {
        return this->r < b.r;
    }

};
int dp[1003][1003];

void solve() {
    rep(i,1003) rep(j,1003) dp[i][j] = 0;
    vector<Book> book;
    book.resize(N);

    rep(i,N) {
        int a,b;
        cin>>a>>b;
        book[i] = Book(a,b);
    }
    sort(book.begin(), book.end());
    int sum = 0;
    rep(i,N) if(i!=N-1) sum += book[i].r;
    if(sum >= book[N-1].r) {
        sum += book[N-1].r;
        rep(i,N) sum += book[i].w;
        cout<<sum<<endl;
        return;
    }
    
    // i番目までで,時間jにできるか
    dp[0][0] = 1;
    rep(i,N-1) {
        rep(j,book[N-1].r-sum+1) {
            //cout<<i+1<<","<<j+book[i].w<<endl;
            dp[i+1][j] |= dp[i][j];
            dp[i+1][j+book[i].w] |= dp[i][j];
        }
    }
    int maxi = 0;
    rep(i,book[N-1].r-sum+1) {
        if(dp[N-1][i]) maxi = max(maxi,i);
    }
    
    int t = book[N-1].r - sum;
    t -= maxi;
    rep(i,N) t+=book[i].w;
    cout<<book[N-1].r+sum+t<<endl;

    

}

int main() {
    while(cin>>N) {
        if(N==0) return 0;
        solve();
    }

    return 0;
}
