all:
	gcc -g -m32 -fno-stack-protector main.c 2048.c share.c -o 20482048204820482048204820482048204820482048204820482048204820482048204820482048 -lm
test:
	gcc -g -m32 -fno-stack-protector main.c 2048.c share.c -o test -lm
