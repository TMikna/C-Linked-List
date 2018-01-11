// Tomas Mikna P. S. I kuras 2 grupë

#include <stdlib.h>
#include <stdio.h>
#include "hed.h"

int main()
{
    int err = 0;
    int n;
    int k = 1;
    char *Nurodymai = {"Pasirinkite, ka norite daryti su sarasu:\n  Spauskite 1, jei norite irasyti simboli\n  Spauskite 2, jei norite atspausdinti simboli (pagal eil. nr.)\n  Spauskite 3, jei norite isspausdinti sarasa\n  Spauskite 4, jei norite istrinti simboli\n  Spauskite 5, jei norite nustatyti ilgi\n  Spauskite 6, jei norite surasti simboli (pagal reiksme)\n  Spauskite 0, jei norite baigti darba\n"};
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
