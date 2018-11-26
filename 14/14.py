def collatz( n ):
  if n == 1:
    return 1
  elif n % 2 == 0:
    return 1 + collatz( n / 2 )
  else:
    return 1 + collatz( 3*n + 1 )

maxim = 0

for i in range( 1, 1000000 ):
  if i % 10000 == 0:
    print i / 10000, '% DONE!!'
  val = collatz( i )
  if val > maxim:
    maxim = val
    maxnum = i
    print maxim, maxnum
