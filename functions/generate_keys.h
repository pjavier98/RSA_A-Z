# ifndef generate_keys
# define  generate_keys

# include  " ../header/header.h "

void  keys ();
/* Digita um numero primo p e depois um numero primo q, e fica verificando se esse numeros sao primos,;
 * Chamando a funcao totiente, na qual retorna o resultado da multiplicacao dos primos -1;
 * O usuario ira digita o valor de um coprimo ao resultado da totiente, e depois o valor e verificado ate esta certo, ou seja a segunda chave publica;
 * Chama a funcao public_key, onde ira retorna o valor da segunda chave publica a multiplicao dos primos;
 * Chama a funcao inverso_modular, na qual ira retorna o valor da 3 chave privada;
 * Abre o arquivo "key_public/key_public.txt", onde ira guarda as chaves publicas;
 * O arquivo "key_private/key_private.txt", ficara guardado as chaves privadas;
 */

void  mdc (lli num_1, lli num_2, lli * cont);
/* mdc de euclides, ate que o resultado do num2 seja = 0 para parar, e tem um cont que fica somando +1 a cada loop que num seja diferente de 0;
 */

 short primo (lli num);
/* Na qual verifica se o numero é primo ou nao;
 */

 short coprimo (lli num_1, lli num_2);
/* Verifica se o numero é coprimo ou nao;
 */

lli totiente (lli key_1, lli key_2);
/* Multiplicacao dos primos -1 ((q-1) * (p-1)), e retorna esse resultado;
 */

lli public_key (lli p, lli q);
/* Multiplicacao dos 2 primos;
 */

lli linear_comb (lli num_1, lli num_2, lli coef_s, lli cont);
/* primeiro verifica se o numero é divisivel por ele ou não, ou o contador do mdc é 2;
 * caso o numero tenha mais de um divisor, cria um array com o tamanho do cont;
 * depois entra no loop que so acaba quando o temp1 % temp == 0 (falta completar);
 */

lli inverso_modular (lli expoente, lli res_totiente);
/* Chama a fuçao mdc, que ira por meio de ponteiro recebe o cont (quantidade de loops da funcao mdc);
 * Depois executa a função liner_comb, que ira retorna o resultado do coeficente (falta completar); 
 */

# endif