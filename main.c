#include "functions/generate_keys.h"
#include "functions/encrypt_decrypt.h"

int main()
{
    lli valor;
    lli i = 0;
    lli size = 2;
    lli array[size];
    printf("Selecione a opção 1 para Gerar a Chave Pública:\n");
    printf("Selecione a opção 2 para Criptografar:\n");
    printf("Selecione a opção 3 para Descriptografar:\n");
    scanf("%lld", &valor);

    switch (valor)
    {
        case 1:
        {   
            keys();
            break;
        }
        case 2:
        {
            txt_to_encrypt();
            break;
        }
        case 3:
        {
            txt_to_decrypt();
            break;
        }
    }

}