MAX = 1000000
maxim = 0
a = -1
b = -1
primes = ( MAX + 10 ) * [ 1 ]

def sieve():
  for i in range( 2, MAX ):
    j = 2*i
    while( j < MAX ):
      primes[ j ] = 0
      j += i

def val( x, y, z ):
  return x**2 + x*y + z

sieve()

for aa in range( -1000, 1000 ):
  for bb in range( -1000, 1000 ):
    n = 0
    while( primes[ val( n, aa, bb ) ] == 1 ):
      n += 1
    if( n > maxim ):
      maxim = n
      a = aa
      b = bb

print a * b

