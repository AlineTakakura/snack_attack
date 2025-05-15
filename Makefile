CC = gcc
CFLAGS = -Wall -Iinclude -Ilib/cli-lib/include

SRCS = src/main.c \
       src/jogo.c \
       src/jogador.c \
       src/lanche.c \
       lib/cli-lib/src/screen.c \
       lib/cli-lib/src/keyboard.c \
       lib/cli-lib/src/timer.c

OBJS = $(SRCS:.c=.o)
EXEC = snackattack

all: $(EXEC)

$(EXEC): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(EXEC)

run: $(EXEC)
	./$(EXEC)

clean:
	rm -f $(EXEC)