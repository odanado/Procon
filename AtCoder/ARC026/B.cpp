#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++) 

int main() {
    long long N;
    long long sum = 0;
    cin>>N;
    for(long long i=1;i*i<=N;i++) {
        if(N%i==0) {
            sum += i;
            if(i!=N/i) sum += N/i;
        }
    }
    sum -= N;
    if(sum == N) {
        cout<<"Perfect"<<endl;
    }
    if(sum > N) {
        cout<<"Abundant"<<endl;
    }
    if(sum < N) {
        cout<<"Deficient"<<endl;
    }

    return 0;
}
