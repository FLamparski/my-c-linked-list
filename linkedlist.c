#include <stdlib.h>
#include "linkedlist.h"
#include "../debug.h"

LinkedList* ll_new() {
  LinkedList* list = malloc(sizeof(LinkedList));
  list->length = 0;
  list->first = NULL;
  return list;
}

void ll_free(LinkedList* list) {
  if (list->length > 0) {
    LinkedListItem* el = list->first;
    LinkedListItem* previous = NULL;

    while (el) {
      if (el->data) {
        free(el->data);
      }
      if (previous) {
        free(previous);
      }
      previous = el;
      el = el->next;
    }
  }

  free(list->first);
  free(list);
}

int ll_append(LinkedList* list, void* el) {
  LinkedListItem* item = NULL;
  check(list != NULL, "Can't work on a NULL list");
  check(el != NULL, "Elements must not be NULLs");
  debug("Checks passed.");

  item = malloc(sizeof(LinkedListItem));
  debug("Allocated a LinkedListItem memory at %p", item);
  item->next = NULL;
  item->data = el;
  debug("Created a LinkedListItem at %p", item);

  if (!list->first) {
    list->first = item;
  } else {
    sentinel("Not yet implemented!");
  }
  list->length++;
  return list->length;
error:
  if (item) {
    if (item->data) {
      free(item->data);
    }
    free(item);
  }
  return -1;
}
