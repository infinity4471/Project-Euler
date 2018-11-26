def modexp( a, b ):
  if b == 0:
    return 1
  if b == 1:
    return a
  val = modexp( a, b / 2 )
  if b % 2 == 0:
    return val * val
  else:
    return ( val * val ) * a

A = []

cnt = 0

for a in range( 2, 101 ):
  for b in range( 2, 101 ):
    val = modexp( a, b )
    if( not( val in A ) ):
      A.append( val )
      cnt += 1

print cnt
