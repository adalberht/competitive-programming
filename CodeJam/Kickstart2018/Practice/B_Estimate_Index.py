memo = {
  0: 0,
  1: 1,
}

def f(n):
  if n in memo:
    return memo[n]
  memo[n] = 2*f(n-1) + 1
  return memo[n]

cnt = 2
while True:
  if f(cnt) > 1e18:
    print(cnt)
    break
  cnt += 1