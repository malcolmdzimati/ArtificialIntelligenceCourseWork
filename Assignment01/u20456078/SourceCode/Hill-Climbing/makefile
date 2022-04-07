make:
	g++ -c *.cpp
	g++ *.o -o HC

run:
	./HC

clean:
	rm *.o
	rm HC

debug:
	g++ -c *.cpp
	g++ *.o -g -o debug
	gdb debug
	rm *.o
	rm debug
