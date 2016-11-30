#include <stdlib.h>
#include "linkedlist.h"
#include "debug.h"

LinkedListItem* _ll_item_new(void* data, LinkedListItem* next) {
  LinkedListItem* it = malloc(sizeof(LinkedListItem));
  it->data = data;
  it->next = next;
  return it;
}

void _ll_item_free(LinkedListItem* item) {
  free(item);
}

LinkedList* ll_new() {
  LinkedList* list = malloc(sizeof(LinkedList));
  list->length = 0;
  list->first = NULL;
  list->last = NULL;
  return list;
}

void ll_free(LinkedList* list) {
  if (list->length > 0) {
    LinkedListItem* el = list->first;
    LinkedListItem* previous = NULL;

    while (el) {
      if (previous) {
        _ll_item_free(previous);
      }
      previous = el;
      el = el->next;
    }
  }

  free(list);
}

int ll_prepend(LinkedList* list, void* elt) {
  check(list != NULL, "The list cannot be null!");

  list->first = _ll_item_new(elt, list->first);
  list->length++;

  return list->length;

  error:
    return -1;
}

int ll_length(LinkedList* list) {
  check(list != NULL, "The list cannot be null!");

  return list->length;

  error:
    return -1;
}

void* ll_get(LinkedList* list, int idx) {
  check(list != NULL, "The list cannot be null!");
  check(idx < 0 || list->length > idx, "Range error: idx must be 0 <= idx < %d", list->length);

  LinkedListItem* item = list->first;
  while (idx > 0) {
    item = item->next;
    idx--;
  }
  return item->data;

  error:
    return NULL;
}
