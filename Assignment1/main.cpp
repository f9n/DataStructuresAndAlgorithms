/*
  $gcc --version : 6.3.1 20170306
 */
#include <stdlib.h>  // free
#include "util.h"
using namespace std;

int main(int argc, char* argv[]) {
  // Ister sabit array lerde degisiklik yapip analiz edebiliriz, ya da fonksiyonlari cagirmaya izin verilerek tek tek biz gireriz.
  int NA = 5, NB = 5, NC;
  //setArraySize(&NA, "NA");
  //setArraySize(&NB, "NB");
  NC = NA + NB;
  int a[] = {9, 2, 5, 1, 7};
  int b[] = {8, 4, 11, 6, 3};
  int linka[] = {-1, 2, 4, 1, 0};
  int linkb[] = {2, 3, -1, 0, 1};
  int * A = a;//setArrayElements2(NA, "A");
  int * B = b;//setArrayElements2(NB, "B");
  int * LinkA = linka;//setArrayElements2(NA, "LinkA");//
  int * LinkB = linkb;//setArrayElements2(NB, "LinkB");//
  int HeadA = 3;//setArraySize2("HeadA");//3;
  int HeadB = 4;//setArraySize2("HeadB"); //4; // HeadA and HeadB are not array size.
  int * C = catArrayElements(A, NA, B, NB);
  int HeadC = C[HeadA] < C[NA+HeadB] ? HeadA : (NA+HeadB);
  //printArraySize(HeadA, "HeadA");
  int * LinkC = merge(C, LinkA, LinkB, HeadA, HeadB, NA, NC);
  display(C, LinkC, HeadC, NC);

  free(A);
  free(B);
  free(LinkA);
  free(LinkB);
  free(LinkC);
  free(C);
  return 0;
}
