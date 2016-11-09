import numpy as np

size = 4
A = np.random.rand(size, size)
U = np.array(A)
L = np.eye(size)
P = np.eye(size)
P_new = np.eye(size)
Q = np.eye(size)
Q_new = np.eye(size)

for i in range(size):
  # if need to permute => permute, store permutation on P (left) and Q (right)
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
  max_pivot_row = i
  max_pivot_col = i
  for j in range(i,size):
    for k in range(i,size):
      if abs(U[j,k]) > abs(U[max_pivot_row,max_pivot_col]):
        max_pivot_row = j
        max_pivot_col = k
  # Row permutation
  temp_row = np.array(U[i])
  U[i] = U[max_pivot_row]
  U[max_pivot_row] = temp_row
  temp_row = np.array(L[i,0:i])
  L[i,0:i] = L[max_pivot_row,0:i]
  L[max_pivot_row,0:i] = temp_row
  P_new = np.eye(size)
  P_new[i,i] = 0
  P_new[max_pivot_row,max_pivot_row] = 0
  P_new[i,max_pivot_row] = 1
  P_new[max_pivot_row,i] = 1
  P = np.dot(P_new, P)
  # Column permutation
  temp_col = np.array(U[:,i])
  U[:,i] = U[:,max_pivot_col]
  U[:,max_pivot_col] = temp_col
  Q_new = np.eye(size)
  Q_new[i,i] = 0
  Q_new[max_pivot_col,max_pivot_col] = 0
  Q_new[i,max_pivot_col] = 1
  Q_new[max_pivot_col,i] = 1
  Q = np.dot(Q, Q_new)

  # once permuted, continue with elimination
  for j in range(i+1,size):
    L[j,i] = U[j,i] / U[i,i]
    for k in range(i,size):
      if k==i:
        U[j,k] = 0.0
      else:
        U[j,k] -= L[j,i] * U[i,k]

print A
print
print U
print
print L
print
print P
print
print Q
print
print np.dot(np.dot(np.transpose(P),np.dot(L,U)),np.transpose(Q))
print
print np.dot(np.dot(np.transpose(P),np.dot(L,U)),np.transpose(Q)) - A
print
