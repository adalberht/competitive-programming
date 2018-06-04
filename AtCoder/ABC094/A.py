A, B, C = [int(x) for x in input().split(" ")]
if A > C:
	print("NO")
elif A == C:
	print("YES")
elif A + B >= C:
	print("YES")
else:
	print("NO")