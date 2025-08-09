import sys

x = 1
A = 48271
M = (1 << 63) - 1
def next():
    global x
    x = (x * A + 1) & M

n = int(sys.argv[1])
l = int(sys.argv[2])
r = int(sys.argv[3])

print(n)
for i in range(n):
    next()
    print(l + x % (r-l+1), end=" ")
print()
