#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 80

void escreve(){
    char str[MAX],strNome[MAX];
    FILE *arq;
    printf("Digite o nome do arquivo a ser criado:\n");
    scanf("%s", strNome);

        if((arq=fopen(strNome, "w"))==NULL){
            printf("Erro ao abrir %s", str);
            exit(1);
        }
        printf("Digite um paragrafo:\n");
        fflush(stdin);
        fgets(str, MAX, stdin);
        
        fputs(str, arq);
    fclose(arq);
}

void ler(){
    char str[MAX]; 
    FILE *arq;
    printf("Arquivo dicionario:\n");
    if((arq=fopen("dicionario.txt", "r"))==NULL){
            printf("Erro ao abrir %s", str);
            exit(1);
        }
        
        while(fgets(str, MAX ,arq) != NULL)
            printf("%s", str);
        fclose(arq);
}

void compara(){
    char str[MAX], strNome[MAX];
    char palavraOriginal[MAX], palavraSubstituta[MAX];
    int flag; 
    FILE *arq, *arqDi, *arqNovo;
    
    printf("Digite o nome do arquivo a ser comparado:\n");
    scanf("%s", strNome);
    if((arq=fopen(strNome, "r"))==NULL){
            printf("Erro ao abrir %s\n", strNome);
            exit(1);
        }
    if((arqDi=fopen("dicionario.txt", "r"))==NULL){
            printf("Erro ao abrir dicionario.txt\n");
            exit(1);
        }
    if((arqNovo=fopen("traducao.txt", "w"))==NULL){
            printf("Erro ao abrir traducao.txt\n");
            exit(1);
        }
    
    while(fscanf(arq, "%s", str)!= EOF){
        flag = 0;
        rewind(arqDi);
        while (fscanf(arqDi, "%s %s", palavraOriginal, palavraSubstituta) != EOF) {   
            if((strcmp(str, palavraOriginal))==0){
                fprintf(arqNovo, "%s ", palavraSubstituta);
                flag = 1;
            }
        }
        if(!flag)
            fprintf(arqNovo, "%s ", str);   
    }
    fclose(arq);
    fclose(arqDi);
    fclose(arqNovo);
}

int main(){
   escreve();
   ler();
   compara(); 
}