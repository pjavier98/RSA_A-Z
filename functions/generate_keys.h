#ifndef generate_keys
#define  generate_keys

#include  "../header/header.h"

void  keys ();
/* Digita um numero primo p e depois um numero primo q, e fica verificando se esse 
 * numeros sao primos;
 * Chamando a funcao totiente, na qual retorna o resultado da multiplicacao dos primos -1;
 * O usuario ira digita o valor de um coprimo ao resultado da totiente, e depois o 
 * valor e verificado ate esta certo, ou seja a segunda chave publica;
 * Chama a funcao public_key, onde ira retorna o valor da segunda chave publica a 
 * multiplicao dos primos;
 * Chama a funcao inverso_modular, na qual ira retorna o valor da 3 chave privada;
 * Abre o arquivo "key_public/key_public.txt", onde ira guarda as chaves publicas;
 * O arquivo "key_private/key_private.txt", ficara guardado as chaves privadas;
 */

void  mdc (lli num_1, lli num_2, lli * cont);
/* mdc de euclides, ate que o resultado do num2 seja = 0 para parar, e tem um 
 * cont que fica somando +1 a cada loop que num seja diferente de 0;
 */

 short primo (lli num);
/* 
 * Na qual verifica se o numero é primo ou nao;
 */

 short coprimo (lli num_1, lli num_2);
/* 
 * Verifica se o numero é coprimo ou nao;
 */

lli totiente (lli key_1, lli key_2);
/* 
 * Multiplicacao dos primos ((q-1) * (p-1)), e retorna esse resultado;
 */

lli public_key (lli p, lli q);
/* 
 * Multiplicacao dos 2 primos;
 */

lli linear_comb (lli num_1, lli num_2, lli coef_s, lli cont);
/* 
 * primeiro verifica se o num_1 é divisel por num_2, caso nao verifica se quanta vezes
 * ocorre a divisao ate achar o mdc, se o cont = 2 quer dizer que ele faz o processo do 
 * mdc duas vezes, caso fizer mais de 2 vezes entra no else, cria um array com os divisores,
 * inverte a posições do array para fazer o calculo do coeficiente s, caso o coeficiente for  
 * negativo ele soma com o num_2, caso for positivo ele retorna para a função inverso modular
 */

lli inverso_modular (lli expoente, lli res_totiente);
/* 
 * Chama a fuçao mdc, que ira por meio de ponteiro recebe o cont
 * (quantidade de loops da funcao mdc);
 * Depois executa a função liner_comb, que ira retorna o resultado do coeficente
 */

# endif
