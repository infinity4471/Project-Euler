from math import sqrt

def div_sum( n ):
  sum = 0
  for i in range( 1, int( sqrt( n ) ) + 1 ):
    if n % i == 0:
      sum += i + n / i
  return sum - n

sum = 0
for i in range( 2, 10000 ):
  getsum1 = div_sum( i )
  if i == getsum1:
    continue
  if( div_sum( getsum1 ) == i and getsum1 < 10000 ):
    sum += i

print sum
