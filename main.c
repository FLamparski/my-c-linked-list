#include <stdlib.h>
#include "string.h"
#include "linkedlist.h"
#include "debug.h"

int main() {
  log_info("Creating a linked list.");
  LinkedList* list = ll_new();
  check(list->first == NULL, "List was not correctly initialised.");
  check(list->length == 0, "List should not have any elements.");

  log_info("Adding an element to the list.");
  int v = 1337;
  int* vpointer = malloc(sizeof(int));
  *vpointer = v;
  ll_prepend(list, vpointer);
  check(list->length == 1, "Length increment failed");
  check(list->first != NULL, "Append failed");
  check(list->first->data == vpointer, "Bad address");
  log_info("The address of list->first->data %p",
      list->first->data);
  check(*((int*) list->first->data) == v, "Bad value");
  log_info("The value is %d as expected",
      *((int*) list->first->data));

  log_info("Adding another element.");
  v = 1338;
  int* another = malloc(sizeof(int));
  *another = v;
  ll_prepend(list, another);
  check(list->length == 2, "Length increment failed");
  check(*((int*) list->first->data) == v, "List increment screwed up");

  log_info("Checking list[0].");
  check(*((int*) ll_get(list, 0)) == v, "First element does not match what was last prepended.");
  log_info("Checking list[1].");
  check(*((int*) ll_get(list, 1)) == 1337, "First element does not match what was first prepended.");

  log_info("Freeing the linked list.");
  ll_free(list);
  return 0;
error:
  return 1;
}
