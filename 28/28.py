def get_sum( n ):
  if n == 1:
    return 1
  return 4* ( ( n - 2 ) ** 2 ) + 10*( n - 1 ) + get_sum( n - 2 )

print get_sum( 1001 )
