CC=g++
CFLAGS=-c -Wall -ansi
LIBS=-lglut -lGL -lGLU
OBJECTS=Dynamo.o CTargaImage.o winmain.o

all: $(OBJECTS)
	$(CC) -o dynamicpath $(OBJECTS) $(LIBS) -Wall -ansi
	
Dynamo.o: Dynamo.cpp Dynamo.h
	$(CC) $(CFLAGS) Dynamo.cpp
	
CTargaImage.o: CTargaImage.cpp CTargaImage.h
	$(CC) $(CFLAGS) CTargaImage.cpp
	
winmain.o: winmain.cpp
	$(CC) $(CFLAGS) winmain.cpp
	
clean: 
	rm -f *.o
	