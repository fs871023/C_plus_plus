TARGET = test.out
CC = g++
obj = test.o bigint.o 
all:$(TARGET)

$(TARGET) : $(obj)
	$(CC) -o $@ $^
test.o : test.cpp bigint.h
	$(CC) -c -o $@ $<
bigint.o : bigint.cpp bigint.h
	$(CC) -c -o $@ $<

.PHONY : clean
clean :
	rm -f *.o *.out 
