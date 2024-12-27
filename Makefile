all: main_int main_str main_triage main_printf

main_printf: functions.o test_printf.o
	gcc -Wall -o $@ $^

main_triage: functions.o test_triage.o
	gcc -Wall -o $@ $^
main_str: functions.o test_str.o
	gcc -Wall -o $@ $^
main_int: functions.o test_int.o
	gcc -Wall -o $@ $^
test_str.o: test_str.c library.h
	gcc -Wall -c -o test_str.o test_str.c
test_int.o: test_int.c library.h
	gcc -Wall -c -o test_int.o test_int.c
functions.o: functions.c library.h
	gcc -Wall -c -o functions.o functions.c
test_triage.o: triage.c library.h
	gcc -Wall -c -o test_triage.o triage.c
test_printf.o: mini_printf.c library.h
	gcc -Wall -c -o $@ mini_printf.c
clean: 
	rm -rf *.o main*
