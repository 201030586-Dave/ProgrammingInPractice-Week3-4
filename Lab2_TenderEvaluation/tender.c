#include <stdio.h>
#include <string.h>

int main()
{
    char supplierName[50];
    float price;
    float budget;
    int registered;
    int documentsComplete;
    float lowestPrice = 0;
    char preferredSupplier[50];
    int qualifiedSupplierFound = 0;
    int i;

    printf("TENDER EVALUATION SYSTEM\n\n");

    for (i = 1; i <= 4; i++)
    {
        printf("\nSupplier %d\n", i);

        printf("Enter supplier name: ");
        scanf("%49s", supplierName);

        printf("Enter tender price: ");
        scanf("%f", &price);

        printf("Enter budget: ");
        scanf("%f", &budget);

        printf("Is the supplier registered? (1 = Yes, 0 = No): ");
        scanf("%d", &registered);

        printf("Are all documents complete? (1 = Yes, 0 = No): ");
        scanf("%d", &documentsComplete);

        if (registered == 1 && documentsComplete == 1 && price <= budget)
        {
            printf("\nSupplier: %s\n", supplierName);
            printf("Status: Qualified\n");

            if (qualifiedSupplierFound == 0 || price < lowestPrice)
            {
                lowestPrice = price;
                strcpy(preferredSupplier, supplierName);
                qualifiedSupplierFound = 1;
            }
        }
        else
        {
            printf("\nSupplier: %s\n", supplierName);
            printf("Status: Disqualified\n");
        }
    }

    if (qualifiedSupplierFound == 1)
    {
        printf("\nPreferred Supplier:\n");
        printf("Supplier: %s\n", preferredSupplier);
        printf("Lowest Price: %.2f\n", lowestPrice);
    }
    else
    {
        printf("\nNo qualified supplier was found.\n");
    }

    return 0;
}