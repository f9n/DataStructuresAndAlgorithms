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
  root = insertNewUserWithFriends(root, 10, "Okan", "Yeah", 0);
  root = insertNewUserWithFriends(root, 15, "Esra", "Atas", 3, 1, 2, 3);
  root = insertNewUserWithFriends(root, 35, "Emre", "Bugra", 4, 10, 20, 30, 15);
  root = insertNewUserWithFriends(root, 42, "Okan", "Yeah", 0);
  root = insertNewUserWithFriends(root, 5, "Esra", "Atas", 1, 10);
  root = insertNewUserWithFriends(root, 28, "Emre", "Bugra", 2, 80, 90);
  root = insertNewUserWithFriends(root, 80, "Okan", "Yeah", 2, 100, 110);
  displayTreeWithInorder(root);

  cout << endl << "[=] Testing Contains Function" << endl;
  bool status_contains = contains(root, 10);
  cout << "Status: " << status_contains << endl;

  cout << endl << "[=] Testing Friends Function" << endl;
  bool status_friends = Friends(root, 15);
  cout << "Status: " << status_friends << endl;

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
