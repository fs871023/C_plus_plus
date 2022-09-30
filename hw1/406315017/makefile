TARGET=hw1.out

all:$(TARGET)

$(TARGET):hw1.o
	g++ -o $(TARGET) hw1.o

hw1.o:hw1.cpp
	g++ -c hw1.cpp

clean:
	rm -f *.o *.out
