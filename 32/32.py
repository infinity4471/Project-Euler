from itertools import permutations
from math import factorial

def tonum( A ):
  val = 0
  for i in range( 0, len( A ) ):
    val = val + A[len( A )-1 - i] * 10**i
  return val

iterator = 0
total = factorial( 10 )

sum = 0
for X in permutations( range( 0, 10 ) ):
  for i in range( 0, 10 ):
    for j in range( i + 1, 10 ):
      A, B, C = X[ : ( i + 1 ) ], X[ ( i + 1 ) : ( j + 1 ) ], X[ ( j + 1 ) : ]
      n1, n2, n3 = tonum( A ), tonum( B ), tonum( C )
      if n1 * n2 == n3:
        sum = sum + n3
  iterator += 1
print sum
