number = ""
i = 1

while len( number ) <= 1000000:
  number = number + str( i )
  i += 1

prod = 1

for p in range( 0, 7 ):
  dig = 10 ** p
  prod *= int( number[ dig - 1 ] )

print prod
