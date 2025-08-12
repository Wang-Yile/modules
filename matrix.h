#include<array>

using namespace std;

typedef long long i64;

const int mod=998244353;

class matrix{
  private:
    array<array<i64,3>,3>a;
  public:
    matrix(){for(int i=0;i<3;++i)a[i].fill(0);}
    matrix(const matrix &x){a=x.a;}
    ~matrix(){}
    inline matrix& operator=(const matrix &x){a=x.a;return *this;}
    inline const array<i64,3>& operator[](int x)const{return a[x];}
    inline array<i64,3>& operator[](int x){return a[x];}
    friend inline matrix operator*(const matrix &A,const matrix &B){
        matrix C;
        for(int i=0;i<3;++i)
            for(int k=0;k<3;++k)
                for(int j=0;j<3;++j)
                    C[i][j]+=A[i][k]*B[k][j];
        for(int i=0;i<3;++i)
            for(int j=0;j<3;++j)
                C[i][j]%=mod;
        return C;
    }
};
static inline matrix qpow(matrix a,int b){
    matrix ret;
    for(int i=0;i<3;++i)
        ret[i][i]=1;
    while(b){
        if(b&1)
            ret=ret*a;
        a=a*a;
        b>>=1;
    }
    return ret;
}