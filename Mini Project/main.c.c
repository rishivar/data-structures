#include "railway.h"

int main()
{
	int ch;
	int Graph[5][5];
	List L=CreateEmptylist();
	traininitialise();
	stationInitialise(Graph);
	while(1)
	{
		printf("\n\t\t\tMenu");
		printf("\n\t\t1.Book\n\t\t2.Ticket Status\n\t\t3.Cancel Ticket");
		printf("\n\t\t4.Routes available\n\t\t5.Reservation List\n\t\t6.Ticket Availability");
		printf("\n\t\t7.Display All Trains\n\t\t0.Exit\n\t\tEnter Choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1  :Book(Graph);break;
			case 2  :Status();break;
			case 3  :Cancel();break;
			case 4  :Routes(Graph);break;
			case 5  :Chart();break;
			case 6  :Availability();break;
			case 7	:displaytrains();break;
			case 0  :exit(0);
			default :printf("Invalid Choice ");
		}
		printf("\nPress Enter to continue...\n");
		getch();
		system("cls");
	}
    return 0;
}
