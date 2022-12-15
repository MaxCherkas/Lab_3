#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define eps 0.0001

double func (double x);
double interval(double x1, double x2, int iter_count, int N);
double chord(double x1, double x2, int iter_count, int N);
//-----------------------------------------------------------------------
int main()
{
    int N, method, iter_count;
    double x1, x2;
    double result;
    clock_t start, end;
    double delta_t;

    printf("Виберіть метод:");
    printf("\nІнтервали - 1");
    printf("\nХорди - 2");
    printf("\n>>>");
    scanf("%u", &method);
    while (method!=1&&method!=2)
    {
        scanf("%u", &method);
    }

    printf("Введіть дані:");
    do
    {
        printf("\nX1: ");
        scanf("%lf", &x1);
        printf("\nX2: ");
        scanf("%lf", &x2);
    } while (func(x1)*func(x2)>0);

    printf("\nN: ");
    scanf("%u", &N);

    system("cls");
    switch (method)
    {
        start=clock();
        case 1:
        {
            result = interval(x1,x2, iter_count, N);
        }
        break;

        case 2:
        {
            result = chord(x1, x2, iter_count, N);
        }
        break;

    }
    end=clock();
    delta_t = (double)(end-start)/CLOCKS_PER_SEC;
    printf ("Time for %lf seconds\n", delta_t);
    return 0;
}
//-----------------------------------------------------------------------
double interval(double x1, double x2, int iter_count, int N)
{
    double xi;
    unsigned int choice, toend;
    toend = N;

    do{
        iter_count++;

        xi=( x1 + x2 ) / 2;

        if( func(xi) * func(x1) > 0 ){
            x1 = xi;
        }
        else{
            x2 = xi;
        }
        if ( iter_count % N == 0 ){
            printf ("Кількість потрібних ітерацій: %u", iter_count);
            printf ("\n X: %lf", xi);
            printf ("\n f(x)= %lf", func(xi));
            printf ("\n\n ===================");
            printf ("\n1. Продовжити з такою кількістю ітерацій");
            printf ("\n2. Продовжити до кінця");
            printf ("\n3. Вихід");
            printf ("\n >>> ");
            scanf ("%u", &choice);
            printf ("--------------------------------------------------------\n");
            while (choice != 1 && choice != 2 && choice != 3){
                scanf("%u", &choice);
            }
            if(choice == 1){
                 N=N+toend;
            }
            if(choice == 2){
                N=iter_count;
            }
            if(choice == 3){
                break;
            }
        }
    }while(fabs( x1 - x2 ) >= eps);

    printf ("\nX= %.3lf\tf(x)= %.3lf\n", xi, func(xi));

    return xi;
}
//-----------------------------------------------------------------------
double chord (double x1, double x2, int iter_count, int N){
    double xi;
    unsigned int choice, toend;
    toend = N;

    do{
        iter_count++;

        xi = (x1 * func(x2) - x2 * func(x1)) / (( func(x2) - func(x1) ));

        if( func(xi) * func(x1) > 0 ){
            x1 = xi;
        }
        else{
            x2 = xi;
        }

            if (iter_count % N == 0){
                printf ("Кількість потрібних ітерацій: %u", iter_count);
                printf ("\n X: %lf", xi);
                printf ("\n f(x)= %lf", func(xi));
                printf ("\n\n ===================");
                printf ("\n\t 1. Продовжити з такою ж кількістю ітерацій");
                printf ("\n\t 2. Продовжити до кінця");
                printf ("\n\t 3. Вихід");
                printf ("\n >>> ");
                scanf ("%u", &choice);
                printf ("--------------------------------------------------------\n");

                while (choice!=1&&choice!=2&&choice!=3){
                    scanf("%u", &choice);
                }
                if(choice == 1){
                    N=N+toend;
                }
                if(choice == 2){
                    N=iter_count;
                }
                if(choice == 3){
                    break;
                }
            }

        }while( fabs(func(xi)) >= eps);


        printf ("\nX= %.3lf\tf(x)= %.3lf\n", xi, func(xi));

        return xi;
}
//-----------------------------------------------------------------------
double func (double x){
    double y;
    y = 2*pow(x,2)-3*pow(x,3)+1500*x-12000;
    return y;
}
