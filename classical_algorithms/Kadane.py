# Algorithm implementation
def Kadane(a):
  max_current = a[0]
  max_for_all = a[0]
  
  for x in a:
    max_current = max(max_current + x, x)
    max_for_all = max(max_current, max_for_all)
  return max_for_all
  
# Exampple of use
ar = [1, -3, 2, 1, -1]

print(Kadane(ar))
