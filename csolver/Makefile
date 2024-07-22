#myapp: graphics.c
#	gcc $(pkg-config --cflags gtk+-3.0) graphics.c -o p1  $(pkg-config --libs gtk+-3.0)



# change application name here (executable output name)
TARGET=testapp

# compiler
CC=gcc
# debug
DEBUG=-g
# optimisation
OPT=-O0
# warnings
WARN=-Wall

PTHREAD=-pthread

CCFLAGS=$(DEBUG) $(OPT) $(WARN) $(PTHREAD) -pipe

GTKLIB=`pkg-config --cflags --libs gtk+-3.0`

# linker
LD=gcc
LDFLAGS=$(PTHREAD) $(GTKLIB) -export-dynamic
COBJ=graphics.c
OBJS=graphics.o

$(TARGET):$(OBJS)
	$(LD) -o $(TARGET) $(OBJS) $(GTKLIB)

$(OBJS):$(COBJ)
	$(CC) -c $(CCFLAGS) $(COBJ) $(GTKLIB) -o $(OBJS)

clean:
	rm -f *.o $(TARGET)

