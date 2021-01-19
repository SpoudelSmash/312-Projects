//life_driver.c
//
//Life Driver program
//Roger Priebe 9/5/2018
//EE 312


/* Student information for project:
 *
 * On my honor, Samip Poudel, this programming project is my own work
 * and I have not provided this code to any other student.
 *
 * Name: Samip Poudel
 * email address: s.poudel@utexas.edu
 * UTEID: sp47257
 * Section 5 digit ID: 16000
 *
 */

//This file is a driver program for the life.c module.
//This program must work with your implementations life.h and life.c
//Do not change the function definitions for populateWorld, showWorld or
//iterateGeneration.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "life.h"


int main(int argc, char *argv[]) {

  //  printf("%s, %s\n", argv[0], argv[1]);           // arg0 is ./life   arg1 is "world.txt"   arg2 = numGeneration

   //edit these two lines and use the command line arguments
   //char fName[] = "world.txt";
   //const int numGenerations  = 5; //set to a smaller number for debugging

   //Get inputs
   char *fName = malloc(50 * sizeof(char));

   strcpy(fName, argv[1]);
   const int numGenerations  = atoi(argv[2]);

   const int MAX_ROWS = 80; //we want the world to fit on one screen

   //array of strings that will hold the grid
   char *world[MAX_ROWS];
   int numRows;
   int numCols;

   populateWorld(fName, world, &numRows, &numCols);
   free(fName);
   showWorld(world, numRows, numCols);

   for (int iteration = 0; iteration < numGenerations; iteration++) {
       // code to clear screen goes here
       //system("cls"); //Windows only
       //printf("WIN\n");
       //for(int i = 1000000000; i > 0; i--);
       system("clear"); //Linux only
       //printf("LINUX\n");

       iterateGeneration(world, numRows, numCols);

       showWorld(world, numRows, numCols);
  }

   for (int i = 0; i <= numRows; i++){
       free(world[i]);
   }

  return 0;
}

