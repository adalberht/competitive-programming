from random import *

def substitute(expr, random_dict):
	ret = ""
	for i in range(len(expr)):
		if (expr[i].isalpha()):
			if (expr[i] not in random_dict):
				random_dict[expr[i]] = randint(0, 1000000)
			ret += str(random_dict[expr[i]])
		else:
			ret += expr[i]
	return ret

TC = int(input())
for tc in range(TC):
	expr1, expr2 = input(), input()
	flag = True
	if flag:
		for i in range(10):
			random_dict = {}
			substituted_expr1 = substitute(expr1, random_dict)
			substituted_expr2 = substitute(expr2, random_dict)
			val1 = eval(substituted_expr1)
			val2 = eval(substituted_expr2)
			if val1 != val2:
				flag = False
				break
	if flag:
		print("YES")
	else:
		print("NO")
