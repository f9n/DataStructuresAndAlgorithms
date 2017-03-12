#ifndef UTIL_H
#define UTIL_H
#include <string>
using namespace std;
void msleep(int s);
void printArraySize(int variable, string show);
int setArraySize2(string show);
void setArraySize(int *variable, string show);
int * catArrayElements(int *array1, int arraysize1, int *array2, int arraysize2);
void printArrayElements(int *array, int arraysize, string show);
int * setArrayElements2(int arraysize, string show);
void setArrayElements(int *array, int arraysize, string show);
void display(int *c, int *linkc, int headc, int nc);
int * merge(int *c, int *linka, int *linkb, int heada, int headb, int na, int nc);

#endif // UTIL_H
