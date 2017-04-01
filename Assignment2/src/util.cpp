#include <iostream>
#include <fstream>
#include "util.h"

using namespace std;

node * insertUsersFromFile(node * root, string filename) {
  //system("ls");
  int id, amount;
  string username, surname;
  int * friends = NULL;
  cout << "Filename: " << filename;
  ifstream infile;
  infile.open(filename);
  if(!infile) {
    cerr << "Unable to open file!" << endl;
    return root;
  }
  // http://stackoverflow.com/questions/21647/reading-from-text-file-until-eof-repeats-last-line
  while(infile >> id) {
    infile >> username;
    infile >> surname;
    infile >> amount;
    friends = (int *)malloc(sizeof(int) * amount);
    if(friends == NULL) {
      cerr << "Allocation Error! In insertUsersFromFile function, allocation friends int array!";
      return root;
    }
    for(int i = 0; i < amount ; i++) {
      infile >> friends[i];
    }
    cout << endl << id << " " << username << " " << surname << " " << amount;
    for(int i =0; i < amount ; i++) {
      cout << " " << friends[i];
    }
    root = insertNewUser(root, id, username, surname, friends, amount);
  }
  infile.close();
  return root;
}
void printInOrder(node * root) {
  displayTreeWithInorder(root);
}
void printGreater(node * root, int IdNo) {
  if(root != NULL) {
    if(root->IdNo > IdNo) {
      printGreater(root->Left, IdNo);
      displayOneNode(root);
      displayTreeWithInorder(root->Right);
    }
    if(root->IdNo < IdNo) {
      printGreater(root->Right, IdNo);
    }
    if(root->IdNo == IdNo) {
      displayOneNode(root);
      displayTreeWithInorder(root->Right);
    }
  }
}
void printNext(node * root, int IdNo) {
  node * user = getUser(root, IdNo);
  if(user == NULL) {
    cerr << "There is not a sub tree" << endl;
    return;
  }
  displayTreeWithInorder(user->Left);
  displayTreeWithInorder(user->Right);
}
node * max(node * root) {
  while(root->Right != NULL) {
    root = root->Right;
  }
  return root;
    /*
  if(root != NULL && root->Right != NULL) {
    root = max(root->Right);
  }
  return root;
    */
}
node * min(node * root) {
  while(root->Left != NULL) {
    root = root->Left;
  }
  return root;
  /*
  if(root != NULL && root->Left != NULL) {
    root = min(root->Left);
  }
  return root;
  */
}

node * deleteUser(node * root, int IdNo) {
  if(root == NULL) {
    return NULL;
  }
  if(root->IdNo == IdNo) {
    if(root->Left == NULL && root->Right == NULL) {
      return NULL;
    }
    if(root->Right != NULL) {
      root = min(root->Right);
      root->Right = deleteUser(root->Right, min(root->Right)->IdNo);
      return root;
    }
    if(root->Left != NULL) {
      root = max(root->Left);
      root->Left = deleteUser(root->Left, max(root->Left)->IdNo);
      return root;
    }
  }
  if(root->IdNo < IdNo) {
    root->Right = deleteUser(root->Right, IdNo);
  }
  if(root->IdNo > IdNo) {
    root->Left = deleteUser(root->Left, IdNo);
  }
  return root;
}
/*
node * deleteUser(node * root, int IdNo) {
  cout << "[.] Entry Function" << endl;
  node * user = getUser(root, IdNo);
  cout << "[.] Runned getUser Function" << endl;
  node * parent = NULL;
  if(user->Left != NULL && user->Right != NULL) {
    // It has double child.
  } else if(user->Left == NULL && user->Right == NULL) {
    // It has not child.
  } else {
    
  }
  node * subTree = user->Left;
  node * parent = getMaxsParentTree(subTree);
  cout << "[.] Runned getMaxsParentTree Function" << endl;
  parent->Right->Right = user->Right;
  parent->Right->Left = user->Left;

  user = parent->Right;
  parent->Right = NULL;
  free()
  return root;
}
*/
int size(node * root, int amount) {
  if(root != NULL) {
    amount++;
    amount += size(root->Left, 0);
    amount += size(root->Right, 0);
  }
  return amount;
}
node * getMaxsParentTree(node * root) {
  /*
    Find max node's parent
   */
  if(root != NULL && root->Right->Right != NULL) {
    root = getMaxsParentTree(root->Right);
  }
  return root;
}
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
    if(parent == NULL) {
      cerr << "Allocation error! From allocation node struct!";
      return parent;
    }
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
    if(IdOfFriends == NULL) {
      cerr << "Allocation error! From allocation IdOfFriends integer array!" << endl;
      return parent;
    }
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
  if(root->IdOfFriends != NULL) {
    for(int i = 0; i < root->IdOfFriendsAmount; i++) {
      cout << "\t" << i << ". friend id: " << root->IdOfFriends[i] << endl;
    }
  }
}
void displayIdNoUsernameSurnameOneNode(node * root) {
  cout << "[+] IdNo: " << root->IdNo << " Username: " << root->Username << " Surname: " << root->Surname << endl;
}
void displayOneNode(node * root) {
  if(root != NULL) {
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
