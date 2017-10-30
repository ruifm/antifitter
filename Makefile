DB_FLAGS	= -Wall -g -ggdb -O3 -lexif -lglut

LINK_LIBS	=  -lm


CFLAGS		= $(INC_FLAGS) $(DB_FLAGS)
LFLAGS		= $(LINK_FLAGS)
CC		= g++
CP		= cp
RM		= rm
LS		= ls

PROGS1		= antifitter func 
OUT1     = antifitter.o func.o


all: comp link clean

comp: comp1  

comp1: 
	for fname in $(PROGS1); do $(CC) $(CFLAGS) -c $$fname.cpp ; done


link: link1

link1: 
	$(CC) $(OUT1) $(LFLAGS) $(LINK_LIBS)  -o run

clean:
	$(RM) -f *~ *.o $(PROGS1)
