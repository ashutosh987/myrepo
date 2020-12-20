# -*- MakeFile -*-

SRC	=	crypto
SOURCE	=	$(wildcard $(SRC)/*.c)

OBJECT	=	$(SOURCE:.c=.o)


test:$(OBJECT)	



main.o:main.c
	gcc	-c	main.c		

