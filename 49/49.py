from itertools import permutations
from math import sqrt

def prime( n ):
  for d in range( 2, int( sqrt( n + 1 ) ) ):
    if n % d == 0:
      return False
  return True

def toint( x ):
  val = 0
  for i in range( 0, len( x ) ):
    val += 10**( len( x ) - i - 1 ) * int( x[ i ] )
  return val

for p in range( 1000, 10000 ):
  if prime( p ) == False:
    continue
  A = []
  for x in permutations( str( p ) ):
    val = toint( x )
    if prime( val ) == True and val > 1000:
      if len( A ) == 0:
        A.append( val )
      elif A[ len( A ) - 1 ] == val - 3330:
        A.append( val )
  if len( A ) == 3:
    S = ""
    for x in A:
      S += str( x )
    print S
