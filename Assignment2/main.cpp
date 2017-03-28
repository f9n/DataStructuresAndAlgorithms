#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

struct n {
  int IdNo;
  string Username;
  string Surname;
  int * IdOfFriends = NULL;
  int IdOfFriendsAmount = 0;
  n * Left;
  n * Right;
};
typedef struct n node;

void displayOneNode(node * root);
void displayFriendOneNode(node * root);
void insertNewUser(node * root, int x, string username, string surname);

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
int main() {
  cout << "Naber" << endl;
  node * root = (node *)malloc(sizeof(node));
  root->Left  = NULL;
  root->Right = NULL;
  root->IdNo = 20;
  root->Username = "Ozgur";
  root->Surname  = "Yildirim";
  root->IdOfFriends = (int*)malloc(sizeof(int));
  displayOneNode(root);
  root->IdOfFriends[0] = 5;
  root->IdOfFriendsAmount++;
  displayOneNode(root);
  root->IdOfFriends = (int*)realloc(root->IdOfFriends, sizeof(int));
  root->IdOfFriends[1] = 4;
  root->IdOfFriendsAmount++;
  displayOneNode(root);
  free(root->IdOfFriends);
  free(root);
  return 0;
}
