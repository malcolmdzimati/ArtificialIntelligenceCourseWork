make:
	g++ -c *.cpp
	g++ *.o -o ASA

run:
	./ASA

clean:
	rm *.o
	rm ASA

debug:
	g++ -c *.cpp
	g++ *.o -g -o debug
	gdb debug
	rm *.o
	rm debug
