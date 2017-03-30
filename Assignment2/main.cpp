#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include "util.h"
using namespace std;

void startingMenu();
node * test(node * root);
void shellMenu(node * root);
int main() {
  cout << "Hi, Started Program" << endl;
  node * root = NULL;

  //startingMenu();
  shellMenu(root);
  //test(root);

  destroyFriends(root);
  destroyNodes(root);
  return 0;
}

void startingMenu() {
  string starting ="Starting the Project";
  string starting2;
  for(int i=1; i < 5; i++) {
    char ch;
    int j = 1;
    while(j < 20) {
      starting2 = starting;
      starting2[j] = isupper(starting2[j]) ? tolower(starting2[j]) : toupper(starting2[j]);
      switch(j % 3) {
      case 0: ch = '/'; break;
      case 1: ch = '-'; break;
      case 2: ch = '\\';break;
      }
      system("clear");
      cout << "[+] " << starting2 << "..." << ch << endl;
      usleep(100 * 1000);
      j += 1;
    }
  }
}
void shellMenu(node * root) {
  string inputStr;
  int inputInt;
  string commandList[10] = {"insertuser", "printinorder", "test",
                           "contains", "exit", "help", "clear",
                            "printgreater", "getfriends", "size"};
  string commandListDescription[10] = {"insert a new user", "print in order", "testing command",
                                      "contains idno in tree", "exit the program", "listing command list",
                                       "clear screen", "printing greater id no", "get friends in node",
                                       "size of tree"};
  while(1) {
    cout << endl << "bst> ";
    cin >> inputStr;
    if(inputStr == commandList[4]) {
      break;
    } else if(inputStr == commandList[6]) {
      system("clear");
    } else if(inputStr == commandList[5]) {
      cout << "\tCOMMAND LIST" << endl;
      for(int i = 0; i < 10; i++) {
        cout << " " << commandList[i] << "  : " + commandListDescription[i] << endl;
      }
    } else if(inputStr == commandList[0]) {
      int IdNo;
      string username, surname;
      int friendsAmount;
      int * friends = NULL;
      cout << "bst[insert-idno]> ";
      cin >> IdNo;
      cout << "bst[insert-username]> ";
      cin >> username;
      cout << "bst[insert-surname]> ";
      cin >> surname;
      cout << "bst[insert-friendsamount]> ";
      cin >> friendsAmount;
      friends = (int*)malloc(sizeof(int) * friendsAmount);
      for(int i=0; i < friendsAmount; i++) {
        cout << "bst[insert-friendsId]" << i << "> ";
        cin >> friends[i];
      }
      root = insertNewUser(root, IdNo, username, surname, friends, friendsAmount);
      cout << "Inserted All!";
    } else if(inputStr == commandList[1]) {
      cout << "PrintInOrder..." << endl;
      printInOrder(root);
    } else if(inputStr == commandList[2]) {
      root = test(root);
    } else if(inputStr == commandList[3]) {
      cout << "bst[contains]> Entry IdNo: ";
      cin >> inputInt;
      bool status_contains = contains(root, inputInt);
      if(status_contains != 1) {
        cout << "I'm sorry. There is not a member." << endl;
      }
    } else if(inputStr == commandList[7]) {
      cout << "bst[print-greater]> Entry IdNo: ";
      cin >> inputInt;
      printGreater(root, inputInt);
    } else if(inputStr == commandList[8]) {
      cout << "bst[getFriends]> EntryIdNo: ";
      cin >> inputInt;
      Friends(root, inputInt);
    } else if(inputStr == commandList[9]) {
      int tree_size = size(root, 0);
      cout << "Tree Size: " << tree_size << endl;
    } else {
      cout << "Unknown command...";
    }
  }
}
node * test(node * root) {
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

  cout << endl << "[=] Testing size Function" << endl;
  int tree_size = size(root, 0);
  cout << "Tree Size: " << tree_size << endl;

  cout << endl << "[=] Testing max Function" << endl;
  node * max_node = max(root); // Maybe it return NULL
  cout << "Max IdNo: " << max_node->IdNo << endl;

  cout << endl << "[=] Testing min Function" << endl;
  node * min_node = min(root); // Maybe it return NULL
  cout << "Min IdNo: " << min_node->IdNo << endl;

  cout << endl << "[=] Testing getMaxsParentTree Function" << endl;
  node * maxNodeParent = getMaxsParentTree(root);
  cout << "Max Node's Parent in Tree: " << maxNodeParent->IdNo << endl;

  /*
  cout << endl << "[=] Testing deleteUser Function" << endl;
  root = deleteUser(root, 80);
  displayTreeWithInorder(root);
  */

  cout << endl << "[=] Testing printNext Function" << endl;
  printNext(root, 30);

  cout << endl << "[=] Testing printGreater Function" << endl;
  printGreater(root, 12);

  cout << endl << "[=] Testing printInOrder Function" << endl;
  printInOrder(root);
  return root;
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
