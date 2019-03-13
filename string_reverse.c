#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <pthread.h>

void* inverseaza(void *v)
{
    char *deInversat = (char *)v;
    int lungime = strlen(deInversat);
    for(int i=0; i<lungime/2; ++i)
    {
        char c = deInversat[i];
        deInversat[i] = deInversat[lungime-i-1];
        deInversat[lungime-i-1] = c;
    }
    return v;
}


int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("%s", "Introduceti un sir de caractere\n");
        return errno;
    }
    pthread_t thr;
    if(pthread_create(&thr, NULL, inverseaza, argv[1]))
    {
        perror(NULL);
        return errno;
    }
    void *invers;
    if(pthread_join(thr, &invers))
    {
        perror(NULL);
        return errno;
    }
    printf("%s\n", (char*)invers);
    return 0;
}
