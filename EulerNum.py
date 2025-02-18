import math


def euler_num (n):
    return sum(1 / math.factorial(n) for n in range(n+1))

n = int(input().strip())






""" n =23
fact = 1
for i in range (1, n+1):
    fact = fact * 1
    return fact
 """
