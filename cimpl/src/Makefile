IDIR =../include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=build

#LDIR=../lib
LIBS=-lm -lGL -lGLU -lglut 

_DEPS = view.h controller.h model.h materials.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o view.o controller.o model.o materials.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

gnomish: $(OBJ)
		gcc -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
		rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
