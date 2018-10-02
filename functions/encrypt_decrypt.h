#ifndef encypt_decrypt
#define  encypt_decrypt


#include  "../header/header.h"

lli exponentiation (lli num, lli exp, lli mod);
/* 
 * Entra em um loop ate que o expoente seja 0, faz um bit a bit e verifica se o 
 * ultimo bit for 1,   se for 1 quer dizer que o numero é impar e ele entra no if.
 * retornando o r(resto) dessa função;
 */

lli fermat (lli numero, lli expoente, lli mod);
/* 
 * Recebe o resultado da função exponentiation rapida, retornando um long long int; 
 */

void  txt_to_encrypt ();
/* 
 * Cria um array com o alfabeto e com o espaço incluido de 0-27;
 * Abre o arquivo teste.txt, na qual tem a mensagem a ser encriptografada;
 * Recebe o key1 e o key2 do usuario para encriptografa a mensagem;
 * Depois ler caracter por caracter no arquivo teste.txt 
 * Onde ira pega a posição do caracter a ser encriptado, para passar a função fermat;
 * Também o arquivo criptografado.txt é aberto, que guardará o resultado da função fermat;
 */

void  txt_to_decrypt ();
/* 
 * Cria um array com o alfabeto e com o espaço incluido de 0-27;
 * cria um while para ver o tamanho do arquivo;
 * Abre o arquivo criptografado.txt, onde tem a mensagem criptografada;
 * E também o arquivo key_private/key_private.txt e key_public/key_public.txt, 
 * onde tem as chaves publicas e privadas para descriptografa;
 * Passa um loop, lendo os numeros encriptofrafado para a função fermat, na qual 
 * recebe um valor que ia ser buscado no array,
 * logo printando esse char no arquivo;
 */

# endif
