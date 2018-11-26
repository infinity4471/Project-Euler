from math import sqrt

def divisors( n ):
  cnt = 0
  for i in range( 1, int( sqrt( n ) ) + 1 ):
    if n % i == 0:
      cnt += 2
    if i * i == n:
      cnt -= 1
  return cnt

i = 1
number = 0

while( True ):
  number += i
  i += 1
  div = divisors( number )
  if div > 500:
    print number
    break

