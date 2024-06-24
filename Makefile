CC = gcc
CFLAGS = -I./include

SRCS = src/main.c src/cliente.c src/funcionario.c src/quarto.c src/estadia.c src/data.c
OBJS = $(SRCS:.c=.o)

all: hotel

hotel: $(OBJS)
	$(CC) -o hotel $(OBJS) $(CFLAGS)

clean:
	rm -f hotel $(OBJS)
