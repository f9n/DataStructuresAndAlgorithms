#include <iostream>
#include <stdlib.h>
#include "util.h"
using namespace std;

int main() {
  cout << "Naber" << endl;
  node * root = (node *)malloc(sizeof(node));
  root->Left  = NULL;
  root->Right = NULL;
  root->IdNo = 20;
  root->Username = "Ozgur";
  root->Surname  = "Yildirim";
  root->IdOfFriends = (int*)malloc(sizeof(int));
  displayOneNode(root);
  root->IdOfFriends[0] = 5;
  root->IdOfFriendsAmount++;
  displayOneNode(root);
  root->IdOfFriends = (int*)realloc(root->IdOfFriends, sizeof(int));
  root->IdOfFriends[1] = 4;
  root->IdOfFriendsAmount++;
  displayOneNode(root);
  free(root->IdOfFriends);
  free(root);
  return 0;
}
