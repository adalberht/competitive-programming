"""
Python for Competitive Programming:
In short:
- Write your solution inside a function. Lookup variables in the global scope is more expensive, than using variables in the local scope.
- Avoid for loops like the plague. Favor Python builtins. Always use map, filter, concatenate strings with join, etc.
- Writing output is really expensive. Writting a gigantic string once, may be better than writting several small strings.
- Type casting is really expensive. Avoid if possible (string to int).
  - Casting string to int > casting int to string (but both of them are costly)
- Avoid dots. In other words: Cache function lookups. Example: Avoid using stdout.write directly, put it in a variable w = stdout.write.
- Careful with Dict vs Lists for graphs
"""

def main():
  from sys import stdin, stdout
  def solve(tc: int):
    buf = "Testcase #{}: ".format(tc)
    stdout.write(buf + "\n")
  TC = 1
  # TC = int(stdin.readline())
  
  for tc in range(TC):
    solve(tc)

if __name__ == '__main__':
	main()