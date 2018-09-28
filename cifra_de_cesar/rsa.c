#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int criptografar(char data) 
{
    int value = (data - 'a') + 3;
    value = value % 256;
    while (value < 0)
    {
        value = value + 26;
    }
    
    char new_data = value + 'a';
    return new_data;
}

void ler() 
{
    char data;
    FILE *f = fopen("teste.txt", "rt");
    FILE *w = fopen("escrita.txt", "w");
    if(f == NULL) 
    {
        printf("erro ao abrir o arquivo\n");
    } 
    else 
    {
        while(fscanf(f, "%c", &data) != EOF)
        {   
            fprintf(w, "%c", criptografar(data));
        }
    } 

    fclose(f);
    fclose(w);      
}

int descriptografar(char data) 
{
    char new_data;
    int value = (data - 'a') - 3;
    
    value = value % 26;
    while (value < 0)
    {
        value = value + 26;
    }
    
    new_data = value + 'a'; 
    return new_data;
}

void ler_descriptografar() 
{
    char data;
    FILE *f = fopen("escrita.txt", "rt");
    FILE *w = fopen("descriptografia.txt", "w");
    if(f == NULL) 
    {
        printf("erro ao abrir o arquivo\n");
    } 
    else 
    {
        while(fscanf(f, "%c", &data) != EOF)
        {   
            fprintf(w, "%c", descriptografar(data));
        }
    } 

    fclose(f);
    fclose(w);      
}
 
int main() {
    ler();
    ler_descriptografar(); 
    return 0;
}
