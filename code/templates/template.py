import sys
import math
import bisect
import io,os
from sys import stdin,stdout
from math import gcd,floor,sqrt,log
from collections import defaultdict as dd
from bisect import bisect_left as bl,bisect_right as br

# profundidad maxima de la pila.
# default = 10^3
sys.setrecursionlimit(100000000)

flush  =lambda: stdout.flush()
input  =lambda: stdin.readline()
print  =lambda x: stdout.write(str(x) + "\n")
ceil   =lambda x: int(x) if(x==int(x)) else int(x)+1
seq    =lambda typ=int: list(map(typ,input().strip().split()))
jn     =lambda x,l: x.join(map(str,l))

mod=1000000007

# For too large inputs
input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
s = input().decode() # for strings

# Notes
# Para imprimir un arreglo
print(*list)
print(jn(" ", list))