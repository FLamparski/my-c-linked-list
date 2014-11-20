#ifndef LINKEDLIST_H
#define LINKEDLIST_H
typedef struct LinkedListItem {
  struct LinkedListItem* next;
  void* data;
} LinkedListItem;

typedef struct LinkedList {
  int length;
  LinkedListItem* first;
} LinkedList;

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
 * Append an item to the linked list.
 *
 * @return The new length of the list, or -1 if the operation failed.
 */
int ll_append(LinkedList* list, void* el);

/**
 * Prepend an item to the linked list (insert at start).
 *
 * @return The new length of the list, or -1 if the operation failed.
 */
int ll_push(LinkedList* list, void* el);

/**
 * Insert an element at position :index: on the list.
 *
 * @return The new length of the list, or -1 if the operation failed.
 */
int ll_insert_at(LinkedList* list, int index, void* el);

/**
 * Replace a value of :list:[:index:] with :el:
 *
 * @return The old value at position :index:, or NULL if the operation fails.
 */
void* ll_replace_at(LinkedList* list, int index, void* el);

/**
 * Get an item at position :index: on the list. List starts with index 0.
 * Please check for NULL.
 *
 * @return The element at :index:, or NULL.
 */
int ll_get(LinkedList* list, int index);

/**
 * Remove an element from the start of the list and return it.
 * Please check for NULL.
 *
 * @return The element that was removed, or NULL if the operation failed.
 */
void* ll_pop(LinkedList* list);

/**
 * Remove an element from the position :index: and return it.
 * Please check for NULL.
 *
 * @return The element that was removed, or NULL if the operation failed.
 */
void* ll_remove(LinkedList* list, int index);

/**
 * Get the list's length.
 *
 * @returns The list's length or -1 if :list: == NULL
 */
int ll_length(LinkedList* list);

#endif // LINKEDLIST_H
