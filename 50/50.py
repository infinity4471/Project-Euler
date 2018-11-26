from math import sqrt

MAX = 10 ** 6
primes = []

def prime( i ):
  for div in range( 2, int( sqrt( i ) + 1 ) ):
    if i % div == 0:
      return False
  return True

def generate():
  for i in range( 2, MAX ):
    if prime( i ) == True:
      primes.append( i )

generate()

max = 0
answer = 0

for i in range( 0, len( primes ) ):
  sum = 0
  for j in range( i, len( primes ) ):
    sum = sum + primes[ j ]
    if( sum >= MAX ):
      break
    if prime( sum ) == True and j - i + 1 > max:
      answer = sum
      max = j - i + 1
print answer
