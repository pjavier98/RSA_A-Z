#include "generate_keys.h"

int primo(lli n)
{
    lli aux = 3, raiz = sqrt(n);
    if(n % 2 == 0 && n != 2 || n == 1)
    {
        return 0;
    }
    for(aux = 3; aux <= raiz; aux += 2)
    {
        if(n % aux == 0)
        {
            return 0;
        }
    }
    return 1;
}

lli totiente(lli key_1, lli key_2)
{
    key_1 = (key_1 - 1);
    key_2 = (key_2 - 1);
    return key_1 * key_2;
}

lli public_key(lli p, lli q)
{
    return p * q;
}


void mdc(lli num_1, lli num_2, lli *cont)
{
    if (num_2 == 0)
    {
        return;
    }
    *cont += 1;
    mdc(num_2, num_1 % num_2, cont);
}

int coprimo(lli num_1, lli num_2)
{
    if (num_1 % num_2 == 0)
    {
        if(num_2 == 1)
        {
            return 1;
        }
        return 0;
    }
    coprimo(num_2, num_1 % num_2);
}

// lli linear_comb(lli num_1, lli num_2, lli coef_s, lli cont)
// {
//     if (num_1 % num_2 == 0) // 16 % 4 // contador do mdc == 1
//     {
//         coef_s = 0; 
//     }
//     else if (num_2 % num_1 == 0) // 4 % 16 // contador do mdc == 1
//     {
//         coef_s = 1; 
//     }
//     else if (cont == 2) // 15 e 12, 48 e 15 // contador do mdc == 2
//     {
//         coef_s = -(num_2 / num_1);
//     }
//     else // numeros com mais de dois divisores
//     {
//         lli array[cont];
//         lli aux; 
//         lli i = cont - 1; // para inverter as posicoes do array
//         lli temp_1 = num_1;
//         lli temp_2 = num_2;
//         while (temp_1 % temp_2 != 0)
//         {
//             array[i] = temp_1 / temp_2;
//             aux = temp_2;
//             temp_2 = temp_1 % temp_2;
//             temp_1 = aux;
//             i--;
//         }
//         lli previous = 1;
//         lli back = 0;
//         i = 0;
//         lli count = 0;
//         while (i < cont)
//         {   
//             count = array[i] * previous + back;
//             back = previous;
//             previous = count;

//             if (i == cont - 2)
//             {
//                 if (cont % 2 == 0)
//                 {
//                     coef_s = -count;
//                 }

//                 else
//                 {
//                     coef_s = count;
//                 }
//             }

//             i += 1;
//         }
//     }
//     if (coef_s > 0)
//     {
//         return coef_s;
//     }
//     else
//     {
//         return coef_s + num_2;
//     }
// }

// lli inverso_modular(lli expoente, lli res_totiente)
// {
//     lli cont = 0;
//     mdc(res_totiente, expoente, &cont);
//     lli inverso = linear_comb(expoente, res_totiente, 0, cont);
//     return inverso;
// }

lli inverso_modular(lli expoente, lli res_totiente) {
    lli inverso = 0;
    while(1)
    {
        if((inverso * expoente) % res_tot == 1)
        {
            break;
        }
        inverso++;
    }
    return inverso;
}

void keys()
{
    int num;
    lli p = 0; 
    lli q = 0;
    lli expoente = 0;
    lli res_tot = 0;
    lli d = 0
    ;
    
    printf("Digite o número primo p:\n");
    scanf("%lld",&p); 
    
    while(!primo(p))
    {
        printf("%lld não é primo, digite novamente:\n",p);
        scanf("%lld",&p);
    }
    
    printf("Digite o número primo q:\n");
    scanf("%lld",&q);
    
    while(!primo(q))
    {
        printf("%lld não é primo, digite novamente:\n",q);
        scanf("%lld",&q);
    }
    
    res_tot = totiente(p, q);
    printf("Digite um valor coprimo a %lld:\n",res_tot);
    scanf("%lld",&expoente);
    
    while(!coprimo(res_tot,expoente))
    {
        printf("%lld não é coprimo a %lld, digite novamente:\n",expoente,res_tot);
        scanf("%lld",&expoente);
    }

    lli n = public_key(p , q); 
    d = inverso_modular(expoente, res_tot); 
    
    FILE *public = fopen("key_public/key_public.txt", "w");
    fprintf(public, "%lld %lld", n, expoente);
    fclose(public);

    FILE *private = fopen("key_private/key_private.txt", "w");
    fprintf(private, "%lld %lld %lld", p, q, d);
    fclose(private);
}
