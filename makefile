a.out:main.o slist.o
	gcc -o a.out main.o slist.o

main.o:main.c slist.h
	gcc -c -o main.o main.c


slist.o:slist.c slist.h
	gcc -c -o slist.o slist.c

clean:
	rm *.o *.exe
