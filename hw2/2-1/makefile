TARGET=hw2_1.out

all:$(TARGET)

$(TARGET):hw2_1.o
	g++ -o $(TARGET) hw2_1.o

%.o:%.cpp 
	g++ -c $*.cpp $c  

clean:
	rm -f *.o *.out 
