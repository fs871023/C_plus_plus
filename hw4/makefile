TARGET = main.out
CC = g++
obj = main.o Polygon.o Polynomial.o
all:$(TARGET)

$(TARGET) : $(obj)
	$(CC) -c $@ $^
main.o : main.cpp Polygon.h
	$(CC) -c -o $@ $<
Polygon.o : Polygon.cpp Polygon.h
	$(CC) -c -o $@ $<
Polynomial.o : Polynomial.cpp Polynomial.h
	$(CC) -c -o $@ $<

.PHONY : clean
clean :
	rm -f *.o *.out 
