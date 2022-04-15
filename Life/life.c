//
// Created by spoud on 9/8/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Student information for project:
 *
 * On my honor, Samip Poudel, this programming project is my own work
 * and i have not provided this code to any other student.
 *
 * Name: Samip Poudel
 * email address: s.poudel@utexas.edu
 * UTEID: sp47257
 * Section 5 digit ID: 16000
 *
 */
void populateWorld(char fname[], char *grid[], int *rows, int *numCols){

    //Open file
    FILE *fptr = fopen(fname, "r");

    //Find # of Columns
    char firstRow[1000];
    fgets(firstRow, 1000, fptr);
    *numCols = (int)strlen(firstRow) - 1;


    //Find # of rows and allocate space for each
    int rowCount = 0;
    while (!(feof(fptr))){ // NOLINT(hicpp-signed-bitwise)

        grid[rowCount] = malloc((*numCols + 2) * sizeof(char));

        if (rowCount == 0){
            strcpy(grid[0], firstRow);
        } else {
            fgets(grid[rowCount], *numCols + 2, fptr);      // Columns + 2 accounts for \r\n
        }

        if (strlen(grid[rowCount]) >= *numCols - 1){        // Faulty Row check
            rowCount++;
        }

    }

    *rows = rowCount;

    //Close File
    fclose(fptr);
}

void showWorld(char *grid[], int rows, int numCols){

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < numCols; j++){
            if(grid[i][j] == '0'){
                printf(".");
            }
            else {
                printf("*");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void iterateGeneration(char *grid[], int numRows, int numCols){

    int rows = numRows; int columns = numCols;
    char oldGrid[rows][columns];

    for(int i = 0; i < rows; i++){
        strcpy(oldGrid[i], grid[i]);
    }

    int neighbor;

    //Check 2-D array (i: row, j: column)
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            neighbor = 0;

            //Count neighbors
            if ((oldGrid[i][j+1] == '1') && (j + 1 < columns)){
                neighbor++;
            }
            if ((oldGrid[i][j-1] == '1') && (j - 1 >= 0)){
                neighbor++;
            }
            if ((oldGrid[i+1][j] == '1') && (i + 1 < rows)){
                neighbor++;
            }
            if ((oldGrid[i-1][j] == '1') && (i - 1 >= 0)){
                neighbor++;
            }
            if ((oldGrid[i+1][j+1] == '1') && (j + 1 < columns) && (i + 1 < rows)){
                neighbor++;
            }
            if ((oldGrid[i-1][j+1] == '1') && (j - 1 >= 0) && (i - 1 >= 0)){
                neighbor++;
            }
            if ((oldGrid[i+1][j-1] == '1') && (j + 1 < columns) && (i + 1 < rows)){
                neighbor++;
            }
            if ((oldGrid[i-1][j-1] == '1') && (j - 1 >= 0) && (i - 1 >= 0)){
                neighbor++;
            }

            //Update Cell
            if (neighbor < 2 || neighbor > 3){
                grid[i][j] = '0';
            }
            else if (neighbor == 3){
                grid[i][j] = '1';
            }
        }
    }

}
