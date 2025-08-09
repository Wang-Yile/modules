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

请阅读 [bugs.md](./bugs.md) 了解当前未修复/不计划修复的漏洞。

## 兼容性说明

本模板库在 C++ 14 下可用，舍弃了所有 C++ 17 及以后引入的特性。

本模板库全局修改了如下行为：

- is_integral 为 __int128 特化。

## FastIO

支持读写字符和非负整数。接口是 cin/cout 的一部分和 fin/fout 的混合体。

version 2025-08-09 与解绑同步流的 cin/cout 在相同运行条件（C++ 14 O2）下对比：

值域 $[-10^9, 10^9]$

| 数量 | 输入量 | FastIO | cin/cout | 提速 |
| :- | :- | :- | :- | :- |
| $10^5$ | 1015KiB | 5ms | 14ms | 59.47% |
| $10^6$ | 10MiB | 58ms | 136ms | 57.09% |
| $10^7$ | 99MiB | 470ms | 1215ms | 61.25% |
| $10^8$ | 991MiB | 4196ms | 11551ms | 63.67% |

值域 $[-10^{18}, 10^{18}]$

| 数量 | 输入量 | FastIO | cin/cout | 提速 |
| :- | :- | :- | :- | :- |
| $10^5$ | 1.85MiB | 18ms | 23ms | 21.74% |
| $10^6$ | 18.5MiB | 78ms | 174ms | 51.70% |
| $10^7$ | 185MiB | 1211ms | 2216ms | 45.32% |
| $10^8$ | 1.8GiB | 7462ms | 18596ms | 59.87% |

[fastio.h](./fastio/fastio.h)

## 测试

```plain
$ gcc --version
g++ (Ubuntu 9.4.0-1ubuntu1~20.04.2) 9.4.0
Copyright (C) 2019 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```

编译选项

```
g++ 1.cpp -o 1 -std=c++14 -O2
```

每组测试重复三次，测试结果四舍五入到合适的有效位数，结果仅供参考。

提供测试所用程序的源代码。
