#include "encrypt_decrypt.h"
#include "generate_keys.h"

lli exponentiation(lli base, lli exp, lli mod)
{
    lli r = 1;
    while(exp) {
        if(exp & 1) {
            r = (r * base) % mod;
        }
        base = (base * base) % mod; 
        exp = exp >> 1;
    }
    return r;
}

lli fermat(lli number, lli expoente, lli mod)
{   
    lli resto = exponentiation(number, expoente, mod);
    return resto;
}

void txt_to_encrypt() 
{
    int i;
    char dic[27] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',' '};
    char data;
    FILE *f = fopen("teste.txt", "rt");
    FILE *w = fopen("criptografado.txt", "w");
    if(f == NULL) 
    {
        printf("erro ao abrir o arquivo\n");
    } 
    else 
    {
        lli key_1;
        lli key_2;
        printf("Digite as chaves públicas:\n");
        scanf("%lld %lld",&key_1,&key_2);
        while(fscanf(f, "%c", &data) != EOF)
        {  
            for(i = 0; i < 27; i++)
            {
                if(dic[i] == data)
                {
                    break;
                }
            }
            lli value = i;
            lli number = fermat(value, key_2, key_1);
            fprintf(w, "%lld ", number);
        }
    } 
    printf("\n");
    fclose(f);
    fclose(w);      
}

void txt_to_decrypt() 
{
    int tamanho = 0;
    char aux[100];
    char dic[27] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',' '};
    lli number;
    FILE *f = fopen("criptografado.txt", "rt");
    while(fscanf(f, "%s", aux) != EOF)
    {
        tamanho++;
    }
    fclose(f);
    f = fopen("criptografado.txt", "rt");
    FILE *w = fopen("descriptografado.txt", "w");
    if(f == NULL) 
    {
        printf("erro ao abrir o arquivo\n");
    } 
    else 
    {
        keys();
        lli publ_key ;
        FILE *publ = fopen("key_public/key_public.txt","rt");
        fscanf(publ, "%lld", &publ_key);
        fclose(publ);

        int i = 0;
        lli priv_key = 0;
        lli test_key = 0;
        FILE *priv = fopen("key_private/key_private.txt","rt");
        while (i < 3)
        {
            fscanf(priv, "%lld", &test_key);
            i++;
        }
        fclose(priv);
        priv_key = test_key;
        lli value;
        char data;
        for(i = 0;i < tamanho; i++)
        {
            fscanf(f, "%lld", &number);
            lli value = fermat(number,priv_key,publ_key);
            char data = dic[value];
            fprintf(w, "%c", data);
        }
        
    } 
    printf("\n");
    fclose(f);
    fclose(w);      
}