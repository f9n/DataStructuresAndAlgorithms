#include <iostream>
#include "util.h"

using namespace std;

node * insertNewUser(node * parent, int x, string username, string surname, int * IdOfFriends, int IdOfFriendsAmount) {
  /*
    We are inserting user property to binary search tree.
   */
  if(parent == NULL) {
    parent = (node *)malloc(sizeof(node));
    parent->Left  = NULL;
    parent->Right = NULL;
    parent->IdNo = x;
    parent->Username = username;
    parent->Surname  = surname;
    parent->IdOfFriends = IdOfFriends;
    parent->IdOfFriendsAmount = IdOfFriendsAmount;
  } else if(parent->IdNo < x) {
    parent->Right = insertNewUser(parent->Right, x, username, surname, IdOfFriends, IdOfFriendsAmount);
  } else if(parent->IdNo > x) {
    parent->Left = insertNewUser(parent->Left, x, username, surname, IdOfFriends, IdOfFriendsAmount);
  }
  return parent;
}
node * insertNewUserWithFriends(node * parent, int x, string username, string surname, int args, ...) {
  /*
    First, We are calling insertNewUser() function, then we are inserting friends
   */
  va_list ap;
  if(args > 0) {
    int * IdOfFriends = (int*)malloc(sizeof(int) * args);
    int IdOfFriendsAmount = args;
    va_start(ap, args);
    for(int i=0;i < args; i++){
      IdOfFriends[i] = va_arg(ap, int);
    }
    parent = insertNewUser(parent, x, username, surname, IdOfFriends, IdOfFriendsAmount);
  }
  va_end(ap);
  return parent;
}

void displayFriendsOneNode(node * root) {
  //cout << "### DisplayFriendsOneNode - Login" << endl;
  if(root->IdOfFriends != NULL) {
    //cout << "### DisplayFriendsOneNode - Not Null" << endl;
    for(int i = 0; i < root->IdOfFriendsAmount; i++) {
      cout << i << ". friend id: " << root->IdOfFriends[i] << endl;
    }
  }
}
void displayOneNode(node * root) {
  //cout << "### DisplayOneNode - Login" << endl;
  if(root != NULL) {
    //cout << "### DisplayOneNode - Not Null" << endl;
    cout << "[+] IdNo: " << root->IdNo << " Username: " << root->Username << " Surname: " << root->Surname << endl;
    displayFriendsOneNode(root);
  }
}

void displayTreeWithInorder(node * tree) {
  if(tree != NULL) {
    displayTreeWithInorder(tree->Left);
    displayOneNode(tree);
    displayTreeWithInorder(tree->Right);
  }
}

