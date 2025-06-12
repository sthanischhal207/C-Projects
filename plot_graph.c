#include<stdio.h>
#include <stdlib.h> // Required for abs()

void print_graph(int m,int n);
void initiate_graph(int m,int n);
void user_update(int a,int b,int m, int n);

char arr[1000][1000];

int main(){
    int choicex;
    int choicey;
    printf("Enter the X-coordinate you want to fill: ");
    scanf("%d",&choicex);
    printf("Enter the Y-coordinate you want to fill: ");
    scanf("%d",&choicey);

    int m = 2*abs(choicey) + 16;
    int n = 2*abs(choicex) + 30;

    initiate_graph(m,n);
    user_update((int)(m/2)- choicey,(int)(n/2)+ choicex,m,n);
    print_graph(m,n);

    return 0;
}


void print_graph(int m,int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%c ",arr[i][j]);
        }
        printf("\n");
    }
}

void initiate_graph(int m,int n){
    int halfx= m/2;
    int halfy= n/2;
    for(int i=0;i<m;i++){
        for(int j=0; j<n;j++){
            if(i==halfx){
                arr[i][j] = '-';
            }
            else if(j == halfy){
                arr[i][j] = '|';
            }
            else{
                arr[i][j] = ' ';
            }
        }
    }
}

void user_update(int a,int b,int m, int n){
    char buffer[10];
    sprintf(buffer, "*(%d,%d)", b-(int)(n/2), (int)(m/2)-a);  // Fixed: Convert `a` and `b` to string properly
    
    for (int i = 0; buffer[i] != '\0'; i++) {
        arr[a][b+i] = buffer[i];
    }
}