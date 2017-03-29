#include <iostream>
#include "util.h"

using namespace std;

node * insertNewUser(node * root, int x, string username, string surname) {
  node * added = (node*)malloc(sizeof(node));
  added = (node *)malloc(sizeof(node));
  added->Left  = NULL;
  added->Right = NULL;
  added->IdNo = x;
  added->Username = username;
  added->Surname  = surname;
  //root->IdOfFriends = (int*)malloc(sizeof(int));
  if(root == NULL) {
    root = added;
  } else if(root->IdNo < x) {
    root->Right = added;
  } else if(root->IdNo > x) {
    root->Left = added;
  }
  return root;
}

void displayFriendOneNode(node * root) {
  if(root->IdOfFriends != NULL) {
    for(int i = 0; i < root->IdOfFriendsAmount; i++) {
      cout << i << ". friend id: " << root->IdOfFriends[i] << endl;
    }
  }
}
void displayOneNode(node * root) {
  if(root != NULL) {
    cout << "[+] IdNo: " << root->IdNo << " Username: " << root->Username << " Surname: " << root->Surname << endl;
    displayFriendOneNode(root);
  }
}
