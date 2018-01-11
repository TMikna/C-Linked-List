#ifndef hed
#define hed

int ElementAddition (struct LinkedList **head, struct LinkedList **tail, int *a);
int StrCpy (struct LinkedList **head);
int ElemPrnt (struct LinkedList **head, int *a);
int DelElem (struct LinkedList **head, struct LinkedList **tail, int *a);
int FindSize (struct LinkedList **head);
int FindElem (struct LinkedList **head, int *a);
void errors (int *err);

#endif
