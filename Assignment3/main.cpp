#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  string *stringArray = readStringsFromFile("kelime.txt");

  free(stringArray);
  return 0;
}
string * readStringsFromFile(string filename) {
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
