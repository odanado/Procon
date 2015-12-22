#include<iostream>
#include<algorithm>
#include<map>

using namespace std;

int M,T,P,R;

class Trem {
public:

    int id;
    int AC_cnt;
    int WA_cnt[13];
    int time;
    bool is_AC[13];
    Trem() {
    }
    Trem(int i) {
        this->id = i;
        AC_cnt=0;
        time=0;
        for(int i=0;i<13;i++) {
            WA_cnt[i]=0;
            is_AC[i]=false;
        }
    }
    void submit(int m,int t,int p,int j) {
        if(j==0) {
            AC_cnt++;
            is_AC[p]=true;
            time += m;
            time += WA_cnt[p]*20;
        }
        else {
            WA_cnt[p]++;
            
        }
    }
    bool operator<(const Trem& t1) const {
        if(this->AC_cnt != t1.AC_cnt) {
            return this->AC_cnt > t1.AC_cnt;
        }
        if(this->time != t1.time) return this->time < t1.time;
        return this->id > t1.id;
    }

};

void solve() {
    Trem trem[53];
    for(int i=0;i<53;i++) trem[i]=Trem(i);
    for(int i=0;i<R;i++) {
        int m,t,p,j;
        cin>>m>>t>>p>>j;
        trem[t].submit(m,t,p,j);
    }
    sort(trem+1,trem+T+1);
    for(int i=1;i<=T;i++) {
        Trem t = trem[i];
        Trem next = trem[i+1];
        char c = ((t.AC_cnt==next.AC_cnt && 
                t.time == next.time)?'=':',');
        if(i==T) c='\n';
        cout<<t.id;
        cout<<(c);
    }

    

}

int main() {
    while(cin>>M>>T>>P>>R) {
        if(M+T+P+R==0) return 0;
        solve();
    }

    return 0;
}

/* 2014/05/14 AC */
