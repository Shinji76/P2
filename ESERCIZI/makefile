CC = gcc -std=c++0x

%.o: %.cpp
	${CC} -cpp $< -o $@

main: queue.o queue.cpp
	${CC} queue.o queue.cpp -lm -o $@

clear:
	rm *.o main
