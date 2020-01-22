# Longest Common Subarray

s1 = "AEDFHR"
s2 = "ABCDGH"

def lcs(X,Y):
    
    m = len(X)
    n = len(Y)
    
    rows = m + 1
    cols = n + 1
    
    # L = [[0]*cols]*rows
    L = [[None]*(cols) for i in range(rows)]
    
    for i in range(rows):
        for j in range(cols):
            # First row and column equal to zero
            if(i==0 or j==0):
                L[i][j] = 0
            # When characters are equal, increase the diagonal element by 1
            elif X[i-1] == Y[j-1]:
                L[i][j] = L[i-1][j-1] + 1
                print(X[i-1], end=' ')
            # When characters are not equal take max(top,left)
            else:
                L[i][j] = max(L[i-1][j], L[i][j-1])
    print('')
    
    # print("Result array : ")
    # for row in L:
    #     print(row)

    return L[m][n]

print('Longest Common Sub-Sequence : ', end=' ')
print('Length : ', lcs(s1,s2))