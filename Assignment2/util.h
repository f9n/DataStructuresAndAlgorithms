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
void displayIdNoUsernameSurnameOneNode(node * root);
void displayFriendsOneNode(node * root);
void displayTreeWithInorder(node * tree);

node * insertNewUserWithFriends(node * root, int x, string username, string surname, int args, ...);
node * insertNewUser(node * root, int idno, string username, string surname, int * IdOfFriends, int IdOfFriendsAmount);

node * getUser(node * root, int IdNo);
bool contains(node * root, int IdNo);
bool Friends(node * root, int IdNo);
node * deleteUser(node * root, int IdNo);
int size(node * tree, int amount);
void printNext(node * tree, int IdNo);

node * max(node * tree);
node * min(node * tree);
node * getMaxsParentTree(node * tree);

void destroyFriends(node * tree);
void destroyNodes(node * tree);
#endif // UTIL_H
