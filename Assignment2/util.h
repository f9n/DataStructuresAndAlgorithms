#ifndef UTIL_H
#define UTIL_H
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
node * insertNewUser(node * root, int x, string username, string surname);


#endif // UTIL_H
