build : pb_webdev

pb_webdev : pb_webdev.o functions.o
	gcc -g -o pb_webdev *.o

pb_webdev.o : pb_webdev.c functions.h
	gcc -g -o pb_webdev.o -c pb_webdev.c

functions.o : functions.c functions.h
	gcc -g -o functions.o -c functions.c

clean :
	rm -f pb_webdev *.o
