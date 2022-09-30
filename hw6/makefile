TARGET = main.out
CC = g++
obj = main.o Student.o 
all:$(TARGET)

$(TARGET) : $(obj)
	$(CC) -c $@ $^
main.o : main.cpp Student.h
	$(CC) -c -o $@ $<
Student.o : Student.cpp Student.h
	$(CC) -c -o $@ $<

.PHONY : clean
clean :
	rm -f *.o *.out 
