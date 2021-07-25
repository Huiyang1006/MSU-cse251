Scheduler:	Scheduler.o Menu.o IO.o
	gcc -o Scheduler Scheduler.o Menu.o IO.o

Scheduler.o:	Scheduler.c Scheduler.h
	gcc -c Scheduler.c

Menu.o:	Menu.c Scheduler.h
	gcc -c Menu.c

IO.o: IO.c
	gcc -c IO.c

clean:
	rm -f *.o Scheduler
