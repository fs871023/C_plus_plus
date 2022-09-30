TARGET = 2_3_ring.out
CC = g++
obj = 2_3_ring.o

all:$(TARGET)

$(TARGET) : $(obj)
	$(CC) -o $@ $^
2_3_ring.o : 2_3_ring.cpp ring.h
	$(CC) -c -o $@ $<

.PHONY : clean
clean :
	rm -f *.o *.out 
