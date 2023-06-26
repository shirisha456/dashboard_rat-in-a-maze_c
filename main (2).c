/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

#define n 5

int maze[n][n];
    

int solution[n][n];

void printsolution()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d  ",solution[i][j]);
        }
        printf("\n");
    }
}

int solvemaze(int r, int c)
{

    if((r==n-1) && (c==n-1))
    {
        solution[r][c] = 3;
        return 1;
    }

    if(r>=0 && c>=0 && r<n && c<n && solution[r][c] == 0 && maze[r][c] == 0)
    {
    
        solution[r][c] = 3;

        if(solvemaze(r+1, c))
            return 1;
        if(solvemaze(r, c+1))
            return 1;

        if(solvemaze(r-1, c))
            return 1;

        if(solvemaze(r, c-1))
            return 1;
    
        solution[r][c] = 0;
        return 0;
    }
    return 0;

}

int main()
{

    int i,j;
    printf("Enter the values of cells in the maze\n");
     for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%d", &maze[i][j]);
        }
    }
    printf("Entered maze is\n");
     for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d  ",maze[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            solution[i][j] = 0;
        }
    }
    if (solvemaze(0,0))
        printsolution();
    else
        printf("No solution\n");
    return 0;
}





