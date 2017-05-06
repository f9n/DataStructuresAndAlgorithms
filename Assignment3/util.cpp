#include <fstream>
#include "util.h"

/* Functions */
string * readStringsFromFile(string filename) {
  cout << "[+] Runned readStringsFromFile function" << endl;
  /* Allocate stringArray */
  string * stringArray = (string *)malloc(sizeof(string)*FILESIZE);
  /* Read File */
  string tempString;
  int index = 0;
  ifstream readFile(filename);
  if(readFile.is_open()) {
    while(getline(readFile, tempString)) {
      // cout << index << " " << tempString << endl;
      stringArray[index] = tempString;
      index++;
    }
    readFile.close();
  }
  return stringArray;
}
void displayStringArray(string * array) {
  cout << "[+] Runned displayStringArray function" << endl;
  for(int i=0; i < FILESIZE; i++) {
    cout << i << "  index: " + array[i] << endl;
  }
}
int **allocateMatrix() {
  cout << "[+] Runned allocateMatrix function" << endl;
  int **adjacencyMatrix = (int**)malloc(FILESIZE * sizeof(int*));
  for(int index=0;index<FILESIZE;index++) {
    adjacencyMatrix[index] = (int*)malloc(FILESIZE * sizeof(int));
  }
  return adjacencyMatrix;
}
void destroyAll(string *stringArray, int **matrix) {
  cout << "[+] Runned destroyAll function" << endl;
  free(stringArray);
  for(int i = 0; i < FILESIZE; i++) {
    free(matrix[i]);
  }
  free(matrix);
}
void displayMatrix(int **adjancencyMatrix) {
  cout << "[+] Runned displayMatrix function" << endl;
  for(int row=0; row < FILESIZE; row++) {
    displayRowFromMatrix(adjancencyMatrix, row);
  }
}
void displayColFromMatrix(int **adjacencyMatrix, int col) {
  cout << col << " col:" << endl;
  for(int index=0; index < FILESIZE; index++) {
    cout << adjacencyMatrix[index][col] << " ";
  }
  cout << endl;
}
void displayRowFromMatrix(int **adjacencyMatrix, int row) {
  cout << row << " row:" << endl;
  for(int index=0; index < FILESIZE; index++) {
    cout << adjacencyMatrix[row][index] << " ";
  }
  cout << endl;
}
int **generateMatrix(int **adjancencyMatrix, string *stringArray) {
  cout << "[+] Runned generateMatrix Function" << endl;
  for(int row=0; row < FILESIZE; row++) {
    adjancencyMatrix[row][row] = 0;
    for(int col=row+1; col < FILESIZE; col++) {
      adjancencyMatrix[row][col] = compare(stringArray[row], stringArray[col]);
      adjancencyMatrix[col][row] = adjancencyMatrix[row][col];
    }
  }
  return adjancencyMatrix;
}
int compare(string string1, string string2) {
  int flag = 0;
  for(int i=0; i < STRINGSIZE; i++) {
    if(string1[i] != string2[i]) {
      flag++;
    }
  }
  if(flag == 1) {
    //cout << "String1: " << string1 << endl;
    //printf( " String2: %s\n", string2.c_str());
    return 1;
  }
  return 0;
}
void test(int **adjancencyMatrix, string *stringArray, string string1, string string2) {
  int xIndex = searchStringFromStringArrayAndReturnIndex(stringArray, string1);
  int yIndex = searchStringFromStringArrayAndReturnIndex(stringArray, string2);
  if(xIndex == -1 || yIndex == -1) {
    cout << "String is not found in string array! xIndex:" << xIndex << " yIndex:" << yIndex << endl;
    return;
  }
  if(adjancencyMatrix[xIndex][yIndex] == 1) {
    cout << "There is a one-letter change between two words." << endl;
  } else {
    cout << "There is not a one-letter change between two words." << endl;
  }
}
int searchStringFromStringArrayAndReturnIndex(string *stringArray, string tempString) {
  for(int index = 0; index < FILESIZE; index++) {
    cout << stringArray[index] << endl;
    cout << ' ' << tempString << endl;
    if(stringArray[index] == tempString) {
      return index;
    }
  }
  return -1;
}
