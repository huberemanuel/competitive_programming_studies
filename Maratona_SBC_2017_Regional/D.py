import math

n = int(input())
f = 2
factors = 0

while math.pow(f, 2) <= n:
    if n % f == 0:
        factors += 1
        while n % f == 0:
            n /= f
    f += 1
if n != 1:
    factors += 1

print(int(math.pow(2, factors)) - (factors + 1))
