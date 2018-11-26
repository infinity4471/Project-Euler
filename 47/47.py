from math import sqrt

def fact( n ):
  primfact = []
  for d in range( 2, int( sqrt( n + 1 ) ) ):
    status = False
    while n % d == 0:
      status = True
      n /= d
    if status == True:
      primfact.append( d )
  if n > 1:
    primfact.append( n )
  return primfact

def valid( X ):
  for i in range( 0, 4 ):
    if len( fact( X + i ) ) != 4:
      return False
  return True

X = 2

while True:
  if valid( X ) == True:
    print X
    break
  X += 1
