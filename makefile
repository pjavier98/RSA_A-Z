KEY = functions/generate_keys.c functions/generate_keys.h
RSA = functions/encrypt_decrypt.c functions/encrypt_decrypt.h
MAIN = main.c

compile_rsa:
	gcc $(KEY) $(RSA) $(MAIN) -o rsa -lm

clear_avl:
	rm rsa
