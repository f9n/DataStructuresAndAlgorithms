#include <iostream>
#include <stdlib.h>
#include "util.h"
using namespace std;

int main() {
  cout << "Hi, Started Program" << endl;
  node * root = NULL;
  cout << endl << "[=] Tree ..." << endl;
  root = insertNewUserWithFriends(root, 20, "Ozgur", "Yildirim", 2, 4, 5);
  root = insertNewUserWithFriends(root, 30, "Esra", "Atas", 1, 3);
  root = insertNewUserWithFriends(root, 40, "Emre", "Bugra", 1, 6);
  root = insertNewUserWithFriends(root, 50, "Okan", "Yeah", 0);
  displayTreeWithInorder(root);

  destroyFriends(root);
  destroyNodes(root);
  return 0;
}

/*
  root->IdOfFriends[0] = 5;
  root->IdOfFriendsAmount++;
  displayOneNode(root);
  root->IdOfFriends = (int*)realloc(root->IdOfFriends, sizeof(int));
  root->IdOfFriends[1] = 4;
  root->IdOfFriendsAmount++;
  displayOneNode(root);
*/
