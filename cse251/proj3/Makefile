Scheduler:	Scheduler.o Menu.o IO.o fileIO.o
	gcc -o Scheduler Scheduler.o Menu.o IO.o fileIO.o

Scheduler.o:	Scheduler.c Scheduler.h Menu.h IO.h
	gcc -c Scheduler.c

Menu.o:	Menu.c menu.h Scheduler.h IO.h
	gcc -c Menu.c

IO.o: IO.c IO.h Scheduler.h
	gcc -c IO.c

fileIO.o:	fileIO.c Scheduler.h
	gcc -c fileIO.c

clean:
	rm -f *.o Scheduler
