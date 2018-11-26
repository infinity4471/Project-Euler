MAX = 10000

def find( A, val ):
  lo, hi = 0 , len( A )
  while lo <= hi:
    mid = ( lo + hi ) / 2
    if A[ mid ] < val:
      lo = mid + 1
    elif A[ mid ] > val:
      hi = mid - 1
    else:
      return True
  return False

pentagonal = [2, 4, 8, 15 ]

for n in range( 1, MAX ):
  pentagonal.append( n * ( 3*n - 1 ) / 2 )

for i in range( 0, len( pentagonal ) ):
  for j in range( i + 1, len( pentagonal ) ):
    val1, val2 = pentagonal[ i ], pentagonal[ j ]
    if( find( pentagonal, val2 - val1 ) == True and find( pentagonal, val2 + val1 ) == True ):
      print val2 - val1
