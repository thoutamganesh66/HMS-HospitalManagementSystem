#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>


void home();
void add_disease();
void find_disease();
void find_BMI();
void find_reason();
void find_hospital();
void find_medicine();


struct symptoms{
    char symptom[100];
    }s1[3];


void main()
{
    home();
}


void home()
{
    int p;
    printf("**********************welcome*************************\n\n");
    printf("choose your option\n\n");
    printf("1.Add new disease details\n2.Find your disease\n3.Find your BMI\n4.Find reasons for your disease\n5.Find doctors available for your disease\n6.Find medicines for your disease\n7.exit\n\n\n");
    scanf("%d",&p);
    switch(p)
    {
    case 1:
            add_disease();
    case 2:
            find_disease();
    case 3:
            find_BMI();
    case 4:
            find_reason();
    case 5:
            find_hospital();
    case 6:
            find_medicine();
    case 7:
    		exit("");
    }
}


void add_disease(){
        FILE *f;
        f=fopen("disease1.txt","a");
        char disname[500];
        char symptoms[1000];
        char reasons[1000];
        char medicines[1000];
        char hospital[1000];
        int n;
        printf("Enter how many disease do u want to add : ");
        scanf("%d",&n);
        while(n>0){
                printf("Enter the disease name :");
                scanf("\n");
                gets(disname);
                printf("Enter the symptoms of %s : ",disname);
                scanf("\n");
                gets(symptoms);
                printf("Enter the reasons of %s : ",disname);
                scanf("\n");
                gets(reasons);
                printf("Enter the medicines for %s : ",disname);
                scanf("\n");
                gets(medicines);
                printf("Enter available hospitals followed by it's location for %s: ",disname);
                scanf("\n");
                gets(hospital);
                n--;
                fprintf(f,"%s;%s;%s;%s;%s;\n",disname,symptoms,reasons,medicines,hospital);
        }
        fclose(f);
printf("\n\npress any key to goto home_screen");
getch();
printf("\n\n\n");
home();
}


void find_disease()
{
    FILE *f;
    char disname[1000];
    char symptoms[1000];
    char reasons[1000];
    char medicines[1000];
    char hospital[1000];
    f=fopen("disease1.txt","r");
    int i=0;
    while(i<3){
        printf("Enter the symptom %d : ",i+1);
        scanf("\n");
        scanf("%s",s1[i].symptom); i++; }

    char c;
    int lc=0;
    while((c=getc(f))!=EOF){
        if(c=='\n'){
                lc++;
        }
    }
    fseek(f,0,SEEK_SET);
    while(lc>0){
            fscanf(f,"%[^;]s",disname);
            fseek(f,1,SEEK_CUR);
            fscanf(f,"%[^;]s",symptoms);
            fseek(f,1,SEEK_CUR);
            fscanf(f,"%[^;]s",reasons);
            fseek(f,1,SEEK_CUR);
            fscanf(f,"%[^;]s",medicines);
            fseek(f,1,SEEK_CUR);
            fscanf(f,"%[^;]s",hospital);
            fseek(f,2,SEEK_CUR);

            int c=0;
            int g=0;
            while(g<3){

                char *a=strstr(symptoms,s1[g].symptom);

            if((a)!=0){
                    c++;
                }
                g++;
            }

            if(c>=2){
                printf("\nYou may be suffering with %s",disname);
                printf("\n\n");
                printf("all other symptoms are :: %s",symptoms);
                printf("\n\n");
            }
            lc--;
    }
printf("press any key to goto home_screen");
getch();
printf("\n\n\n");
home();
}

void find_BMI()
{
	int age;
    float w,h,bmi;
    printf("enter your age: ");
    scanf("%d",&age);
    if(age>18 && age<=45){
    printf("enter your weight in kilograms:");
    scanf("%f",&w);
    printf("enter your height in metres:");
    scanf("%f",&h);
    bmi=(w/pow(h,2));
    printf("your BMI is: %f\n",bmi);
    if(bmi>=25)
        printf("you are overweight\n");
    else if(18.5<bmi && bmi<24.9)
        printf("you are normal\n");
    else if(bmi<18.5)
        printf("\nyou have malnutrition\n\n");
	}
	else
		printf("you are under-age\n\n");
printf("press any key to goto home screen");
getch();
printf("\n\n");
home();
}
void find_reason()
{
    FILE *f;
    char disname[50];
    char symptoms[500];
    char reasons[500];
    char medicines[500];
    char hospital[500];
    f=fopen("disease1.txt","r");
    int i=0;
    while(i<3){
        printf("Enter the symptom %d : ",i+1);
        scanf("\n");
        scanf("%s",s1[i].symptom); i++; }

    char c;
    int lc = 0;
    while((c=getc(f))!=EOF){
        if(c=='\n'){
                lc++;
        }
    }
    fseek(f,0,SEEK_SET);
    while(lc>0){
            fscanf(f,"%[^;]s",disname);
            fseek(f,1,SEEK_CUR);
            fscanf(f,"%[^;]s",symptoms);
            fseek(f,1,SEEK_CUR);
            fscanf(f,"%[^;]s",reasons);
            fseek(f,1,SEEK_CUR);
            fscanf(f,"%[^;]s",medicines);
            fseek(f,1,SEEK_CUR);
            fscanf(f,"%[^;]s",hospital);
            fseek(f,2,SEEK_CUR);

            int c=0;
            int g=0;
            while(g<3){

                char *a=strstr(symptoms,s1[g].symptom);

            if((a)!=0){
                    c++;
                }
                g++;
            }

            if(c>=2){
            	printf("\nThe disease may be %s\n",disname);
                printf("\n\ncauses for your symptoms may be: %s\n\n",reasons);
            }
            lc--;
    }
printf("press any key to goto home_screen");
getch();
printf("\n\n\n");
home();
}


void find_hospital()
{
FILE *f;
    char disname[50];
    char symptoms[500];
    char reasons[500];
    char medicines[500];
    char hospital[500];
    f=fopen("disease1.txt","r");
    int i=0;
    while(i<3){
        printf("Enter the symptom %d : ",i+1);
        scanf("\n");
        scanf("%s",s1[i].symptom); i++; }

    char c;
    int lc = 0;
    while((c=getc(f))!=EOF){
        if(c=='\n'){
                lc++;
        }
    }
    fseek(f,0,SEEK_SET);
    while(lc>0){
            fscanf(f,"%[^;]s",disname);
            fseek(f,1,SEEK_CUR);
            fscanf(f,"%[^;]s",symptoms);
            fseek(f,1,SEEK_CUR);
            fscanf(f,"%[^;]s",reasons);
            fseek(f,1,SEEK_CUR);
            fscanf(f,"%[^;]s",medicines);
            fseek(f,1,SEEK_CUR);
            fscanf(f,"%[^;]s",hospital);
            fseek(f,2,SEEK_CUR);

            int c=0;
            int g=0;
            while(g<3){

                char *a=strstr(symptoms,s1[g].symptom);

            if((a)!=0){
                    c++;
                }
                g++;
            }

            if(c>=2){
            	printf("\nThe disease you're sufffering may be %s\n",disname);
                printf("\n\nThe hospitals for your symptoms are: %s\n\n",hospital);
            }
            lc--;
    }
printf("press any key to goto home_screen");
getch();
printf("\n\n");
home();
}


void find_medicine()
{
   FILE *f;
    char disname[50];
    char symptoms[500];
    char reasons[500];
    char medicines[500];
    char hospital[500];
    f=fopen("disease1.txt","r");
    int i=0;
    while(i<3){
        printf("Enter the symptom %d : ",i+1);
        scanf("\n");
        scanf("%s",s1[i].symptom); i++; }

    char c;
    int lc = 0;
    while((c=getc(f))!=EOF){
        if(c=='\n'){
                lc++;
        }
    }
    fseek(f,0,SEEK_SET);
    while(lc>0){
            fscanf(f,"%[^;]s",disname);
            fseek(f,1,SEEK_CUR);
            fscanf(f,"%[^;]s",symptoms);
            fseek(f,1,SEEK_CUR);
            fscanf(f,"%[^;]s",reasons);
            fseek(f,1,SEEK_CUR);
            fscanf(f,"%[^;]s",medicines);
            fseek(f,1,SEEK_CUR);
            fscanf(f,"%[^;]s",hospital);
            fseek(f,2,SEEK_CUR);

            int c=0;
            int g=0;
            while(g<3){

                char *a=strstr(symptoms,s1[g].symptom);

            if((a)!=0){
                    c++;
                }
                g++;
            }

            if(c>=2){
            	printf("\nThe disease you're suffering from may be %s\n",disname);
                printf("\n\nThe medicines for your symptoms are: %s\n\n",medicines);
            }
            lc--;
    }
printf("press any key to goto home_screen");
getch();
printf("\n\n\n");
home();
}
