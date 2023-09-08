#include <stdio.h>

void rotateMatrix(int rows, int cols, int matrix[rows][cols]) 
{
    int i = 0, j = 0, temp, prev, backup;
    prev = matrix[i][j + 1];
    backup = matrix[i][j + 2];

    while (1) 
    {
        temp = matrix[i][j];
        matrix[i][j] = prev;
        prev = temp;

        if (i < rows - 1 && j == 0) 
        {
            ++i;
        } 
        else if ((i == rows - 1 && j == 0) || (i == rows - 1 && j < cols - 1)) 
        {
            ++j;
        }
        else if ((i > 0 || i == rows - 1) && j == cols - 1) 
        {
            --i;
        }
        else if (i == 0 && (j > 1 || j == cols - 1)) 
        {
            --j;
        } 
        else if (i == 0 && j == 1) 
        {
            matrix[i][j] = backup;
            break;
        }
    }
}

int main() 
{
    int numRows, numCols;
    printf("Enter the number of rows and columns: ");
    scanf("%d", &numRows);
    numCols = numRows;

    int matrix[numRows][numCols];

    printf("Enter matrix data:\n");
    for (int i = 0; i < numRows; i++) 
    {
        for (int j = 0; j < numCols; j++) 
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\nOriginal Matrix:\n");
    for (int i = 0; i < numRows; i++) 
    {
        for (int j = 0; j < numCols; j++) 
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    rotateMatrix(numRows, numCols, matrix);

    printf("\nRotated Matrix:\n");
    for (int i = 0; i < numRows; i++)
      {
        for (int j = 0; j < numCols; j++) 
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
