#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#include "dijkstra.h"
#include "passengerlist.h"
#include "graph.h"
#include "TrainDate.h"

List L;


float ticketcost(float dist,char Class[])
{
	if (!strcmpi(Class,"First"))
	{
		printf("Ticket Cost = %.2f \n",dist*1);
		return dist*1;
	}
	else if (!strcmpi(Class,"Second"))
	{
		printf("Ticket Cost = %.2f \n",dist*0.5);
		return dist*0.5;
	}
	else if (!strcmpi(Class,"Sleeper"))
	{
		printf("Ticket Cost = %.2f \n",dist*0.35);
		return dist*0.35;
	}
	else
	{
		printf("Invalid Class !!!\n");
		return 0.0;
	}
}

void displaystations()
{
	printf("Stations : \n");
	for(int i=0;i<5;i++)
	{
		printf("%d ) %s\n",i,p[i]);
	}
}

int findindex(char str[])
{
	for(int i=0;i<5;i++)
	{
		if(!strcmp(p[i],str))
			return i;
	}
	return -1;
}



void Book(int G[][5])
{
	int dist;
	printf("WELCOME.\n");
	int num;
	float total=0.0;
	char src[100],dest[100];int start,end;
	int dt,mt,yr;
	printf("Enter the date on which you have to book tickets:(dd-mm-yyy)\n");
	scanf("%d-%d-%d",&dt,&mt,&yr);
	int doi=-1;//dateofinterest
	int toi=-1;//train of interest
	for(int i=0;i<7;i++)
	{
		if(dat[i].dd==dt && dat[i].mm==mt && dat[i].yy==yr)
		{
			doi=i;
			break;
		}
	}
	int flag=0;
	if(doi!=-1)
	{
		printf("Enter the number of tickets to be booked:");
		scanf("%d",&num);
		displaystations();
		int tflag=0;
		for(int j=0;j<num;j++)
		{
			printf("\n\nEnter boarding point:");
			scanf("%s",src);
			printf("Enter the destination:");
			scanf("%s",dest);
			printf("Trains:\n");
			printf("Name\t\t\t\tFC\tSC\tSL\n");
			for(int i=0;i<20;i++)
			{
				if((!strcmpi(dat[doi].t[i].src,src)||(!strcmpi(dat[doi].t[i].via,src))) && ((!strcmpi(dat[doi].t[i].dest,dest)||(!strcmpi(dat[doi].t[i].via,dest)))))
				{
					if((dat[doi].t[i].tick1>0)|(dat[doi].t[i].tick2>0)|(dat[doi].t[i].tick3>0))
					{
						printf("%-30s\t%d\t%d\t%d\n",dat[doi].t[i].tname,dat[doi].t[i].tick1,dat[doi].t[i].tick2,dat[doi].t[i].tick3);
						tflag=1;
					}
					
				}
			}
			if(tflag==0)
			{
				printf("No Trains Available\n");
				break;
			}
		char trainname[100];
		printf("Enter Train Name:");
		scanf(" %[^\n]",trainname);
		for(int i=0;i<20;i++)
		{
			if(!strcmpi(dat[doi].t[i].tname,trainname))
				{
				toi=i;
				break;
				}
		}
		details det;
		if(toi!=-1)
		{
			printf("Enter class:");
			scanf("%s",det.Class);
			if(!strcmpi(det.Class,"First"))
			{
				if(dat[doi].t[toi].tick1>0)
				{
					printf("\nEnter name:");
					scanf("%s",det.name);
					printf("Enter gender(M/F/T):");
					scanf(" %c",&det.gender);
					printf("Enter age:");
					scanf("%d",&det.age);
					printf("Enter proof of identity:");
					scanf("%s",det.proof);
					strcpy(det.src,src);
					strcpy(det.dest,dest);
					start=findindex(det.src);
					end=findindex(det.dest);
					dist=dijkstradist(G,5,start,end);
					det.cost=ticketcost(dist,det.Class);
					--dat[doi].t[toi].tick1;
					
					addend(dat[doi].t[toi].L,det);
					
					total+=det.cost;
				}
				else
				{
					printf("Not enough tickets!!!\n");
					flag=-1;
				}
			}
			else if(!strcmpi(det.Class,"Second"))
			{
				if(dat[doi].t[toi].tick2>0)
				{
					printf("\nEnter name:");
					scanf("%s",det.name);
					printf("Enter gender(M/F/T):");
					scanf(" %c",&det.gender);
					printf("Enter age:");
					scanf("%d",&det.age);
					printf("Enter proof of identity:");
					scanf("%s",det.proof);
					strcpy(det.src,src);
					strcpy(det.dest,dest);
					start=findindex(det.src);
					end=findindex(det.dest);
					dist=dijkstradist(G,5,start,end);
					det.cost=ticketcost(dist,det.Class);
					--dat[doi].t[toi].tick2;
					
					addend(dat[doi].t[toi].L,det);
					
					total+=det.cost;
				}
				else
				{
					printf("Not enough tickets!!!\n");
					flag=-1;
				}
			}
			else if(!strcmpi(det.Class,"Sleeper"))
			{
				if(dat[doi].t[toi].tick3>0)
				{
					printf("\nEnter name:");
					scanf("%s",det.name);
					printf("Enter gender(M/F/T):");
					scanf(" %c",&det.gender);
					printf("Enter age:");
					scanf("%d",&det.age);
					printf("Enter proof of identity:");
					scanf("%s",det.proof);
					strcpy(det.src,src);
					strcpy(det.dest,dest);
					start=findindex(det.src);
					end=findindex(det.dest);
					dist=dijkstradist(G,5,start,end);
					det.cost=ticketcost(dist,det.Class);
					--dat[doi].t[toi].tick3;
					
					addend(dat[doi].t[toi].L,det);
					
					total+=det.cost;
				}
				else
				{
					printf("Not enough tickets!!!\n");
					flag=-1;
				}
			}
			else
			{
				printf("Invalid Class!\n");
				flag=-1;
			}
			
			}
		else
		{
			printf("Invalid train name.\n");
		}
			
		}
			if(toi!=-1 && flag!=-1
			)
			{
			printf("\nTotal Cost : %.2f",total);
			printf("\nTickets Booked !!!\n");
			}
		
			}
	else
	{
		printf("Invalid Date!!!\n");
	}

}


void Status()
{

	int dt,mt,yr;
	printf("Enter the date:(dd-mm-yyy)\n");
	scanf("%d-%d-%d",&dt,&mt,&yr);
	int doi=-1;//dateofinterest
	int toi=-1;//train of interest
	for(int i=0;i<7;i++)
	{
		if(dat[i].dd==dt && dat[i].mm==mt && dat[i].yy==yr)
		{
			doi=i;
			break;
		}
	}
	if(doi!=-1)
	{
		char trainname[100];
		printf("Enter Train Name:");
		scanf(" %[^\n]",trainname);
		for(int i=0;i<20;i++)
		{
			if(!strcmpi(dat[doi].t[i].tname,trainname))
				{
				toi=i;
				break;
				}
		}
		if(toi!=-1)
		{
		
			char name[100];
			printf("Enter the name to know status:");
			scanf("%s",name);
			int st;
			printf("\tDetails:\n");
			st=Find(dat[doi].t[toi].L,name);
			if(st!=-1)
			{
					printf("Status\t\t: Your tickets are confirmed.\n");
			}
		}
		else
		{
			printf("Invalid train name!!\n");
		}

				
}
else
{
	printf("Invalid date!!\n");
}
		
}

void Cancel()
{
	int dt,mt,yr;
	printf("Enter the date:(dd-mm-yyy)\n");
	scanf("%d-%d-%d",&dt,&mt,&yr);
	int doi=-1;//dateofinterest
	int toi=-1;//train of interest
	for(int i=0;i<7;i++)
	{
		if(dat[i].dd==dt && dat[i].mm==mt && dat[i].yy==yr)
		{
			doi=i;
			break;
		}
	}
	if(doi!=-1)
	{
		char trainname[100];
		printf("Enter Train Name:");
		scanf(" %[^\n]",trainname);
		for(int i=0;i<20;i++)
		{
			if(!strcmpi(dat[doi].t[i].tname,trainname))
				{
				toi=i;
				break;
				}
		}
		if(toi!=-1)
		{
		
			char name[100];
			printf("Enter the name whose ticket is to be cancelled:");
			scanf("%s",name);
			int ret;
			ret=Delete(dat[doi].t[toi].L,name);
			if (ret==1)
			{
				++dat[doi].t[toi].tick1;
				printf("Cancelled successfully!\n");
			}
			else if (ret==2)
			{
				++dat[doi].t[toi].tick2;
				printf("Cancelled successfully!\n");
			}		
			else if(ret==3)
			{
				++dat[doi].t[toi].tick3;
				printf("Cancelled successfully!\n");
			}
		}
		else
		{
			printf("Invalid train name.\n");
		}
	}
	else
	{
		printf("Invalid date!!\n");
		
	}
}


void Routes(int G[][5])
{
	int fs[5],size;
	int ch=1;
	char Start[50];
	int start;
	//while(ch!=0)
	//{
		printf("Shortest Routes\n\t\t");
		//scanf("%d",&ch);
		//switch(ch)
		//{
			/*case 1 :
					displaystations();
					printf("\nEnter Boarding Station : ");
					scanf("%d",&start);
					size=0;
					size=dfs(start,G,fs,size);
					printf("DFS : \n");
					for(int i=0;i<5;i++)
						printf("%s ",p[fs[i]]);
					printf("\n");
					break;
			case 2 :
					displaystations();
					printf("\nEnter Boarding Station : ");
					scanf("%d",&start);
					size=0;
					size=bfs(start,G,fs,size);
					printf("BFS : \n");
					for(int i=0;i<5;i++)
						printf("%s ",p[fs[i]]);
					printf("\n");
					break;
			case 3 :
			*/
					displaystations();
					printf("\nEnter Boarding Station Name : ");
					scanf("%s",Start);
					start=findindex(Start);
					dijkstra(G,5,start);
					//break;
			//case 0 : break;
			//default : printf("Invalid Choice \n");
		//}
	//}
}

void Chart()
{
	int dt,mt,yr;
	printf("Enter the date:(dd-mm-yyy)\n");
	scanf("%d-%d-%d",&dt,&mt,&yr);
	int doi=-1;//dateofinterest
	int toi=-1;//train of interest
	for(int i=0;i<7;i++)
	{
		if(dat[i].dd==dt && dat[i].mm==mt && dat[i].yy==yr)
		{
			doi=i;
			break;
		}
	}
	if(doi!=-1)
	{
		char trainname[100];
		printf("Enter Train Name:");
		scanf(" %[^\n]",trainname);
		for(int i=0;i<20;i++)
		{
			if(!strcmpi(dat[doi].t[i].tname,trainname))
				{
				toi=i;
				break;
				}
		}
		if(toi!=-1)
		{
			printf("\n\t\tReservation Chart.\n");
			printf("----------------------------------------------------------------------------------\n");
			disp(dat[doi].t[toi].L);
			printf("----------------------------------------------------------------------------------\n");
		}
		else
			printf("Invalid Train name!\n");
	}
	else
			printf("Invalid Date!\n");
}


void Availability()
{
	int dt,mt,yr;
	printf("Enter the date:(dd-mm-yyy)\n");
	scanf("%d-%d-%d",&dt,&mt,&yr);
	int doi=-1;//dateofinterest
	int toi=-1;//train of interest
	for(int i=0;i<7;i++)
	{
		if(dat[i].dd==dt && dat[i].mm==mt && dat[i].yy==yr)
		{
			doi=i;
			break;
		}
	}
	if(doi!=-1)
	{
		char trainname[100];
		printf("Enter Train Name:");
		scanf(" %[^\n]",trainname);
		for(int i=0;i<20;i++)
		{
			if(!strcmpi(dat[doi].t[i].tname,trainname))
				{
				toi=i;
				break;
				}
		}
		if(toi!=-1)
		{
			printf("\nNo. of tickets available in First Class   :  %d\n",dat[doi].t[toi].tick1);
			printf("No. of tickets available in Second Class  :  %d\n",dat[doi].t[toi].tick2);
			printf("No. of tickets available in Sleeper Class :  %d\n",dat[doi].t[toi].tick3);
		}
		else
			printf("Invalid train name!!\n");
	}
	else
		printf("Invalid date!\n");
}
