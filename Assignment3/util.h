#ifndef UTIL_H
#define UTIL_H
#include <iostream>
#include <string>
// #include <stdlib.h>
using namespace std;
/* VARIABLES */
#define FILESIZE 2415
#define STRINGSIZE 5

/* Prototypes */
string *readStringsFromFile(string filename);
void displayStringArray(string * array);
int **allocateMatrix();
void destroyAll(string *stringArray, int **matrix);
void displayMatrix(int **adjancencyMatrix);
void displayColFromMatrix(int **adjacencyMatrix, int col);
void displayRowFromMatrix(int **adjacencyMatrix, int row);
int compare(string string1, string string2);
int **generateMatrix(int **adjancencyMatrix, string *stringArray);
int searchStringFromStringArrayAndReturnIndex(string *stringArray, string tempString);
void test(int **adjancencyMatrix, string *stringArray, string string1, string string2);

#endif // UTIL_H
