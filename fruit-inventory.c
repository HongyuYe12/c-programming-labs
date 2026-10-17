#include <stdio.h>
#include <string.h>

struct fruit
{
    char name[30];
    char category[30];
    float price;
    float mass;
};

int main()
{
    int a;
    float totalmass = 0;
    float totalprice = 0;

    printf("/*How many records of fruits you want to add*/\n");
    printf("Enter Limit:");
    scanf("%d", &a);

    struct fruit fruit[a];

    for (int i = 0; i < a; i++)
    {
        printf("--------------------------\n");
        printf("Enter details of fruit-%d\n", i + 1);
        printf("--------------------------\n");
        printf("Fruit Name:");
        scanf("%s", fruit[i].name);
        printf("Category:");
        scanf("%s", fruit[i].category);
        printf("Price per kg:");
        scanf("%f", &fruit[i].price);
        printf("mass (kg):");
        scanf("%f", &fruit[i].mass);
        totalmass += fruit[i].mass;
        totalprice += fruit[i].mass * fruit[i].price;
    }

    char unique_categories[a][30];
    int unique_category_count = 0;

    for (int i = 0; i < a; i++)
    {
        int found = 0;
        for (int j = 0; j < unique_category_count; j++)
        {
            if (strcmp(fruit[i].category, unique_categories[j]) == 0)
            {
                found = 1;
                break;
            }
        }
        if (!found)
        {
            strcpy(unique_categories[unique_category_count], fruit[i].category);
            unique_category_count++;
        }
    }

    printf("--------------------------\n");
    printf("Summary\n");
    printf("--------------------------\n");
    printf("Total mass of fruits: %.2f\n", totalmass);
    printf("Total price of fruits: %.2f\n", totalprice);

    for (int i = 0; i < unique_category_count; i++)
    {
        printf("\n%s Fruits:\n", unique_categories[i]);
        int found = 0;
        for (int j = 0; j < a; j++)
        {
            if (strcmp(fruit[j].category, unique_categories[i]) == 0)
            {
                printf("Fruit Name: %s\n", fruit[j].name);
                found = 1;
            }
        }
        if (!found)
        {
            printf("No fruits of this category.\n");
        }
    }

    return 0;
}
