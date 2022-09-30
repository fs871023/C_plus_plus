TARGET = main.out
CC = g++
obj = main.o Diamond.o 
all:$(TARGET)

$(TARGET) : $(obj)
	$(CC) -o $@ $^
main.o : main.cpp Diamond.h
	$(CC) -c -o $@ $<
Diamond.o : Diamond.cpp Diamond.h
	$(CC) -c -o $@ $<

.PHONY : clean
clean :
	rm -f *.o *.out 
