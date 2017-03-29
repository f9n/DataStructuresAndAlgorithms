#ifndef UTIL_H
#define UTIL_H
#include <stdlib.h>
#include <string>
#include <stdarg.h>
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
void displayFriendsOneNode(node * root);
node * insertNewUserWithFriends(node * root, int x, string username, string surname, int args, ...);
node * insertNewUser(node * root, int x, string username, string surname, int * IdOfFriends, int IdOfFriendsAmount);
void displayTreeWithInorder(node * tree);
void destroyFriends(node * tree);
void destroyNodes(node * tree);
#endif // UTIL_H
