#ifndef _MENU_H
#define _MENU_H
#include <iostream>
#include <unistd.h>
#include <iomanip>
#include "util.h"

struct commands {
  string command;
  string description;
};

void startingMenu();
void shellMenu(node * root);
node * automaticInsertUser(node * root);
node * test(node * root);

#endif // MENU_H
