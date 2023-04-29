CC		= gcc
CFLAGS	= -Wall -O2 -g
LDFLAGS	= -lglfw -lGLU -lGL -lm

BINDIR	= bin/
INCDIR	= inc/
SRCDIR	= src/
OBJDIR	= obj/

# Fichiers

OBJ= $(OBJDIR)main.o $(OBJDIR)3D_tools.o
EXEC= TILC

# Regles compilation The IMAC Light Corridor

all : app

app : $(OBJ)
	mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $(OBJ) -o $(BINDIR)$(EXEC) $(LDFLAGS)

clean :
	rm -rf *~
	rm -rf $(SRCDIR)*/*~
	rm -rf $(OBJDIR)
	rm -rf $(BINDIR)*

$(OBJDIR)%.o: $(SRCDIR)%.c $(INCDIR)*.h
	mkdir -p `dirname $@`
	$(CC) -o $@ -I $(INCDIR) -c $< $(CFLAGS)