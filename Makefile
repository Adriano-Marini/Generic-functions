all: main_int main_str

main_str: functions.o test_str.o
	gcc -Wall -o $@ $^
main_int: functions.o test_str.o
	gcc -Wall -o $@ $^
test_str.o: test_str.c library.h
	gcc -Wall -c -o test_str.o test_str.c
test_int.o: test_int.c library.h
	gcc -Wall -c -o test_int.o test_int.c
	
functions.o: functions.c library.h
	gcc -Wall -c -o functions.o functions.c

clean: 
	rm -rf *.o main_int main_str
