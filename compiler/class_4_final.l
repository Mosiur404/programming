%{
    #include<stdio.h>
    #include<stdlib.h>
    int a,b,c;
    int choice;
    float x = 0, y = 0;
%}

%%
.               ;
%%

int yywrap(void){ }

int max(int a,int b){return ((a + b + abs(a - b)) / 2);}
int main() {
    while(1){

    printf("\n\n1) Largest Number in 3 int\n2) Average of 10\n");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
            printf("Enter 3 number\n");
            scanf("%d%d%d", &a, &b, &c);
            printf("Result = %d", max(a, max(b, c)));
            break;
        case 2:
            for(int i = 0; i < 10; i++){
                printf("\tNum %d: ", i+1);
                scanf("%f", &x);
                y += x;
            }
            printf("Total = %.2f\nAverage = %.2f", y, y/10);
            break;
        default:
            printf("Not valid");
            break;
    }
    
    }
    yylex(); 
    return 1;
}