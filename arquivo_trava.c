#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/file.h>

int main()
{
    int pid = fork();
    FILE *arq;
    char c;
    arq = fopen("arquivo.txt", "r+"); //abre o arquivo
    flock(fileno(arq), LOCK_EX); //trava o arquivo com trava exclusiva
    printf("processo %d abriu o arquivo %p\n",pid, arq);
    if (!arq){
        perror("Arquivo inexistente");
        exit(0);
    }
    while (1) {
        c = getc(arq); //lê um caractere
        if (feof(arq)){
            fputs("\nNovo texto\n", arq); //vai gravar uma linha
            printf("Processo %d vai dormir\n", pid);
            sleep(5);
            break;
        }
        putchar(c); //imprime na tela o caractere
    }
    flock(fileno(arq), LOCK_UN); //destrava o arquivo
    fclose(arq); //fecha o arquivo
    return 0;
}
