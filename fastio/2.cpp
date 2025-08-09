#include<iostream>

using namespace std;

static inline void write(__int128 x){
    if(x<0){
        cout.put('-');
        return write(-x);
    }
    if(x>=10)
        write(x/10);
    cout.put((x%10)^48);
}

int n;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    __int128 sum=0;
    for(int i=1;i<=n;++i){
        long long x;
        cin>>x;
        sum+=x;
        cout<<x<<' ';
    }
    cout<<'\n';
    write(sum);
    cout<<'\n';
    return 0;
}