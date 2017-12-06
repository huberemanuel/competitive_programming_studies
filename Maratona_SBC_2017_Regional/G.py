mod = 1000000007
time, minimo, maximo = [int(x) for x in raw_input("").split(" ")]
diferenca = maximo - minimo

m = [[1 for x in range(diferenca + 1)] for y in range(2)]

old = 0
curr = 1

for t in range(1, time):
    for d in range(1, diferenca):
        m[curr][d] = (m[old][d - 1] + m[old][d + 1]) % mod

    m[curr][0] = m[old][1]
    m[curr][diferenca] = m[old][diferenca - 1]

    old, curr = curr, old
  
r = 0
for i in range(diferenca + 1):
  r = (m[old][i] + r) % mod

print(r)


