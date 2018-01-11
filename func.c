
#include <stdio.h>
#include <string.h>

struct LinkedList
{
    int sk;
    struct LinkedList* next;
    struct LinkedList* previous;
};

int ElementAddition (struct LinkedList **head, struct LinkedList **tail, int *a)
{
    struct LinkedList *ToNew = NULL;
    struct LinkedList *temp = NULL;

    ToNew=(struct LinkedList*)malloc(sizeof (struct LinkedList));
    if (ToNew == NULL)
        return 10;
    ToNew->sk = *a;
    if (*head == NULL)
    {
        *head = ToNew;
        *tail = ToNew;
        ToNew->next = NULL;
        ToNew->previous = NULL;
    }
    else
    {
        temp = *head;
        while(temp->next != NULL)
            temp = temp->next;
        ToNew->previous = temp;
        temp->next = ToNew;
        ToNew->next = NULL;
        *tail=ToNew;
    }

    return 0;
}



int ListPrnt (struct LinkedList **head)
{
    struct LinkedList *ToPrnt = *head;

    if(*head != NULL)
    {
        printf("Saraee esantys elementai: \n");
        ToPrnt = *head;
        while (ToPrnt != NULL)
        {
            printf("%d ", ToPrnt->sk);
            ToPrnt = ToPrnt->next;
        }

        printf("\n ");
        return 0;
    } else
    {
        printf("%s\n", "Sarasas tuscias \n");
        return 1;
    }
}



int ElemPrnt (struct LinkedList **head, int *a)
{
    int i;
    struct LinkedList *ToPrnt = *head;
    if (*head == NULL)
        return 2;
    for (i = 0; i<(*a); i++)
    {
        if (ToPrnt->next == NULL)
            return 1;
        ToPrnt = ToPrnt->next;
    }
    printf ("%d elementas yra: %d\n", *a, ToPrnt->sk);
    return 0;
}



int DelElem (struct LinkedList **head, struct LinkedList **tail, int *a)
{
    int i;
    struct LinkedList *temp = *head;

    if (*head == NULL)
        return 2;
    for (i = 0; i<(*a); i++)
    {
        if (temp->next == NULL)
            return 1;
        temp = temp->next;
    }

    if (temp->previous == NULL && temp->next == NULL)
    {
        *head = NULL;
        *tail = NULL;
    } else if (temp->previous == NULL)
    {
        *head = temp->next;
        temp->next->previous = NULL;
    } else if (temp->next == NULL)
    {
        *tail = temp->previous;
        temp->previous->next = NULL;
    } else
    {
        temp->next->previous = temp->previous;
        temp->previous->next = temp->next;
    }

    printf("Skaicius sekmingai istrintas is saraso! \n");
    free (temp);
    return 0;
}



int FindSize (struct LinkedList **head)
{
    int n=1;
    struct LinkedList *temp = *head;
    if (*head == NULL)
        return 2;
    while (temp = temp->next)
        n++;

    printf("Saraso dydis yra %d elementu.\n", n);
    return 0;
}



int FindElem (struct LinkedList **head, int *a)
{
    int i = 0;
    struct LinkedList *temp = *head;
    if (*head == NULL)
        return 2;

    do
    {
        if (temp->sk == *a)
        {
            printf("Elemantas %d rastas, jis yra %d sarase (skaiciuojant nuo nulio).\n", *a, i);
            return 0;
        }
        i++;
    } while (temp = temp->next);
    return 3;
}




void errors (int *err)
{
    if (*err == 1)
        printf("Deja, tokio elemento nera. Bandykite ieskioti artimesnio elemento.\n");
    if (*err == 2)
        printf("Sarase nera elementu.\n");
    if (*err == 3)
        printf("Sarase elementas nerastas.\n");
    if (*err == 10)
        printf("Klaida alokuojant atminti");
}


