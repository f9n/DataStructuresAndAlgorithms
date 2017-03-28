#include <iostream>
#include "util.h"

using namespace std;

void insertNewUser(node * root, int x, string username, string surname) {

}

void displayFriendOneNode(node * root) {
  if(root->IdOfFriends != NULL) {
    for(int i = 0; i < root->IdOfFriendsAmount; i++) {
      cout << i << ". friend id: " << root->IdOfFriends[i] << endl;
    }
  }
}
void displayOneNode(node * root) {
  cout << "[+] IdNo: " << root->IdNo << " Username: " << root->Username << " Surname: " << root->Surname << endl;
  displayFriendOneNode(root);
}
