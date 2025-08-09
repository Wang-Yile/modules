#include<iostream>
#include"fastio.h"

using namespace std;

int n;

signed main(){
    in>>n;
    __int128 sum=0;
    for(int i=1;i<=n;++i){
        long long x;
        in>>x;
        sum+=x;
        out<<x<<' ';
    }
    out<<'\n';
    out<<sum<<'\n';
    return 0;
}