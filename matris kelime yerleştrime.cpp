#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <string.h>
main()
{
	int n,index=0,i,sayi,x,y;
	int yon;
	int secim;
	srand(time(NULL));
    char matris2[4][50]={{"SOFTWARE"},{"COMPILER"},{"FLUTTER"},{"REACT"}};
	do
	{printf("\n Lutfen n 8den buyuk olmak uzere n degeri girin: ");
	 scanf("%d",&n);
	}while(n<9);
	char matris[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			matris[i][j]='*';
		}
	}
	do{printf("\nDuz icin 1,capraz icin 2 giriniz: ");
	   scanf("%d",&secim);
	}while(secim!=1&&secim!=2);
	int yonler[4];
	do{
		yonler[0]=rand()%4;	
		yonler[1]=rand()%4;	
		yonler[2]=rand()%4;	
		yonler[3]=rand()%4;		
	}while(yonler[2]==yonler[3]||yonler[1]==yonler[3]||yonler[1]==yonler[2]||yonler[0]==yonler[3]||yonler[0]==yonler[2]||yonler[0]==yonler[1]);
	int kelimeno=0;
	if(secim==1)//duz için yapýyoruz..
	{    
	   while(kelimeno<4)
		{	
			olmadi:
			y=rand()%n;
			x=rand()%n;
			if(yonler[kelimeno]==0)//sag
			{
				index=0;
				while(matris2[kelimeno][index]!='\0')
				{
					if(matris[y][x+index]!='*' && matris[y][x+index]!=matris2[kelimeno][index])
					{
						goto olmadi;
					}
					if(x+index>=n)
					{
						goto olmadi;
					}
				index++;
				}
				index=0;
				while(matris2[kelimeno][index]!='\0')
				{
					matris[y][x+index]=matris2[kelimeno][index];
					index++;
				}
			}
			if(yonler[kelimeno]==1)//sola git!!
			{
				index=0;
				while(matris2[kelimeno][index]!='\0')
				{
					if(matris[y][x-index]!='*' && matris[y][x-index]!=matris2[kelimeno][index])
					{
						goto olmadi;
					}
					
					if(x-index<0)
					{
						goto olmadi;
					}
					index++;
				}
				index=0;
				while(matris2[kelimeno][index]!='\0')
				{
					matris[y][x-index]=matris2[kelimeno][index];
					index++;
				}
			}
			if(yonler[kelimeno]==2)//yukarý git!!
			{
				index=0;
				while(matris2[kelimeno][index]!='\0')
				{
					if(matris[y-index][x]!='*' && matris[y-index][x]!=matris2[kelimeno][index])
					{
						goto olmadi;
					}
					if(y-index<0)
					{
						goto olmadi;
					}
					index++;
				}
				index=0;
				while(matris2[kelimeno][index]!='\0')
				{
					matris[y-index][x]=matris2[kelimeno][index];
					index++;
				}
			}
			if(yonler[kelimeno]==3)//asagý git!!
			{
				index=0;
				while(matris2[kelimeno][index]!='\0')
				{
					if(matris[y+index][x]!='*' && matris[y+index][x]!=matris2[kelimeno][index])
					{
						goto olmadi;
					}
					if(y+index>=n)
					{
						goto olmadi;
					}
					index++;
				}
				index=0;
				while(matris2[kelimeno][index]!='\0')
				{
					matris[y+index][x]=matris2[kelimeno][index];
					index++;
				}
			}
			kelimeno++;
		}
	}
		else if(secim==2)//capraza geciyoruz
		{
			while(kelimeno<4)
			{	
				olmadicapraz:
				y=rand()%n;
				x=rand()%n;	
				if(yonler[kelimeno]==0)
				{
				    index=0;
					while(matris2[kelimeno][index]!='\0')
					{
						if(matris[y+index][x+index]!='*' && matris[y+index][x+index]!=matris2[kelimeno][index])
						{
							goto olmadicapraz;
						}
						if(x+index>=n || y+index>=n)
						{
							goto olmadicapraz;
						}
					index++;
					}
					index=0;
					while(matris2[kelimeno][index]!='\0')
					{
						matris[y+index][x+index]=matris2[kelimeno][index];
						index++;
					}
				}
				if(yonler[kelimeno]==1)
				{
					index=0;
					while(matris2[kelimeno][index]!='\0')
						{
						if(matris[y-index][x-index]!='*' && matris[y-index][x-index]!=matris2[kelimeno][index])
						{
							goto olmadicapraz;
							}
						
							if(x-index<0 || y-index<0)
						{
							goto olmadicapraz;
							}
						index++;
					}
					index=0;
					while(matris2[kelimeno][index]!='\0')
						{
						matris[y-index][x-index]=matris2[kelimeno][index];
						index++;
					}
				}
				if(yonler[kelimeno]==2)
				{
					index=0;
					while(matris2[kelimeno][index]!='\0')
					{
						if(matris[y-index][x+index]!='*' && matris[y-index][x+index]!=matris2[kelimeno][index])
							{
							goto olmadicapraz;
							}
						
							if(y-index<0||x+index>=n)
							{
							goto olmadicapraz;
						}
						index++;
					}
					index=0;
					while(matris2[kelimeno][index]!='\0')
					{
						matris[y-index][x+index]=matris2[kelimeno][index];
						index++;
					}
				}
				if(yonler[kelimeno]==3)//asagý git!!
				{
					index=0;
					while(matris2[kelimeno][index]!='\0')
					{
						if(matris[y+index][x-index]!='*' && matris[y+index][x-index]!=matris2[kelimeno][index])
						{
							goto olmadicapraz;
						}
					
						if(y+index>=n||x-index<0)
						{
							goto olmadicapraz;
						}
						index++;
					}
					index=0;
					while(matris2[kelimeno][index]!='\0')
					{
						matris[y+index][x-index]=matris2[kelimeno][index];
						index++;
					}
				}	
			kelimeno++;
			}	
		}
	for(int i=0;i<n;i++)
	{
		printf("\n");
		for(int j=0;j<n;j++)
		{
			if(matris[i][j]=='*')
			{
				matris[i][j]=49+rand()%3;
			}
			printf(" %c ",matris[i][j]);
		}
	}
	main();
}
