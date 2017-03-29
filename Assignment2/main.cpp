#include <iostream>
#include <stdlib.h>
#include "util.h"
using namespace std;

int main() {
  cout << "Naber" << endl;
  node * root = NULL;
  root = insertNewUser(root, 20, "Ozgur", "Yildirim");
  displayOneNode(root);
  displayOneNode(root->Left);
  displayOneNode(root->Right);
  root = insertNewUser(root, 30, "Esra", "Atas");
  displayOneNode(root);
  displayOneNode(root->Left);
  displayOneNode(root->Right);
  root = insertNewUser(root, 40, "Emre", "Bugra");
  displayOneNode(root);
  displayOneNode(root->Left);
  displayOneNode(root->Right);
  /*
  root->IdOfFriends[0] = 5;
  root->IdOfFriendsAmount++;
  displayOneNode(root);
  root->IdOfFriends = (int*)realloc(root->IdOfFriends, sizeof(int));
  root->IdOfFriends[1] = 4;
  root->IdOfFriendsAmount++;
  displayOneNode(root);
  free(root->IdOfFriends);
  */
  free(root);
  return 0;
}
