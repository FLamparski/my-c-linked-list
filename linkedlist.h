#ifndef LINKEDLIST_H
#define LINKEDLIST_H
typedef struct LinkedListItem {
  void* data;
  struct LinkedListItem* next;
} LinkedListItem;

typedef struct LinkedList {
  int length;
  LinkedListItem* first;
  LinkedListItem* last;
} LinkedList;

LinkedListItem* _ll_item_new(void* data, LinkedListItem* next);
void _ll_item_free(LinkedListItem* item);

/**
 * Create a new linked list.
 *
 * @return A pointer to the new list. Please free this with ll_free.
 */
LinkedList* ll_new();

/**
 * Free a linked list :list:.
 */
void ll_free(LinkedList* list);

/**
 * Add the element :elt: to the front of :list:
 *
 * @return The length of the list after this operation.
 */
int ll_prepend(LinkedList* list, void* elt);

/**
 * Get an item at position :index: on the list. List starts with index 0.
 * Please check for NULL.
 *
 * @return The element at :index:, or NULL.
 */
void* ll_get(LinkedList* list, int index);

/**
 * Get the list's length.
 *
 * @returns The list's length or -1 if :list: == NULL
 */
int ll_length(LinkedList* list);

#endif // LINKEDLIST_H
