#include <iostream>
#include "util.h"

using namespace std;

node * insertNewUser(node * parent, int x, string username, string surname) {
  if(parent == NULL) {
    parent = (node *)malloc(sizeof(node));
    parent->Left  = NULL;
    parent->Right = NULL;
    parent->IdNo = x;
    parent->Username = username;
    parent->Surname  = surname;
    //root->IdOfFriends = (int*)malloc(sizeof(int));
  } else if(parent->IdNo < x) {
    parent->Right = insertNewUser(parent->Right, x, username, surname);
  } else if(parent->IdNo > x) {
    parent->Left = insertNewUser(parent->Left, x, username, surname);
  }
  return parent;
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

void displayTreeWithInorder(node * tree) {
  if(tree != NULL) {
    displayTreeWithInorder(tree->Left);
    displayOneNode(tree);
    displayTreeWithInorder(tree->Right);
  }
}
