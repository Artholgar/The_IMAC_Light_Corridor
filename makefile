CC		= gcc
CFLAGS	= -Wall -O2 -g
LDFLAGS	= -lglfw -lGLU -lGL -lm

BINDIR	= bin/
SRCDIR	= src/
OBJDIR	= obj/

# Fichiers

OBJ= main.o
EXEC= TILC

# Regles compilation The IMAC Light Corridor

all : app

app : $(OBJDIR)$(OBJ)
	$(CC) $(CFLAGS) $(OBJDIR)$(OBJ) -o $(BINDIR)$(EXEC) $(LDFLAGS)

clean :
	rm -rf *~
	rm -rf $(SRCDIR)*/*~
	rm -rf $(OBJDIR)
	rm -rf $(BINDIR)*

$(OBJDIR)%.o: $(SRCDIR)%.c
	mkdir -p `dirname $@`
	$(CC) -o $@ -c $< $(CFLAGS)