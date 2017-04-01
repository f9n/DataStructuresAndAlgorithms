#include "menu.h"

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
      usleep(50 * 1000);
      j += 1;
    }
  }
  cout << endl <<
    "\t" << "######   #######  #########     " << endl <<
    "\t" << "#    ##  #            #         " << endl <<
    "\t" << "#    ##  #            #         " << endl <<
    "\t" << "######   #######      #         " << endl <<
    "\t" << "#    ##        #      #         " << endl <<
    "\t" << "#    ##        #      #         " << endl <<
    "\t" << "######   #######      #     <Assingment 2>     " << endl;
}
void shellMenu(node * root) {
  struct commands commandList[14] = {
    {"exit", "exit the program"}, // 0
    {"clear", "clear screen"}, // 1
    {"help", "listed command list"}, // 2
    {"insertnewuser", "insert a new user"}, // 3
    {"printinorder", "print in order"}, // 4
    {"printgreater", "printing greater all node"}, // 5
    {"getfriends","get frinedns in one node"}, // 6
    {"size", "size of tree"}, // 7
    {"printnext", "print subtree"}, // 8
    {"deleteuser", "deleting a user"}, // 9
    {"contains", "contains IdNo in tree"}, // 10
    {"test", "testing program functions"}, // 11
    {"insertautomatic", "insert users automatic way "}, // 12
    {"insertfile", "insert users from file"} // 13
  };
  string inputStr;
  int inputInt;
  while(1) {
    cout << endl << BOLD(FBLU("bst> "));
    cin >> inputStr;
    if(inputStr == commandList[0].command) {
      break;
    } else if(inputStr == commandList[1].command) {
      system("clear");
    } else if(inputStr == commandList[2].command) {
      cout << "COMMANDS" << endl;
      cout << "========" << endl << endl;
      cout << " " << setw(20) << setfill(' ') << "Command";
      cout << " : " << "Description" << endl;
      cout << " " << setw(20) << setfill(' ') << "-------";
      cout << " : " << "-----------" << endl;
      for(int i = 0; i < 14; i++) {
        cout << " " << setw(20) << setfill(' ')<< commandList[i].command;
        cout << " : " << commandList[i].description << endl;
      }
    } else if(inputStr == commandList[3].command) {
      int IdNo;
      string username, surname;
      int friendsAmount;
      int * friends = NULL;
      cout << FGRN("bst[insert-idno]> ");
      cin >> IdNo;
      cout << FGRN("bst[insert-username]> ");
      cin >> username;
      cout << FGRN("bst[insert-surname]> ");
      cin >> surname;
      cout << FGRN("bst[insert-friendsamount]> ");
      cin >> friendsAmount;
      friends = (int*)malloc(sizeof(int) * friendsAmount);
      for(int i=0; i < friendsAmount; i++) {
        cout << FGRN("bst[insert-friendsId]") << i << FGRN("> ");
        cin >> friends[i];
      }
      cout << "Called insertNewUser function!"<< endl;
      root = insertNewUser(root, IdNo, username, surname, friends, friendsAmount);
      cout << "Inserted All!";
    } else if(inputStr == commandList[4].command) {
      //cout << "bst[printinorder]> " << endl;
      printInOrder(root);
    } else if(inputStr == commandList[5].command) {
      cout << FCYN("bst[print-greater]> Entry IdNo: ");
      cin >> inputInt;
      printGreater(root, inputInt);
    } else if(inputStr == commandList[6].command) {
      cout << FCYN("bst[getFriends]> Entry IdNo: ");
      cin >> inputInt;
      Friends(root, inputInt);
    } else if(inputStr == commandList[7].command) {
      int tree_size = size(root, 0);
      cout << "Tree Size: " << tree_size << endl;
    } else if(inputStr == commandList[8].command) {
      cout << FCYN("bst[printnext]> Entry IdNo: ");
      cin >> inputInt;
      printNext(root, inputInt);
    } else if(inputStr == commandList[9].command) {
      cout << FRED("bst[deleteuser]> Entry IdNo: ");
      cin >> inputInt;
      root = deleteUser(root, inputInt);
    } else if(inputStr == commandList[10].command) {
      cout << FCYN("bst[contains]> Entry IdNo: ");
      cin >> inputInt;
      bool status_contains = contains(root, inputInt);
      if(status_contains != 1) {
        cout << "I'm sorry. There is not a member." << endl;
      }
    } else if(inputStr == commandList[11].command) {
      root = test(root);
    } else if(inputStr == commandList[12].command) {
      root =  automaticInsertUser(root);
    } else if(inputStr == commandList[13].command) {
      cout << FMAG("bst[insertfile]> Entry filename: ");
      cin >> inputStr;
      root = insertUsersFromFile(root, inputStr);
    } else {
      cout << UNDL("Unknown command...Please write `help` command");
    }
  }
}
node * automaticInsertUser(node * root) {
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
  return root;
}
node * test(node * root) {
  cout << endl << "[=] Tree ..." << endl;
  root =  automaticInsertUser(root);
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

  /*
  cout << endl << "[=] Testing getMaxsParentTree Function" << endl;
  node * maxNodeParent = getMaxsParentTree(root);
  cout << "Max Node's Parent in Tree: " << maxNodeParent->IdNo << endl;
  */

  cout << endl << "[=] Testing deleteUser Function" << endl;
  root = deleteUser(root, 80);
  displayTreeWithInorder(root);

  cout << endl << "[=] Testing printNext Function" << endl;
  printNext(root, 30);

  cout << endl << "[=] Testing printGreater Function" << endl;
  printGreater(root, 12);

  cout << endl << "[=] Testing printInOrder Function" << endl;
  printInOrder(root);
  return root;
}

/*

  root->IdOfFriends = (int*)realloc(root->IdOfFriends, sizeof(int))
*/
