from math import sqrt

def prime( n ):
  for d in range( 2, int( sqrt( n + 1 ) ) ):
    if n % d == 0:
      return False
  return True

def pandigital( n ):
  digits = 10 * [ 0 ]
  length = len( str( n ) )
  while n > 0:
    digits[ n % 10 ] += 1
    n /= 10
  pos = -1
  for d in range( 1, 10 ):
    if digits[ d ] == 0:
      pos = d - 1
      break
  if( pos != length ):
    return False
  return True

X = 2

while True:
  X += 1
  if prime( X ) == False:
    continue
  if pandigital( X ) == True:
    print X
