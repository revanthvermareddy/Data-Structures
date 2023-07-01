# https://leetcode.com/problems/set-matrix-zeroes/

from typing import List

class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        
        rows = len(matrix)
        cols = len(matrix[0])
        
        firstRowVal = 1

        for row in range(rows):
            for col in range(cols):
                if matrix[row][col] == 0:
                    matrix[0][col] = 0 # mark the column
                    if row != 0:
                        matrix[row][0] = 0 # mark the row
                    else:
                        firstRowVal = 0

        for row in reversed(range(rows)):
            for col in reversed(range(cols)):
                if row == 0:
                    matrix[row][col] *= firstRowVal
                elif matrix[0][col] == 0 or matrix[row][0] == 0:
                    matrix[row][col] = 0

def printMatrix(matrix):
    for row in matrix:
        for col in row:
            print(col, end=' ')
        print()

if __name__ == "__main__":
    
    matrix = [[1, 1, 1], [1, 0, 1], [1, 1, 1]]
    
    print('\nBefore:')
    printMatrix(matrix)
    
    sol = Solution()
    sol.setZeroes(matrix)
    
    print('\nAfter:')
    printMatrix(matrix)