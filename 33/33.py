def cancel( a, b ):
  a1, a2 = a % 10, a / 10
  b1, b2 = b % 10, b / 10
  if a1 == b1:
    return float( a2 ) / float( b2 )
  elif a1 == b2:
    return float( a2 ) / float( b1 )
  elif a2 == b2:
    return float( a1 ) / float( b1 )
  elif a2 == b1:
    return float( a1 ) / float( b2 )
  else:
    return 1

def gcd( a, b ):
  if b == 0:
    return a
  else:
    return gcd( b, a % b )

nom, denom = 1, 1

for a in range( 10, 100 ):
  for b in range( a + 1, 100 ):
    if a % 10 == 0 or b % 10 == 0:
      continue
    val = cancel( a, b )
    if val == float( a ) / float( b ):
      nom *= a
      denom *= b
g = gcd( nom, denom )
denom /= g
print denom
