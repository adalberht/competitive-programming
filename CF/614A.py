from math import log

l, r, k = map(int, input().split())

lower = int(log(l, k))

while (k ** lower < l):
  lower += 1

if (k ** lower > r):
  print(-1)
  exit()

print(k ** lower, end="")
lower += 1
while (k ** lower <= r):
  print(" " + str(k ** lower), end="")
  lower += 1
print()
