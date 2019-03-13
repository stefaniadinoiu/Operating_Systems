#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <pthread.h>

#define m 2
#define p 3
#define n 2
#define nrThreaduri 4
int matA[m][p] = {{1, 2, 3},
                  {1, 2, 3}};
int matB[p][n] = {{3, 4},
                  {5, 6},
                  {7, 8}};
int matC[m][n];


struct Element
{
    int i, j;
};

int pas = -1;
struct Element deCalculat()
{
    struct Element x = {pas/n, pas%n};
    return x;
}

void* multi(void* v)
{
    pas++;
    struct Element d = deCalculat();
    int *x = (int*)v;
    printf("%d\n", *x);
    for (int k=0; k<p; k++)
        matC[d.i][d.j] += matA[d.i][k] * matB[k][d.j];
    return NULL;
}

int main()
{
    pthread_t thread[nrThreaduri];
    int t[nrThreaduri];
    for (int i=0; i<nrThreaduri; i++)
    {
        t[i]=i;
        pthread_create(&thread[i], NULL, multi, (void*)(t+i));
    }

    for (int i=0; i<nrThreaduri; i++)
        pthread_join(thread[i], NULL);

    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
            printf("%d ", matC[i][j]);
        printf("\n");
    }
    return 0;
}
