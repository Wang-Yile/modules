import sys
import random

rand = random.randint

n = int(sys.argv[1])
l = int(sys.argv[2])
r = int(sys.argv[3])

print(n)
for i in range(n):
    print(rand(l, r), end=" ")
print()
