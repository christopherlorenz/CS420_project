import numpy as np

size = 4
A = np.random.rand(size, size)
U = np.array(A)
L = np.eye(size)
P = np.eye(size)
P_new = np.eye(size)

for i in range(size):
  # if need to permute => permute and store permutation on P
  """
  if U[i,i] < 1e-5:
    max_pivot = i
    for j in range(i+1,size):
      if abs(U[j,i]) > abs(U[max_pivot,i]): max_pivot = j
    temp_row = np.array(U[i])
    U[i] = U[max_pivot]
    U[max_pivot] = temp_row
    P[i,i] = 0
    P[max_pivot,max_pivot] = 0
    P[i,max_pivot] = 1
    P[max_pivot,i] = 1
  """
  # Finding maximum value of columng i
  max_pivot = i
  for j in range(i+1,size):
    if abs(U[j,i]) > abs(U[max_pivot,i]): max_pivot = j
  # Permuting
  temp_row = np.array(U[i])
  U[i] = U[max_pivot]
  U[max_pivot] = temp_row
  temp_row = np.array(L[i,0:i])
  L[i,0:i] = L[max_pivot,0:i]
  L[max_pivot,0:i] = temp_row
  # Computing new combined permutation matrix
  P_new = np.eye(size)
  P_new[i,i] = 0
  P_new[max_pivot,max_pivot] = 0
  P_new[i,max_pivot] = 1
  P_new[max_pivot,i] = 1
  print 'P_new =\n', P_new
  P = np.dot(P_new, P)

  # once permuted, continue with elimination
  for j in range(i+1,size):
    L[j,i] = U[j,i] / U[i,i]
    for k in range(i,size):
      if k==i:
        U[j,k] = 0.0
      else:
        U[j,k] -= L[j,i] * U[i,k]

print A
print U
print L
print P
print np.dot(np.transpose(P),np.dot(L,U))
print np.dot(np.transpose(P),np.dot(L,U)) - A
