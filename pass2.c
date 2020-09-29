#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
void main()
{
	FILE *out,*out1,*ala1,*ala2,*ala3;
	int INDEX1=0,marker1=1,marker2=1,marker3=1;
	char mne[20],la[20],opnd[20];
	out=fopen("output.txt","r");
	out1=fopen("output1.txt","w");
	ala1=fopen("ala1.txt","w");
	ala2=fopen("ala2.txt","w");
	ala3=fopen("ala3.txt","w");
	fscanf(out,"%s%s%s",la,mne,opnd);
		fprintf(out1,"%s\t%s\t%s\n",la,mne,opnd);
	if(strcmp(mne,"START")==0)
	{
		fscanf(out,"%s\t%s\t%s",la,mne,opnd);	
		while(strcmp(mne,"add")!=0)
		{
			
			fprintf(out1,"%s\t%s\t%s\n",la,mne,opnd);
			fscanf(out,"%s\t%s\t%s",la,mne,opnd);
		}
			while(strcmp(mne,"END")!=0)
			{
				if(strcmp(mne,"add")==0)
				{
					fprintf(ala1,"index\targument\n");
					fprintf(ala1,"#%d\t%s\n",INDEX1,la);
					fprintf(ala1,"#%d\t%s\n",++INDEX1,opnd);
				fprintf(out1,"%s\tA\t%d,%s\n",la,marker1,opnd);
									
					fprintf(out1,"-\tA\t%d,%s\n",++marker1,opnd);
					fscanf(out,"%s\t%s\t%s",la,mne,opnd);
					fprintf(out1,"%s\t%s\t%s\n",la,mne,opnd);
					INDEX1=0;									
				}
				fscanf(out,"%s\t%s\t%s",la,mne,opnd);
				if(strcmp(mne,"add")==0)
				{
					fprintf(ala2,"index\targument\n");
					fprintf(ala2,"#%d\t%s\n",INDEX1,la);
					fprintf(ala2,"#%d\t%s\n",++INDEX1,opnd);
					fprintf(out1,"%s\tA\t%d,%s\n",la,marker2,opnd);
									
					fprintf(out1,"-\tA\t%d,%s\n",++marker2,opnd);
					fscanf(out,"%s\t%s\t%s",la,mne,opnd);
					fprintf(out1,"%s\t%s\t%s\n",la,mne,opnd);
					INDEX1=0;									
				}
					fscanf(out,"%s\t%s\t%s",la,mne,opnd);
				if(strcmp(mne,"add")==0)
				{
				fprintf(ala3,"index\targument\n");
					fprintf(ala3,"#%d\t%s\n",INDEX1);
					fprintf(ala3,"#%d\t%s\n",++INDEX1,opnd);
					fprintf(out1,"%s\tA\t%d,%s\n",la,marker3,opnd);
									
					fprintf(out1,"-\tA\t%d,%s\n",++marker3,opnd);
					fscanf(out,"%s\t%s\t%s",la,mne,opnd);
					fprintf(out1,"%s\t%s\t%s\n",la,mne,opnd);
					INDEX1=0;									
				}	
					
			}
	}
	fclose(out);
	fclose(out1);
	fclose(ala1);
	fclose(ala2);
	fclose(ala3);	
	printf("pass 2 is successful");
	getch();
		
}
