Solve the LP problem with Simplex method under the Tabular form
    
    max f(x) = C[1]*X[1] + C[2]*X[2] +  . . . + C[n]*X[n]
    A[1,1]*X[1] + A[1,2]*X[2] + . . . + A[1,n]*X[n]   <= b[1]
    
    A[2,1]*X[1] + A[2,2]*X[2] + . . . + A[2,n]*X[n]   <= b[2]
             . . .
    A[m,1]*X[1] + A[m,2]*X[2] + . . . + A[m,n]*X[n]   <= b[m]
Domain of variables:   0 <= X[i], for i = 1, 2, ..., n

Input
Line 1: contains 2 positive integer n and m (1 <= n,m <= 1000)

Line n+1: contains C[1], C[2], ..., C[n]

Line n+2+i (i = 1,...,m): contains the ith row of the matrix A: A[i,1], A[i,2], . . ., A[i,n]

Line n+m+2: contains b[1], b[2], ..., b[m]

Output

If the given problem does not have any optimal solution, then write UNBOUNDED. Otherwise, line 1 writes n, and line 2 writes X[1], X[2], ..., X[n] (separated by a SPACE character)

Example

Input
2 3

3 2

2 1

1 2

1 -1

7 8 2

Output

2

2.0 3.0
