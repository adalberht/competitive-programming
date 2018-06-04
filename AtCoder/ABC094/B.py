N, M, X = [int(x) for x in input().split(" ")]
arr = [0 for x in range(N+1)]
for i in [int(a) for a in input().split(" ")]:
	arr[i] = 1
kiri = arr[0:X].count(1)
kanan = arr[X+1:].count(1)
print(min(kiri, kanan))