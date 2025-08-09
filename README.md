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

| 数量 | 值域 | 输入量 | FastIO | cin/cout | 提速 |
| :- | :- | :- | :- | :- | :- |
| $10^5$ | $[-10^9, 10^9]$ | 1014.78KiB | 11ms | 13ms | $19.72\%$ |
| $2 \cdot 10^5$ | $[-10^9, 10^9]$ | 1.98MiB | 11ms | 24ms | $54.44\%$ |
| $5 \cdot 10^5$ | $[-10^9, 10^9]$ | 4.95MiB | 26ms | 65ms | $59.58\%$ |
| $10^6$ | $[-10^9, 10^9]$ | 9.91MiB | 50ms | 132ms | $62.36\%$ |
| $10^7$ | $[-10^9, 10^9]$ | 99.08MiB | 517ms | 1210ms | $57.24\%$ |
| $5 \cdot 10^5$ | $[-10^{18}, 10^{18}]$ | 9.25MiB | 49ms | 86ms | $42.00\%$ |
| $10^6$ | $[-10^{18}, 10^{18}]$ | 18.49MiB | 86ms | 177ms | $51.26\%$ |
| $5 \cdot 10^6$ | $[-10^{18}, 10^{18}]$ | 92.45MiB | 468ms | 1004ms | $53.42\%$ |
| $10^7$ | $[-10^{18}, 10^{18}]$ | 184.91MiB | 1157ms | 2039ms | $43.24\%$ |
| $5 \cdot 10^7$ | $[-10^{18}, 10^{18}]$ | 924.53MiB | 5880ms | 9681ms | $39.26\%$ |
| $10^8$ | $[-10^{18}, 10^{18}]$ | 1.81GiB | 11431ms | 17672ms | $35.32\%$ |

[代码](./fastio/fastio.h)

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

[FastIO](./fastio/)
