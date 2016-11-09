import numpy as np

size = 4
A = np.random.rand(size, size)
U = np.array(A)
L = np.eye(size)

for i in range(size):
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
print np.dot(L,U)
print np.dot(L,U) - A
