import os
import time

def run(cmd: str, retry = 3):
    ret = []
    print("    ", end="")
    for i in range(retry):
        st = time.time()
        os.system(cmd)
        ed = time.time()
        print(f"{round((ed-st)*1000)}ms", end=" ", flush=True)
        ret.append(ed-st)
    ava = sum(ret)/retry
    print(f"= {round(ava*1000)}ms")
    return ava

if os.system("g++ 1.cpp -o 1 -std=c++14 -O2"):
    exit()
if os.system("g++ 2.cpp -o 2 -std=c++14 -O2"):
    exit()

def tr(x: int):
    fl = x < 0
    x = abs(x)
    for i in range(10):
        if x == 10**i:
            return ("-" if fl else "") + "10^" + str(i)
        for j in range(2, 10):
            if x == j * 10**i:
                return ("-" if fl else "") + str(j) + " \cdot 10^" + str(i)
    for i in range(10, 20):
        if x == 10**i:
            return ("-" if fl else "") + "10^{" + str(i) + "}"
        for j in range(2, 10):
            if x == j * 10**i:
                return ("-" if fl else "") + str(j) + " \cdot 10^{" + str(i) + "}"
    return str(x)
def tr_mem(mem: int):
    head = "EPTGMK"
    for i in range(len(head)):
        size = 1 << (10 * (len(head) - i))
        if mem >= size:
            return f"{round(mem/size*100)/100}{head[i]}iB"
    return f"{mem} B"

tcs = [
    (int(1e5), -int(1e9), int(1e9)),
    (int(2e5), -int(1e9), int(1e9)),
    (int(5e5), -int(1e9), int(1e9)),
    (int(1e6), -int(1e9), int(1e9)),
    (int(1e7), -int(1e9), int(1e9)),
    (int(5e5), -int(1e18), int(1e18)),
    (int(1e6), -int(1e18), int(1e18)),
    (int(5e6), -int(1e18), int(1e18)),
    (int(1e7), -int(1e18), int(1e18)),
    (int(5e7), -int(1e18), int(1e18)),
    (int(1e8), -int(1e18), int(1e18)),
]

md = "| 数量 | 值域 | 输入量 | FastIO | cin/cout | 提速 |\n| :- | :- | :- | :- | :- | :- |\n"

for tc in tcs:
    n, l, r = tc
    print(f"{n:e} {l:e} {r:e}")
    if os.system(f"python3 data.py {n} {l} {r} > 1.in"):
        print("FAIL")
        break
    x = run("./1 < 1.in > 1.out")
    y = run("./2 < 1.in > 2.out")
    if os.system("diff 1.out 2.out -w -q"):
        print("Wrong Answer")
        break
    md += f"| ${tr(n)}$ | $[{tr(l)}, {tr(r)}]$ | {tr_mem(os.stat('1.in').st_size)} | {int(x*1000)}ms | {int(y*1000)}ms | ${(y-x)/y*100:.2f}\\%$ |\n"

print(md)
