#include<stdio.h>
#include<string.h>

typedef struct student{
	char id[10];
	int c[2];
	int m[2];
	int e[2];
	int a[2]; 
}student;

int main()
{   
    int n,m;
    scanf("%d %d",&n,&m);
	student stu[n];
	for(int i=0;i<n;i++)  //输入成绩信息 
	{
		scanf("%s %d %d %d",stu[i].id,&stu[i].c[0],&stu[i].m[0],&stu[i].e[0]);		
		stu[i].a[0]=(stu[i].c[0]+stu[i].m[0]+stu[i].e[0])/3;
	}
	
	for(int i=0;i<n;i++) //排名 
	{   
	    stu[i].c[1]=1;
		stu[i].m[1]=1;
		stu[i].e[1]=1;
		stu[i].a[1]=1;
			   
		for(int j=0;j<n;j++)
		{
		if(stu[j].c[0]> stu[i].c[0])
		stu[i].c[1]++;
		if(stu[j].m[0]> stu[i].m[0])
		stu[i].m[1]++;
		if(stu[j].e[0]> stu[i].e[0])
		stu[i].e[1]++;
		if(stu[j].a[0]> stu[i].a[0])
		stu[i].a[1]++;
	    }
	}

	
	char key[10];
	for(int i=0;i<m;i++)  
	{   
	    int j;
		scanf("%s",key);
		
		for(j=0;j<n;j++)
		if(!strcmp(stu[j].id,key))
		break;
		if(j==n) 
		printf("N/A\n");
        else
        {
        	int k=stu[j].a[1];
	     	char course='A';
		
			if(stu[j].c[1]<k){
			k=stu[j].c[1];	
			course='C';
			}
			if(stu[j].m[1]<k){
			k=stu[j].m[1];	
			course='M';
			}
			
		
			if(stu[j].e[1]<k){
			k=stu[j].e[1];	
			course='E';
			}
		
			
			printf("%d %c\n",k,course);
        }	
	} 
	return 0;
}
