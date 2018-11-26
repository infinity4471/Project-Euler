def modexp( a, b, MOD = 10000000000 ):
  if b == 0:
    return 1
  elif b == 1:
    return a
  val = modexp( a, b / 2 )
  if b % 2 == 0:
    return val * val % MOD
  else:
    return val * val * a % MOD

sum = 0
for i in range( 1, 1001 ):
  sum = ( sum + modexp( i, i ) ) % 10000000000

print sum
