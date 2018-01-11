// Tomas Mikna P. S. I kuras 2 grupë

#include <stdlib.h>
#include <stdio.h>

struct LinkedList
{
    int sk;
    struct LinkedList* next;
    struct LinkedList* previous;
};

int ElementAddition (struct LinkedList **head, struct LinkedList **tail, int *a);
int StrCpy (struct LinkedList **head);
int ElemPrnt (struct LinkedList **head, int *a);
int DelElem (struct LinkedList **head, struct LinkedList **tail, int *a);
int FindSize (struct LinkedList **head);
int FindElem (struct LinkedList **head, int *a);
void errors (int *err);

int main()
{
    int err = 0;
    int n;
    int k = 1;
    char *Nurodymai = {"Pasirinkite, ka norite daryti su sarasu:\n  Spauskite 1, jei norite irasyti simboli\n  Spauskite 2, jei norite atspausdinti simboli (pagal eil. nr)\n  Spauskite 3, jei norite isspausdinti sarasa\n  Spauskite 4, jei norite istrinti simboli\n  Spauskite 5, jei norite nustatyti ilgi\n  Spauskite 6, jei norite surasti simboli (pagal reiksme)\n  Spauskite 0, jei norite baigti darba\n"};
    char *BlogasNr = {"Ivedete netinkama numeri, prasome ivesti is naujo\n"};
    char *Ivekite = {"Iveskita skaiciu: \n"};

    struct LinkedList *head = NULL;
    struct LinkedList *tail = NULL;

    int a;


    do
    {
        err=0;

        printf("\n%s", Nurodymai);
        scanf("%d", &n);

        switch(n)
        {
            case 1:
                printf("%s", Ivekite);
                scanf("%d", &a);
                err=ElementAddition (&head, &tail, &a);
                errors (&err);
                break;

            case 2:
                printf("Iveskite, kelinta simboli norite atspausdinti (simboliai skaiciuojami nuo nulio): \n");
                scanf("%d", &a);
                err = ElemPrnt (&head, &a);
                errors (&err);
                break;

            case 3:
                ListPrnt (&head);
                break;

            case 4:
                printf("Iveskite, kelinta simboli norite istrinti (simboliai skaiciuojami nuo nulio): \n");
                scanf("%d", &a);
                err = DelElem (&head, &tail, &a);
                errors (&err);
                break;

            case 5:
                err = FindSize (&head);
                errors (&err);
                break;

            case 6:
                printf("Iveskite, koki skaiciu norite rasti: \n");
                scanf("%d", &a);
                err = FindElem (&head, &a);
                errors (&err);
                break;

            case 0:
                k = 0;
                break;
            default:
                printf("%s", BlogasNr);
        }
    }
    while (k);
    return 0;
}

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
