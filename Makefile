# Nome do executável final
TARGET = programa.exe

# Compilador
CC = gcc

# Flags do compilador
CFLAGS = -Wall -Wextra -std=c11

# Arquivos fonte e objeto
SRCS = $(wildcard *.c)  # Busca todos os arquivos .c no diretório atual
OBJS = $(SRCS:.c=.o)    # Substitui .c por .o para os objetos

# Regra padrão
all: $(TARGET)

# Regra para criar o executável
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Regra para compilar os arquivos .c em .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpeza dos arquivos temporários
clean:
ifeq ($(OS),Windows_NT)
	del /Q *.o $(TARGET)
else
	rm -f *.o $(TARGET)
endif

# Para evitar erros ao usar "make clean" sem arquivos de saída
.PHONY: all clean
