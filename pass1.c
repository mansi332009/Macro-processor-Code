
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
void main()
{
FILE *f1,*f2,*f3,*f4,*f5;
char mne[20],opnd[20],la[20];

f1=fopen("input.txt","r");
f2=fopen("output.txt","w");
f3=fopen("mnt.txt","w");
f4=fopen("mdt.txt","w");
f5=fopen("ala.txt","w");
fscanf(f1,"%s%s%s",la,mne,opnd);
int index=1,INDEX=0,marker=1,m=0;
while(strcmp(mne,"MEND")!=0)
{
	if(strcmp(mne,"MACRO")==0)
	{
		fprintf(f3,"MNTC\tname\tMDTC entry\n");
		fprintf(f4,"MDTC\tcontent\n");
		fprintf(f5,"index\targuments\n");
		fscanf(f1,"%s%s%s",la,mne,opnd);
		fprintf(f3,"%d\t%s\t%d\n",index,mne,index);
		fprintf(f4,"%d\t%s\t%s\t%s\n",index,la,mne,opnd);
		fprintf(f5,"#%d\t%s\n",INDEX,la);
		fprintf(f5,"#%d\t%s\n",++INDEX,opnd);
	}
	else if(strcmp(mne,"A")==0)
	{
		if(index==1)
		{
			
			fprintf(f4,"%d\t#%d\tA\t%d,#%d\n",++index,m,marker,INDEX);
			
		}
		else
			fprintf(f4,"%d\t-\tA\t%d,#%d\n",++index,++marker,INDEX);
	}

fscanf(f1,"%s%s%s",la,mne,opnd);
}
fprintf(f4,"%d\t%s",++index,mne);
fscanf(f1,"%s%s%s",la,mne,opnd);
while(strcmp(mne,"END")!=0)
{
	if(strcmp(mne,"START")==0)
	{
		
		fprintf(f2,"%s\t%s\t%s\n",la,mne,opnd);
	}
	else
	{
		
		fprintf(f2,"%s\t%s\t%s\n",la,mne,opnd);
	}
	fscanf(f1,"%s\t%s\t%s",la,mne,opnd);	
}
fprintf(f2,"%s\t%s\t%s\n",la,mne,opnd);
fclose(f1);
fclose(f2);

printf("PASS 1 is successful");
getch();
}
