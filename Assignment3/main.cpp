#include <iostream>
#include <fstream>
#include <string>

#define FILESIZE 2415

using namespace std;

int main() {
  string *stringArray = readStringsFromFile("kelime.txt");
  displayStringArray(stringArray);
  free(stringArray);
  return 0;
}
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
  for(int i=0; i < FILESIZE; i++) {
    cout << i << "  index: " + array[i] << endl;
  }
}
