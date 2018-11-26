from math import sqrt

MAX = 30000

def div_sum( n ):
  sum = 0
  for i in range( 2, int( sqrt( n  ) ) + 1 ):
    if n % i == 0:
      sum += i + n / i
    if i * i == n:
      sum -= i;
  return sum + 1

abundant = []

sum = 0

print div_sum( 4 )
for i in range( 1, MAX + 10 ):
  abundant.append( -1 )
for i in range( 1, MAX ):
  val = div_sum( i )
  if val > i:
    abundant[ i ] = 1

for i in range( 1, MAX + 1 ):
  status = True
  for x in range( 1, i ):
    if abundant[ i - x ] == 1 and abundant[ x ] == 1:
      status = False
      break
  if status == True:
    sum += i

print sum
