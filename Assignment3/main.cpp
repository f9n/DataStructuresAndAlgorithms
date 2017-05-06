#include <iostream>
#include <fstream>
#include <string>

using namespace std;
/* I used links
 * http://stackoverflow.com/questions/13035674/how-to-read-line-by-line-or-a-whole-text-file-at-once
 *
 */

/* VARIABLES */
#define FILESIZE 2415
#define STRINGSIZE 5

/* Prototypes */
string *readStringsFromFile(string filename);
void displayStringArray(string * array);

/* Main Section */
int main() {
  string *stringArray = readStringsFromFile("wordlist.txt");
  displayStringArray(stringArray);
  free(stringArray);
  return 0;
}

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
