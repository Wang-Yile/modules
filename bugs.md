# 已知漏洞

## FastIO

### 【不计划修复】输出 INT32_MIN 一类数字时会出现乱码

原因是 FastIO::ostream 将负数取绝对值输出，而对 INT32_MIN 取绝对值会导致 int 类型溢出。

由于一般不会输出这一类数字，且经测试修复方案（如下）效率明显下降，不计划修复该问题。如果确实有需要，请尝试输出时转换为更大的类型或使用如下方案替换 fastio.h 的对应部分。

```cpp
class ostream{
  private:
    // ...
    template<typename T>
    inline typename enable_if<is_integral<T>::value,int>::type _tobuf(char* sta,T x){
        int t=0;
        while(x){
            sta[t++]=(x%10)^48;
            x/=10;
        }
        return t;
    }
  public:
    // ...
    template<typename T>
    inline typename enable_if<is_integral<T>::value,ostream&>::type operator<<(T x){
        if(x==0)
            return put('0');
        static char sta[sizeof(T)<<2];
        int t;
        if(x<0){
            put('-');
            t=_tobuf(sta,-(x+1));
            for(int i=0;i<t;++i){
                if(sta[i]!='9'){
                    ++sta[i];
                    break;
                }
                sta[i]='0';
            }
            if(!t||sta[t-1]=='0')
                put('1');
        }else
            t=_tobuf(sta,x);
        while(t)
            put(sta[--t]);
        return *this;
    }
}out(stdout);
```