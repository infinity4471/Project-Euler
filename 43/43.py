from itertools import permutations

P = [ 2, 3, 5, 7, 11, 13, 17 ]

def tonum( X ):
  num = 0
  for d in range( 0, len( X ) ):
    num += 10** ( len( X ) - d - 1 ) * X[ d ]
  return num

sum = 0

for X in permutations( range( 0, 10 ) ):
  status = True

  for i in range( 1, 8 ):
    number = tonum( X[ i : i + 3 ] )
    if number % P[ i - 1 ] != 0:
      status = False
  if status == True:
    sum += tonum( X )

print sum
