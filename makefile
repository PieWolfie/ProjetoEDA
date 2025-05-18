# Detecta o sistema operacional
ifdef OS
    EXEC = projeto.exe
else
    EXEC = projeto
endif

# Variáveis
CC = gcc
CFLAGS = -Wall -Wextra -g
OBJ = main.o lista.o grafos.o

# Regra principal
all: $(EXEC)

# Criar o executável
$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXEC)

# Regras para compilar os arquivos .c em .o
main.o: main.c estrutura.h lista.h grafos.h
	$(CC) $(CFLAGS) -c main.c -o main.o

lista.o: lista.c lista.h estrutura.h
	$(CC) $(CFLAGS) -c lista.c -o lista.o

grafos.o: grafos.c grafos.h estrutura.h
	$(CC) $(CFLAGS) -c grafos.c -o grafos.o

# Limpeza dos arquivos compilados
clean:
	rm -f $(OBJ) $(EXEC)

# Recompilar do zero
rebuild: clean all

.PHONY: all clean rebuild