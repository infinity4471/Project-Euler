def pandigital( S ):
  for dig in range( 1, 10 ):
    cnt = 0
    for x in range( 0, len( S ) ):
      if dig == int( S[ x ] ):
        cnt += 1
    if cnt != 1:
      return False
  return True

max = 0

for X in range( 0, 10000 ):
  S = ""
  for n in range( 1, 100 ):
    S = S + str( n* X )
    if( len( S ) > 9 ):
      break
    if( len( S ) == 9 and pandigital( S ) == True ):
      if( int( S ) > max ):
        max = int( S )
print max
