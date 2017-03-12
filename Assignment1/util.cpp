#include <iostream>  // cout, cin
#include <stdio.h>   // printf
#include <stdlib.h>  // malloc
#include <unistd.h>
#include "util.h"

using namespace std;
void msleep(int s) {
  usleep(s * 1000);
}
void printArraySize(int variable, string show){
  cout << show << ":" <<variable << endl;
}
int setArraySize2(string show) {
  int variable;
  cout << show << ":";
  cin >> variable;
  return variable;
}
void setArraySize(int *variable, string show) {
  cout << show << ":";
  cin >> *variable;
}
int * catArrayElements(int *array1, int arraysize1, int *array2, int arraysize2) {
  cout << "[+] In Cat Array Elements " << endl;
  int *newArray = (int *)malloc((arraysize1 + arraysize2) * sizeof(int));
  int i = 0;
  for(int j=0; j < arraysize1; j++) {
    newArray[i] = array1[j];
    i++;
  }
  for(int j=0; j < arraysize2; j++) {
    newArray[i] = array2[j];
    i++;
  }
  cout << "[+] Outing Cat Array Elements " << endl;
  return newArray;
}
void printArrayElements(int *array, int arraysize, string show) {
  for(int i=0; i < arraysize; i++) {
    cout << show;
    printf("[%d]=%d\n", i, array[i]);
  }
}
int * setArrayElements2(int arraysize, string show) {
  int *newArray = (int *)malloc(arraysize * sizeof(int));
  if (newArray == NULL) {
    printf("Error allocation memory! For ");
    cout << show << endl;
    exit(1);
  }
  for(int i=0; i < arraysize; i++) {
    cout << show;
    printf("[%d]=", i);
    cin >> newArray[i];
  }
  return newArray;
}
void setArrayElements(int *array, int arraysize, string show) {
  cout << arraysize << endl;
  for(int i=0; i < arraysize; i++) {
    cout << show;
    printf("[%d]=", i);
    cin >> array[i];
  }
}
void display(int *c, int *linkc, int headc, int nc) {
  while(linkc[headc] != -1) {
    cout << c[headc] << " ";
    headc = linkc[headc];
  }
}
int * merge(int *c, int *linka, int *linkb, int heada, int headb, int na, int nc) {
  cout << "[+] In Merge Function" << endl;
  cout << "Na and Nc "<< na << " " << nc << endl;
  int *linkc = (int *)malloc(sizeof(int) * nc);
  int headc, buffer; // buffer is next
  cout << "[-] HeadA HeadB HeadC Buffer: " << heada << " " << headb << " " << headc << " " << buffer << endl;

  // Burda ilk buffer, ve headc degerini aliyoruz. buffer, gelecegi goren deger diyelim. headc de linkli dizide suanlik durumu(indexi).
  if (c[heada] < c[na+headb]) {
    headc = heada;
    heada = linka[heada];
    buffer = heada;
  } else {
    headc = na + headb;
    headb = linkb[headb];
    buffer = na + headb;
  }
  // Devamli heada ve headb yi ilerlettigimiz icin 2 side -1 oldugunda demekki merge edecek bir sey kalmadi.
  while(heada != -1 or headb != -1) {
    cout << "[-] Before: HeadA HeadB HeadC Buffer: " << heada << " " << headb << " " << headc << " " << buffer << endl;
    printArrayElements(linkc, nc, "linkc");
    msleep(2000);
    // linkc dizinin headc deki yerine yani suanki durumuna, gelecegi goren buffer degerini veriyoruz.
    linkc[headc] = buffer;
    cout << "[-] After: HeadA HeadB HeadC Buffer: " << heada << " " << headb << " " << headc << " " << buffer << endl;
    printArrayElements(linkc, nc, "linkc");
    msleep(2000);
    cout << c[heada] << " < " << c[na+headb] << endl;
    // heada ve headb nin degerleri kendi linkli dizilerindeki sinirlari cikamiyor. 0 < heada < na , 0 < headb < nb
    // buffer ve headc ise 0 < x < nc
    // Suanki durumu karsilastirip bir sonraki adimda nereye atlayacagimiz buluyoruz.
    // Esitlege kadar her sey iyi sonra patliyor.

    if (c[heada] < c[na+headb]) {
      cout << "c[heada] < c[na+headb]" << endl;
      headc = buffer;
      heada = linka[heada];
      buffer = heada;
    } else if(c[heada] > c[na+headb]){
      cout << "c[heada] > c[na+headb]" << endl;
      headc = buffer;
      headb = linkb[headb];
      buffer = headb + na;
    } else {
      cout << "c[heada] == c[na+headb]" << endl;
      headc = buffer;
      buffer = headb + na;
      headb = linkb[headb];
    }
  }
  linkc[headc] = -1;

  cout << "[+] Outing Merge Function" << endl;
  return linkc;
}
