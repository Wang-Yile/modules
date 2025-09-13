#include<iostream>
#include<type_traits>

using namespace std;

namespace std{
    template<>
    struct is_integral<__int128>:true_type{};
}

namespace FastIO{
const int BUFSIZE=1<<20;
class istream{
  private:
    char buf[BUFSIZE],*st=buf,*ed=buf;
    FILE *file=nullptr;
    void _flush(){ed=(st=buf)+fread(buf,sizeof(char),BUFSIZE,file);}
  public:
    istream(){}
    istream(FILE *stream){file=stream;}
    istream(const istream&)=delete;
    ~istream(){}
    inline char get(){
        if(st==ed)_flush();
        return st==ed?EOF:*st++;
    }
    inline istream& operator>>(char &x){x=get();return *this;}
    template<typename T>
    inline typename enable_if<is_integral<T>::value,istream&>::type operator>>(T &x){
        x=0;
        char c=get();
        bool op=false;
        while(c<48||c>57){
            if(c=='-')
                op=true;
            c=get();
        }
        while(48<=c&&c<=57){
            x=(x<<3)+(x<<1)+(c^48);
            c=get();
        }
        if(op)
            x=-x;
        return *this;
    }
}in(stdin);
class ostream{
  private:
    char buf[BUFSIZE];
    int tp=0;
    FILE *file=nullptr;
  public:
    ostream(){}
    ostream(FILE *stream){file=stream;}
    ostream(const ostream&os)=delete;
    ~ostream(){flush();}
    inline void flush(){fwrite(buf,sizeof(char),tp,file),tp=0;}
    inline ostream& put(char c){
        buf[tp++]=c;
        if(tp==BUFSIZE)
            flush();
        return *this;
    }
    inline ostream& operator<<(char c){put(c);return *this;}
    inline ostream& operator<<(const char *s){
        while(*s)
            put(*s++);
        return *this;
    }
    inline ostream& operator<<(const string &s){
        for(auto c:s)
            put(c);
        return *this;
    }
    template<typename T>
    inline typename enable_if<is_integral<T>::value,ostream&>::type operator<<(T x){
        if(x==0)
            return put('0');
        if(x<0){
            put('-');
            x=-x;
        }
        static char sta[sizeof(T)<<2];
        int t=0;
        while(x){
            sta[t++]=(x%10)^48;
            x/=10;
        }
        while(t)
            put(sta[--t]);
        return *this;
    }
}out(stdout);
};
using FastIO::in;
using FastIO::out;