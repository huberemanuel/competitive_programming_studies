fibo = [2, 0]
total = 0
i = 0

while fibo[i] < 4000000:
  total += fibo[i]
  i = (i + 1) % 2
  fibo[i] = 4 * fibo[(i + 1) % 2] + fibo[i]

print(total)
