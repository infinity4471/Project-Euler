MAX = 100000

triangle = []
pentagonal = []
hexagonal = []

for n in range( 1, MAX ):
  triangle.append( n * ( n + 1 ) / 2 )
  pentagonal.append( n * ( 3*n - 1 ) / 2 )

pos = 0
for x in triangle:
  while( pentagonal[ pos ] < x ):
    pos += 1
  if pentagonal[ pos ] == x:
    print x

