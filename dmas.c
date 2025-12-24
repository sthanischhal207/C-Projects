#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void results(int C);
void update(int i,int C);

char equation[100],symbols[100];
float num[100];
int main()
{
    int i=0;
    printf("NOTE: DONT FORGET TO ENTER = SIGN AT THE END OF EXPRESSION\n");
    printf("Enter the expression: \n");
    while(symbols[i-1] != '=')
    {
        scanf("%f",&num[i]);
        scanf("%c",&symbols[i]);
        i++;
    }
    results(strlen(symbols));
    return 0;
}

float result;

void results(int C)
{
    int i;
    for(i=0;i<C;i++)
    {
        if(symbols[i] == '/')
        {
            if(num[i+1]==0)
            {
                printf("----zero division error----");
                exit(1);
            }
            result = num[i]/num[i+1];
            update(i,C);
        }
    }

    for(i=0;i<C;i++)
    {
        if(symbols[i] == '*')
        {
            result = num[i]*num[i+1];
            update(i,C);
        }
    }

    for(i=0;i<C;i++)
    {
        if(symbols[i] == '+')
        {
            result = num[i]+num[i+1];
            update(i,C);
        }
    }

    for(i=0;i<C;i++)
    {
        if(symbols[i] == '-')
        {
            result = num[i]-num[i+1];
            update(i,C);
        }
    }
}

void update(int i,int C)
{
    int j;
    num[i]=result;
    for(j=i+1;j<C;j++)
    {
        num[j]=num[j+1];
    }
    for(j=i;j<=C;j++)
    {
        symbols[j]=symbols[j+1];
    }
    for(j=0;j<C-1;j++)
    {
        printf("%g ",num[j]);
        if(symbols[j]!='=')
        {
            printf("%c ",symbols[j]);
        }
    }
    printf("\n");
    results(C-1);
}