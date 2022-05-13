%{
    #include<stdio.h>
    #include<math.h>
    int a,b;
    int choice;
    float x;
%}

%%
.               ;
%%

int yywrap(void){ }
int main() {
    printf("1) Addition\n2) Subtraction\n3) Multiplication\n4) Division\n");
    printf("5) Sin(X)\n6) Cos(X)\n7) Tan(X)\n");
    printf("8) Square\n9) Square-Root\n");
    printf("10) Positive|Negative|Zero\n");

    scanf("%d", &choice);

    if(choice > 0 && choice < 5) {

    printf("\nEnter A:\n");
    scanf("%d", &a);
    printf("Enter B:\n");
    scanf("%d", &b);
    printf("\n");

    switch(choice)
    {
        case 1:
            printf("A+B = %lf", (a+b));
            break;
        case 2:
            printf("A-B = %lf", (a-b));
            break;
        case 3:
            printf("A*B = %lf", (a*b));
            break;
        case 4:
            printf("A/B = %lf", (a/b));
            break;
        default:
            printf("Not valid");
            break;
    }
    }
    else {
        // do trigonometry
         printf("\nEnter X:\n");
        scanf("%f", &x);
        switch(choice)
        {
            case 5:
                printf("sin(%f) = %f", x, sin(x));
                break;
            case 6:
                printf("cos(%f) = %f", x, cos(x));
                break;
            case 7:
                printf("tan(%f) = %f", x, tan(x));
                break;
            case 8:
                printf("Square(%f) = %f", x, x*x);
                break;
            case 9:
                double result =  sqrt(x);
                printf("Square Root(%f) = %f", x, result);
                break;
            case 10:
                if(x > 0) printf("\nPositive");
                else if(x < 0) printf("\nNegative");
                else printf("Zero");
                break;
            default:
                printf("Not valid");
                break;
        }
       
    }
    
    yylex(); 
    return 1;
}