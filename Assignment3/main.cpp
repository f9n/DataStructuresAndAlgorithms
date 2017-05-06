#include "util.h"
/* I used links
 * http://stackoverflow.com/questions/13035674/how-to-read-line-by-line-or-a-whole-text-file-at-once
 * http://stackoverflow.com/questions/2128728/allocate-matrix-in-c
 *
 */

/* Main Section */
int main() {
  string *stringArray = readStringsFromFile("wordlist.txt");
  int **adjacencyMatrix = allocateMatrix();
  adjacencyMatrix = generateMatrix(adjacencyMatrix, stringArray);
  //displayStringArray(stringArray);
  displayRowFromMatrix(adjacencyMatrix, 0);
  destroyAll(stringArray, adjacencyMatrix);
  return 0;
}
