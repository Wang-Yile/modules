#include<iostream>
#include"fastio.h"

using namespace std;

int n;
long long a[100000005];

signed main(){
    in>>n;
    __int128 sum=0;
    for(int i=1;i<=n;++i){
        in>>a[i];
        sum+=a[i];
    }
    out<<sum<<'\n';
    out<<n<<'\n';
    for(int i=1;i<=n;++i)
        out<<a[i]<<' ';
    out<<'\n';
    return 0;
}