#include<string.h>

typedef struct 
{
	char tname[100];
	char tno[10];
	int tick1,tick2,tick3;
	char src[100];
	char dest[100];
	char via[100];
	List L;
}train;

typedef struct 
{
	int dd;
	int mm;
	int yy;
	train t[20];
}date;

date dat[7];

int da=1;
int mo=12;
int ye=19;

void traininitialise()
{

	for(int i=0;i<7;i++)
	{
	dat[i].dd=da;
	dat[i].mm=mo;
	dat[i].yy=ye;
	
	strcpy(dat[i].t[0].tname,"Cheran Express");
	strcpy(dat[i].t[0].tno,"16007");
	strcpy(dat[i].t[0].src,"Chennai");
	strcpy(dat[i].t[0].dest,"Coimbatore");
	strcpy(dat[i].t[0].via,"Villupuram");
	
	strcpy(dat[i].t[1].tname,"Pandian Express");
	strcpy(dat[i].t[1].tno,"16010");
	strcpy(dat[i].t[1].src,"Chennai");
	strcpy(dat[i].t[1].dest,"Madurai");
	strcpy(dat[i].t[1].via,"Villupuram");
	
	strcpy(dat[i].t[2].tname,"Pudhuvai Express");
	strcpy(dat[i].t[2].tno,"16018");
	strcpy(dat[i].t[2].src,"Chennai");
	strcpy(dat[i].t[2].dest,"Pondicherry");
	strcpy(dat[i].t[2].via,"None");

	strcpy(dat[i].t[3].tname,"Villupuram Express");
	strcpy(dat[i].t[3].tno,"16045");
	strcpy(dat[i].t[3].src,"Chennai");
	strcpy(dat[i].t[3].dest,"Villupuram");
	strcpy(dat[i].t[3].via,"None");
	
	strcpy(dat[i].t[4].tname,"Chennai Express");
	strcpy(dat[i].t[4].tno,"16107");
	strcpy(dat[i].t[4].src,"Coimbatore");
	strcpy(dat[i].t[4].dest,"Chennai");
	strcpy(dat[i].t[4].via,"Villupuram");

	strcpy(dat[i].t[5].tname,"Madurai Express");
	strcpy(dat[i].t[5].tno,"16110");
	strcpy(dat[i].t[5].src,"Coimbatore");
	strcpy(dat[i].t[5].dest,"Madurai");
	strcpy(dat[i].t[5].via,"None");

	strcpy(dat[i].t[6].tname,"Pondy Express");
	strcpy(dat[i].t[6].tno,"16118");
	strcpy(dat[i].t[6].src,"Coimbatore");
	strcpy(dat[i].t[6].dest,"Pondicherry");
	strcpy(dat[i].t[6].via,"Villupuram");

	strcpy(dat[i].t[7].tname,"VizhimaNagar Express");
	strcpy(dat[i].t[7].tno,"16145");
	strcpy(dat[i].t[7].src,"Coimbatore");
	strcpy(dat[i].t[7].dest,"Villupuram");
	strcpy(dat[i].t[7].via,"None");

	strcpy(dat[i].t[8].tname,"Madras Express");
	strcpy(dat[i].t[8].tno,"16207");
	strcpy(dat[i].t[8].src,"Madurai");
	strcpy(dat[i].t[8].dest,"Chennai");
	strcpy(dat[i].t[8].via,"Villupuram");

	strcpy(dat[i].t[9].tname,"Kovai Express");
	strcpy(dat[i].t[9].tno,"16210");
	strcpy(dat[i].t[9].src,"Madurai");
	strcpy(dat[i].t[9].dest,"Coimbatore");
	strcpy(dat[i].t[9].via,"None");

	strcpy(dat[i].t[10].tname,"Gingee Express");
	strcpy(dat[i].t[10].tno,"16218");
	strcpy(dat[i].t[10].src,"Madurai");
	strcpy(dat[i].t[10].dest,"Villupuram");
	strcpy(dat[i].t[10].via,"None");

	strcpy(dat[i].t[11].tname,"Pondicherry Express");
	strcpy(dat[i].t[11].tno,"16245");
	strcpy(dat[i].t[11].src,"Madurai");
	strcpy(dat[i].t[11].dest,"Pondicherry");
	strcpy(dat[i].t[11].via,"None");

	strcpy(dat[i].t[12].tname,"Pallavan Express");
	strcpy(dat[i].t[12].tno,"16307");
	strcpy(dat[i].t[12].src,"Pondicherry");
	strcpy(dat[i].t[12].dest,"Chennai");
	strcpy(dat[i].t[12].via,"None");

	strcpy(dat[i].t[13].tname,"Coimbatore Express");
	strcpy(dat[i].t[13].tno,"16310");
	strcpy(dat[i].t[13].src,"Pondicherry");
	strcpy(dat[i].t[13].dest,"Coimbatore");
	strcpy(dat[i].t[13].via,"Villupuram");

	strcpy(dat[i].t[14].tname,"Vaigai Express");
	strcpy(dat[i].t[14].tno,"16318");
	strcpy(dat[i].t[14].src,"Pondicherry");
	strcpy(dat[i].t[14].dest,"Madurai");
	strcpy(dat[i].t[14].via,"None");

	strcpy(dat[i].t[15].tname,"Tondai Express");
	strcpy(dat[i].t[15].tno,"16345");
	strcpy(dat[i].t[15].src,"Pondicherry");
	strcpy(dat[i].t[15].dest,"Villupuram");
	strcpy(dat[i].t[15].via,"None");

	strcpy(dat[i].t[16].tname,"Coramandel Express");
	strcpy(dat[i].t[16].tno,"16407");
	strcpy(dat[i].t[16].src,"Villupuram");
	strcpy(dat[i].t[16].dest,"Chennai");
	strcpy(dat[i].t[16].via,"None");

	strcpy(dat[i].t[17].tname,"Noyyal Express");
	strcpy(dat[i].t[17].tno,"16410");
	strcpy(dat[i].t[17].src,"Villupuram");
	strcpy(dat[i].t[17].dest,"Coimbatore");
	strcpy(dat[i].t[17].via,"None");

	strcpy(dat[i].t[18].tname,"Koodal Express");
	strcpy(dat[i].t[18].tno,"16418");
	strcpy(dat[i].t[18].src,"Villupuram");
	strcpy(dat[i].t[18].dest,"Madurai");
	strcpy(dat[i].t[18].via,"None");

	strcpy(dat[i].t[19].tname,"Puducherry Express");
	strcpy(dat[i].t[19].tno,"16445");
	strcpy(dat[i].t[19].src,"Villupuram");
	strcpy(dat[i].t[19].dest,"Pondicherry");
	strcpy(dat[i].t[19].via,"None");

	for(int j=0;j<20;j++)
	{
		dat[i].t[j].tick1=500;
		dat[i].t[j].tick2=750;
		dat[i].t[j].tick3=1250;
		dat[i].t[j].L=CreateEmptylist();
	}
	++da;  // This is a normal case where we are incrementing the date alone
	
	}
}

void displaytrains()
{
	printf("\nTrain No\tTrain Name\t\tSource\t\tDestination\n");
	printf("----------------------------------------------------------------------------------\n");
	for(int i=0;i<20;i++)
	{
		printf("%s\t\t%s   \t%s  \t%s\n",dat[0].t[i].tno,dat[0].t[i].tname,dat[0].t[i].src,dat[0].t[i].dest);
	}
	printf("----------------------------------------------------------------------------------\n");
	
}
