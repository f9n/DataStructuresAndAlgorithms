#include "util.h"
#include "menu.h"
using namespace std;

int main() {
  cout << "Hi, Started Program" << endl;
  node * root = NULL;

  //startingMenu();
  shellMenu(root);

  destroyFriends(root);
  destroyNodes(root);
  return 0;
}
