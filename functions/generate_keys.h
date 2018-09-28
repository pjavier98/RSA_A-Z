#ifndef generate_keys
#define generate_keys

#include "../header/header.h"

void keys();
/*
 * 
 */

void mdc(lli num_1, lli num_2, lli *cont);
/*
 * 
 */

short primo(lli num);
/*
 *
 */

short coprimo(lli num_1, lli num_2);
/*
 *
 */

lli totiente(lli key_1, lli key_2); 
/*
 * 
 */

lli public_key(lli p, lli q); 
/*
 * 
 */

lli linear_comb(lli num_1, lli num_2, lli coef_s, lli cont);
/*
 * 
 */

lli inverso_modular(lli expoente, lli res_totiente);
/*
 * 
 */

#endif