> version 2025-08-09  
> © 2025 [bluewindde](https://www.luogu.com.cn/user/857577)  
> 本文采用 [CC BY-SA 4.0 协议](https://creativecommons.org/licenses/by-sa/4.0/deed.zh-hans) 发布

## 使用说明

需要在使用本模板库前加入如下代码。

```cpp
#include<iostream>
#include<type_traits>

using namespace std;
```

## 兼容性说明

本模板库在 C++ 14 下可用，舍弃了所有 C++ 17 及以后引入的特性。

本模板库全局修改了如下行为：

- is_integral 为 __int128 特化。

## FastIO

支持读写字符和非负整数。接口是 cin/cout 的一部分和 fin/fout 的混合体。

与解绑同步流的 cin/cout 在相同运行条件（C++ 14 O2）下对比：

| 数量 | 值域 | 输入量 | cin/cout | FastIO | 提速 |
| :- | :- | :- | :- | :- | :- |
| $10^6$ | $[0, 10^9]$ | 9MiB | 48ms | 114 | $57.63\%$ |
| $10^6$ | $[-10^9, 10^9]$ | 10MiB | 55ms | 129 | $57.45\%$ |
| $10^6$ | $[0, 10^{18}]$ | 18MiB | 108ms | 161 | $32.94\%$ |
| $10^6$ | $[-10^{18}, 10^{18}]$ | 18MiB | 96ms | 180 | $46.65\%$ |
| $10^7$ | $[0, 10^{18}]$ | 180MiB | 876ms | 1666 | $47.39\%$ |
| $10^7$ | $[-10^{18}, 10^{18}]$ | 185MiB | 1209ms | 1929 | $37.31\%$ |
| $2 \cdot 10^7$ | $[0, 10^{18}]$ | 360MiB | 1911ms | 3114 | $38.63\%$ |
| $2 \cdot 10^7$ | $[-10^{18}, 10^{18}]$ | 370MiB | 1696ms | 3277 | $48.25\%$ |
| $10^8$ | $[0, 10^{18}]$ | 2GiB | 10530ms | 16503 | $36.19\%$ |
| $10^8$ | $[-10^{18}, 10^{18}]$ | 2GiB | 9317ms | 17748 | $47.50\%$ |

[代码](https://www.luogu.com.cn/paste/102u1wx4)

## 测试

`gcc --version` 结果：

```plain
g++ (Ubuntu 9.4.0-1ubuntu1~20.04.2) 9.4.0
Copyright (C) 2019 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```

编译选项

```
g++ 1.cpp -o 1 -std=c++14 -O2
```

每组测试重复三次，测试结果四舍五入，结果仅供参考。

提供测试所用程序的源代码。

[FastIO](https://www.luogu.com.cn/paste/e4p1orwe)
