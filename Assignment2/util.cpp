#include <iostream>
#include "util.h"

using namespace std;


node * getUser(node * root, int IdNo) {
  if(root != NULL) {
    if(root->IdNo == IdNo) {
      return root;
    } else if(root->IdNo < IdNo) {
      root  = getUser(root->Right, IdNo);
    } else if(root->IdNo > IdNo) {
      root = getUser(root->Left, IdNo);
    }
  }
  return root;
}
bool contains(node * root, int IdNo) {
  node * result = getUser(root, IdNo);
  if(result != NULL) {
    displayIdNoUsernameSurnameOneNode(result);
    return true;
  }
  return false;
}
bool Friends(node * root, int IdNo) {
  node * result = getUser(root, IdNo);
  if(result != NULL) {
    displayFriendsOneNode(result);
    return true;
  }
  return false;
}
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
  parent = insertNewUser(parent, x, username, surname, NULL, 0);
  va_end(ap);
  return parent;
}

void displayFriendsOneNode(node * root) {
  //cout << "### DisplayFriendsOneNode - Login" << endl;
  if(root->IdOfFriends != NULL) {
    //cout << "### DisplayFriendsOneNode - Not Null" << endl;
    for(int i = 0; i < root->IdOfFriendsAmount; i++) {
      cout << "\t" << i << ". friend id: " << root->IdOfFriends[i] << endl;
    }
  }
}
void displayIdNoUsernameSurnameOneNode(node * root) {
  cout << "[+] IdNo: " << root->IdNo << " Username: " << root->Username << " Surname: " << root->Surname << endl;
}
void displayOneNode(node * root) {
  //cout << "### DisplayOneNode - Login" << endl;
  if(root != NULL) {
    //cout << "### DisplayOneNode - Not Null" << endl;
    displayIdNoUsernameSurnameOneNode(root);
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

void destroyFriends(node * tree) {
  if(tree != NULL) {
    free(tree->IdOfFriends);
    destroyFriends(tree->Left);
    destroyFriends(tree->Right);
  }
}
void destroyNodes(node * tree) {
  if(tree != NULL) {
    destroyNodes(tree->Left);
    destroyNodes(tree->Right);
    free(tree);
  }
}

