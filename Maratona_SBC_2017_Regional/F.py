n = int(input())
k = int(input())

strr = ""

for i in range(0, n):
    if i != 0:
        strr += ","
    strr += input()

numbers = list(map(int, strr.split(",")))

numbers.sort()

r = 0
prev = numbers[len(numbers) - 1]

for i in range(n - 1, -1, -1):
    if (prev != numbers[i] and r < k) or (prev == numbers[i]):
        prev = numbers[i]
        r += 1

print(r)
