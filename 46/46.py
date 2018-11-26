from math import sqrt

def prime( n ):
  for d in range( 2, int( sqrt( n + 1 ) ) ):
    if n % d == 0:
      return False
  return True

primes = [ 2 ]
X = 3

while( True ):
  status = False
  for p in primes:
    val = X - p
    sq = int( sqrt( val / 2 ) )
    if( sq**2 == val / 2 ):
      status = True
  if prime( X ) == True:
    primes.append( X )
  elif( status == False ):
    print X
    break
  X += 2
