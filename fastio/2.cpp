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
long long a[100000005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    __int128 sum=0;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        sum+=a[i];
    }
    write(sum);
    cout<<'\n';
    cout<<n<<'\n';
    for(int i=1;i<=n;++i)
        cout<<a[i]<<' ';
    cout<<'\n';
    return 0;
}