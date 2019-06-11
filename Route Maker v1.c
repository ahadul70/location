#include<stdio.h>
#include<string.h>
int help();
int volunteer_input();
int edit_route();
int get_routes(int start,int end);
int user_input();
int route_maker(int start,int end);
float time_check1(float time1,float time2);
float time_check2(float time1,float time2,float time3);
float time_check3(float time1,float time2,float time3,float time4);

struct route_description
{
    char route_name[20];
    float route_time;
    char route_traffic;
    char route_other_variable[20];

};

int main()
{int loop_control;
 printf("  ROUTE MAKER  \n\n\n");
  while(loop_control!=0)
 {
     printf("---MAIN MENU---\n\n");
     printf("1.Help\n2.Volunteer Input\n3.User Input\n0.Exit\n\nPlease select (1/2/3/0) to continue: ");
     scanf("%d",&loop_control);
     if(loop_control==1)
     {
        help();
     }
     else if(loop_control==2)
     {
        volunteer_input();
     }
     else if(loop_control==3)
     {
        user_input();
     }
     else
     {
         printf("\n\n\nInvalid Input\n\n\n");
     }
 }
 return 0;
}

int help()
{
    int interface_control;
    printf("\n\n\nThis program is designed to show you possible routes to your destination.\nIf you are a volunteer and have been through the route you can edit the information.\n\n\n");
    return 0;
}
int volunteer_input()
{
    int interface_control;
    while(interface_control!=0)
    {

        printf("\n\n\n");
        printf("---VOLUNTEER INPUT---\n\n");
        printf("1.Edit Route Information\n2.Return\n\nPlease select (1/2) to continue: ");
        scanf("%d",&interface_control);

        if(interface_control==1)
        {
            edit_route();
            printf("\n");
        }
        else if(interface_control==2)
        {
            printf("\n\n\n\n");
            return 0;
        }
        else
        {
            printf("\n\n\n    Invalid Input    \n\n\n");
        }
    }
}

int edit_route()
{
    int loop_control,loop_control_2,i=1,number_check_start,number_check_end;
    char locations[100];
    char location_start[20],location_end[20];
    FILE *fptr1;
    fptr1=fopen("location_list.txt","r");
    while(loop_control!=0)
    {
        fptr1=fopen("location_list.txt","r");
        if(fptr1!=NULL)
        {
            printf("\n\n\n---ROUTE INFORMATION---\n\n\n");
            while( fscanf(fptr1,"%s",locations)!= EOF)
            {
                printf("%s\n",locations);
                i++;
            }

        }
        fclose(fptr1);
        printf("\n\nPlease enter designated number of a Location from the options above\nEnter Starting Location: ");
        scanf("%d",&number_check_start);
        if(number_check_start>=1&&number_check_start<=10)
        {
            printf("\nEnter Destination Location:");
            scanf("%d",&number_check_end);
        }

        else
        {
            printf("\n\n\nInvalid Input\n\n\n");
            loop_control=0;
            continue;
        }
        if(number_check_start==number_check_end)
        {
            printf("\n\nStarting Location and Destination are same!!\n\n");
            continue;
        }
        if((number_check_end<=10&&number_check_end>=1)&&(number_check_start<=10&&number_check_start>=1))
        {
            get_routes(number_check_start,number_check_end);
            printf("\n\n\n\n");
            loop_control=0;
        }
        else
        {
            printf("\n\n\nInvalid Input\n\n\n");
            continue;
        }


    }
    return 0;
}

int get_routes(int start,int end)
{
    struct route_description info;struct route_description info2;struct route_description info3;struct route_description info4;
    printf("\n\n\n---POSSIBLE ROUTES---\n\n\n");
    if(start==1&&(end>=2&&end<=10))
       {
           FILE *fptr1;
           fptr1=fopen("possible_routes\\nikunja_to_all.txt","w");
           if(fptr1!=NULL)
            {
                printf("1.Dhaka-Mymensingh-Highway-N3\n\n");
                printf("Enter Time Taken in hours:");
                scanf("%f",&info.route_time);
                fprintf(fptr1,"%.2f",info.route_time);
                fclose(fptr1);
            }
        }
    else if(start==2&&(end!=2&&(end>=1&&end<=10)))
    {
        FILE *fptr2;
        fptr2=fopen("possible_routes\\bashundhara_to_all.txt","w");
        if(fptr2!=NULL)
            {
                printf("1.Dhaka-Mymensingh-Highway-N3\n\nEnter Time Taken in hours:");
                scanf("%f",&info.route_time);
                fprintf(fptr2,"%.2f\n",info.route_time);
                fflush(stdin);
                printf("\n\n2.Pragati-Avenue\n\nEnter Time Taken in hours:");
                scanf("%f",&info2.route_time);
                fprintf(fptr2,"%.2f\n",info2.route_time);
                fflush(stdin);
                fclose(fptr2);
            }
    }
    else if(start==3&&(end!=3&&(end>=1&&end<=10)))
    {
           FILE *fptr3;
        fptr3=fopen("possible_routes\\banani_to_all.txt","w");
        if(fptr3!=NULL)
            {
                printf("1.Dhaka-Mymensingh-Highway-N3\n\nEnter Time Taken in hours:");
                scanf("%f",&info.route_time);
                fprintf(fptr3,"%.2f\n",info.route_time);
                fflush(stdin);
                printf("\n\n2.Kamal-Attaruk-Avenue\n\nEnter Time Taken in hours:");
                scanf("%f",&info2.route_time);
                fprintf(fptr3,"%.2f\n",info2.route_time);
                fflush(stdin);
                fclose(fptr3);
            }
    }
    else if(start==4&&(end!=4&&(end>=1&&end<=10)))
    {
              FILE *fptr4;
        fptr4=fopen("possible_routes\\gulshan1_to_all.txt","w");
        if(fptr4!=NULL)
            {
                printf("1.Gulshan-Avenue\n\nEnter Time Taken in hours:");
                scanf("%f",&info.route_time);
                fprintf(fptr4,"%.2f\n",info.route_time);
                fflush(stdin);
                printf("\n\n2.Kamal-Attaruk-Avenue\n\nEnter Time Taken in hours:");
                scanf("%f",&info2.route_time);
                fprintf(fptr4,"%.2f\n",info2.route_time);
                fflush(stdin);
                printf("\n\n3.Pragati-Avenue\n\nEnter Time Taken in hours:");
                scanf("%f",&info3.route_time);
                fprintf(fptr4,"%.2f\n",info3.route_time);
                fflush(stdin);
                fclose(fptr4);
            }
    }
    else if(start==5&&(end!=5&&(end>=1&&end<=10)))
    {
                 FILE *fptr5;
        fptr5=fopen("possible_routes\\gulshan2_to_all.txt","w");
        if(fptr5!=NULL)
            {
                printf("1.Gulshan-Avenue\n\nEnter Time Taken in hours:");
                scanf("%f",&info.route_time);
                fprintf(fptr5,"%.2f\n",info.route_time);
                fflush(stdin);
                printf("\n\n2.Link-Road\n\nEnter Time Taken in hours:");
                scanf("%f",&info2.route_time);
                fprintf(fptr5,"%.2f\n",info2.route_time);
                fflush(stdin);
                printf("\n\n3.Bir-Uttam-AK-Khandakar-Road\n\nEnter Time Taken in hours:");
                scanf("%f",&info3.route_time);
                fprintf(fptr5,"%.2f\n",info3.route_time);
                fflush(stdin);
                printf("\n\n4.Bir-Uttam-Mir-Shawkat-Sarak\n\nEnter Time Taken in hours:");
                scanf("%f",&info4.route_time);
                fprintf(fptr5,"%.2f\n",info4.route_time);
                fflush(stdin);
                fclose(fptr5);
            }
    }
    else if(start==6&&(end!=6&&(end>=1&&end<=10)))
    {
         FILE *fptr6;
        fptr6=fopen("possible_routes\\mohakhali_to_all.txt","w");
        if(fptr6!=NULL)
            {
                printf("1.Dhaka-Mymensingh-Highway-N3\n\nEnter Time Taken in hours:");
                scanf("%f",&info.route_time);
                fprintf(fptr6,"%.2f\n",info.route_time);
                fflush(stdin);
                printf("\n\n2.Bir-Uttam-AK-Khandakar-Road\n\nEnter Time Taken in hours:");
                scanf("%f",&info2.route_time);
                fprintf(fptr6,"%.2f\n",info2.route_time);
                fflush(stdin);
                fclose(fptr6);
            }
    }
    else if(start==7&&(end!=7&&(end>=1&&end<=10)))
    {
                  FILE *fptr7;
        fptr7=fopen("possible_routes\\niketan_to_all.txt","w");
        if(fptr7!=NULL)
            {
                printf("1.Bir-Uttam-Mir-Shawkat-Sarak\n\nEnter Time Taken in hours:");
                fflush(stdin);
                scanf("%f",&info.route_time);
                fprintf(fptr7,"%.2f\n",info.route_time);
                fflush(stdin);
                fclose(fptr7);
            }
    }
    else if(start==8&&(end!=8&&(end>=1&&end<=10)))
    {
                    FILE *fptr8;
        fptr8=fopen("possible_routes\\badda_to_all.txt","w");
        if(fptr8!=NULL)
            {
                printf("1.Bir-Uttam-Rafiqul-Islam-Avenue\n\nEnter Time Taken in hours:");
                scanf("%f",&info.route_time);
                fprintf(fptr8,"%.2f\n",info.route_time);
                fflush(stdin);
                printf("\n\n2.Link-Road\n\nEnter Time Taken in hours:");
                scanf("%f",&info2.route_time);
                fprintf(fptr8,"%.2f\n",info2.route_time);
                fflush(stdin);
                printf("\n\n3.Pragati-Avenue\n\nEnter Time Taken in hours:");
                scanf("%f",&info3.route_time);
                fprintf(fptr8,"%.2f\n",info3.route_time);
                fflush(stdin);
                fclose(fptr8);
            }
    }
    else if(start==9&&(end!=9&&(end>=1&&end<=10)))
    {
                       FILE *fptr9;
        fptr9=fopen("possible_routes\\rampura_to_all.txt","w");
        if(fptr9!=NULL)
            {
                printf("1.Bir-Uttam-Rafiqul-Islam-Avenue\n\nEnter Time Taken in hours:");
                scanf("%f",&info.route_time);
                fprintf(fptr9,"%.2f\n",info.route_time);
                fflush(stdin);
                printf("\n\n2.Hatirjheel-to-Rampura-Bridge-Road\n\nEnter Time Taken in hours:");
                scanf("%f",&info2.route_time);
                fprintf(fptr9,"%.2f\n",info2.route_time);
                fflush(stdin);
                fclose(fptr9);
            }
    }
    else if(start==10&&(end!=10&&(end>=1&&end<=10)))
    {
                              FILE *fptr10;
        fptr10=fopen("possible_routes\\hatirjheel_to_all.txt","w");
        if(fptr10!=NULL)
            {
                printf("1.Bir-Uttam-Mir-Shawkat-Sarak\n\nEnter Time Taken in hours:");
                scanf("%f",&info.route_time);
                fprintf(fptr10,"%.2f\n",info.route_time);
                fflush(stdin);
                printf("\n\n2.Hatirjheel-to-Rampura-Bridge-Road\n\nEnter Time Taken in hours:");
                scanf("%f",&info2.route_time);
                fprintf(fptr10,"%.2f\n",info2.route_time);
                fflush(stdin);
                fclose(fptr10);
            }
    }

}

int user_input()
{
    char locations[100];
    int start,end,lp_control;
    FILE *fptr_1;
    while(lp_control!=0)
    {
        fptr_1=fopen("location_list.txt","r");
        if(fptr_1!=NULL)
        {
            printf("\n\n\n---LOCATION LIST---\n\n\n");
            while( fscanf(fptr_1,"%s",locations)!= EOF)
            {
                printf("%s\n",locations);
            }

        }
        fclose(fptr_1);
        printf("\n\nPlease enter designated number of a Location from the options above\nEnter Starting Location: ");
        scanf("%d",&start);
        if(start>=1&&start<=10)
        {
            printf("\nEnter Destination Location:");
            scanf("%d",&end);
        }

        else
        {
            printf("\n\n\nInvalid Input\n\n\n");
            lp_control=0;
            continue;
        }
        if(start==end)
        {
            printf("\n\nStarting Location and Destination are same!!\n\n");
            continue;
        }
        if((end<=10&&end>=1)&&(start<=10&&start>=1))
        {
            route_maker(start,end);
            lp_control=0;
        }
        else
        {
            printf("\n\n\nInvalid Input\n\n\n");
            continue;
        }

    }
    return 0;
}

int route_maker(int start,int end)
{
    struct route_description info;struct route_description info2;struct route_description info3;struct route_description info4;
    if(start==1&&(end>=2&&end<=10))
       {
           printf("\n\n\n---POSSIBLE ROUTES---\n\n\n");
           FILE *fptr1;
           float time1;
           fptr1=fopen("possible_routes\\nikunja_to_all.txt","r");
           if(fptr1!=NULL)
            {
                printf("1.Dhaka-Mymensingh-Highway-N3\n\n");
                fscanf(fptr1,"%f",&time1);
                printf("Time to Destination:%.2f hours\n\n",time1);
                printf("Since there is only initial route to your destination Dhaka-Mymensingh-Highway-N3 is recommended!!\n\n\n\n");
                fclose(fptr1);
            }
            else
            {
                printf("\n\nThere is no input for Routes!!\n\nPlease give Volunteer Input!!\n\n\n\n");
            }
        }
    else if(start==2&&(end!=2&&(end>=1&&end<=10)))
    {
        printf("\n\n\n---POSSIBLE ROUTES---\n\n\n");
        FILE *fptr2;
        float time1,time2;int result;
        fptr2=fopen("possible_routes\\bashundhara_to_all.txt","r");
        if(fptr2!=NULL)
            {
                fscanf(fptr2,"%f %f",&time1,&time2);
                fflush(stdin);
                printf("1.Dhaka-Mymensingh-Highway-N3\n\nTime to Destination:%.2f hours\n\n",time1);
                printf("\n\n2.Pragati-Avenue\n\nTime to Destination:%.2f hours\n\n");
                int result=time_check1(time1,time2);
                if(result==1)
                {
                    printf("Recommended Route is Dhaka-Mymensingh-Highway-N3\n\n\n\n");
                }
                else if(result==2)
                {
                    printf("Recommended Route is Pragati-Avenue\n\n\n\n");
                }
                fclose(fptr2);
            }
        else
            {
                printf("\n\nThere is no input for Routes!!\n\nPlease give Volunteer Input!!\n\n\n\n");
            }
    }
    else if(start==3&&(end!=3&&(end>=1&&end<=10)))
    {
        printf("\n\n\n---POSSIBLE ROUTES---\n\n\n");
        FILE *fptr3;
        float time1,time2;int result;
        fptr3=fopen("possible_routes\\banani_to_all.txt","r");
        if(fptr3!=NULL)
            {
                printf("1.Dhaka-Mymensingh-Highway-N3\n\nTime to Destination:%f",time1);
                fscanf(fptr3,"%f %f",&time1,&time2);
                fflush(stdin);
                printf("\n\n2.Kamal-Attaruk-Avenue\n\nTime to Destination:%f",time2);
                fflush(stdin);
                int result=time_check1(time1,time2);
                if(result==1)
                {
                    printf("\n\nRecommended Route is Dhaka-Mymensingh-Highway-N3!!\n\n\n\n");
                }
                else if(result==2)
                {
                    printf("\n\nRecommended Route is Kamal-Attaruk-Avenue!!\n\n\n\n");
                }
                fclose(fptr3);
            }
        else
            {
                printf("\n\nThere is no input for Routes!!\n\nPlease give Volunteer Input!!\n\n\n\n");
            }
    }
    else if(start==4&&(end!=4&&(end>=1&&end<=10)))
    {
        printf("\n\n\n---POSSIBLE ROUTES---\n\n\n");
        FILE *fptr4;
        float time1,time2,time3;int result;
        fptr4=fopen("possible_routes\\gulshan1_to_all.txt","r");
        if(fptr4!=NULL)
            {
                fscanf(fptr4,"%f %f %f",&time1,&time2,&time3);
                fflush(stdin);
                printf("1.Gulshan-Avenue\n\nTime to Destination:%f",time1);
                printf("\n\n2.Kamal-Attaruk-Avenue\n\nTime to Destination:%f",time2);
                printf("\n\n3.Pragati-Avenue\n\nTime to Destination:%f",time3);
                int result=time_check2(time1,time2,time3);
                if(result=1)
                {
                     printf("\n\nRecommended Route is Gulshan-Avenue!!\n\n\n\n");
                }
                else if(result=2)
                {
                    printf("\n\nRecommended Route is Kamal-Attaruk-Avenue!!\n\n\n\n");
                }
                else if(result=3)
                {
                    printf("\n\nRecommended Route is Pragati-Avenue!!\n\n\n\n");
                }
                fclose(fptr4);
            }
        else
            {
                printf("\n\nThere is no input for Routes!!\n\nPlease give Volunteer Input!!\n\n\n\n");
            }
    }
    else if(start==5&&(end!=5&&(end>=1&&end<=10)))
    {
        printf("\n\n\n---POSSIBLE ROUTES---\n\n\n");
        FILE *fptr5;
        float time1,time2,time3,time4;int result;

        fptr5=fopen("possible_routes\\gulshan2_to_all.txt","r");
        if(fptr5!=NULL)
            {
                fscanf(fptr5,"%f %f %f %f",&time1,&time2,&time3,&time4);
                fflush(stdin);
                printf("1.Gulshan-Avenue\n\nTime to Destination:%f",time1);
                printf("\n\n2.Link-Road\n\nTime to Destination:%f",time2);
                printf("\n\n3.Bir-Uttam-AK-Khandakar-Road\n\nTime to Destination:%f",time3);
                printf("\n\n4.Bir-Uttam-Mir-Shawkat-Sarak\n\nTime to Destination:%f",time4);
                int result=time_check3(time1,time2,time3,time4);
                if(result=1)
                {
                     printf("\n\nRecommended Route is Gulshan-Avenue!!\n\n\n\n");
                }
                else if(result=2)
                {
                     printf("\n\nRecommended Route is Link-Road!!\n\n\n\n");
                }
                else if(result=3)
                {
                     printf("\n\nRecommended Route is Bir-Uttam-AK-Khandakar-Road!!\n\n\n\n");
                }
                else if(result=4)
                {
                    printf("\n\nRecommended Route is Bir-Uttam-Mir-Shawkat-Sarak!!\n\n\n\n");
                }
                fclose(fptr5);
            }
        else
            {
                printf("\n\nThere is no input for Routes!!\n\nPlease give Volunteer Input!!\n\n\n\n");
            }
    }
    else if(start==6&&(end!=6&&(end>=1&&end<=10)))
    {
        printf("\n\n\n---POSSIBLE ROUTES---\n\n\n");
        FILE *fptr6;
        float time1,time2;int result;
        fptr6=fopen("possible_routes\\mohakhali_to_all.txt","r");
        if(fptr6!=NULL)
            {
                fscanf(fptr6,"%f %f",&time1,&time2);
                fflush(stdin);
                printf("1.Dhaka-Mymensingh-Highway-N3\n\nTime to Destionation:%f",time1);
                printf("\n\n2.Bir-Uttam-AK-Khandakar-Road\n\nTime to Destionation:%f",time1);
                int result=time_check1(time1,time2);
                  if(result==1)
                {
                    printf("\n\nRecommended Route is Dhaka-Mymensingh-Highway-N3!!\n\n\n\n");
                }
                else if(result==2)
                {
                    printf("\n\nRecommended Route is Bir-Uttam-AK-Khandakar-Road!!\n\n\n\n");
                }
                fclose(fptr6);
            }
        else
            {
                printf("\n\nThere is no input for Routes!!\n\nPlease give Volunteer Input!!\n\n\n\n");
            }
    }
    else if(start==7&&(end!=7&&(end>=1&&end<=10)))
    {
        printf("\n\n\n---POSSIBLE ROUTES---\n\n\n");
        FILE *fptr7;
        float time1;
        fptr7=fopen("possible_routes\\niketan_to_all.txt","r");
        if(fptr7!=NULL)
            {
                fscanf(fptr7,"%f",&time1);
                fflush(stdin);
                printf("1.Bir-Uttam-Mir-Shawkat-Sarak\n\nTime to Destination:%f",time1);
                printf("\n\nSince there is only initial route to your destination Dhaka-Mymensingh-Highway-N3 is recommended!!\n\n\n\n");
                fclose(fptr7);
            }
            else
            {
                printf("\n\nThere is no input for Routes!!\n\nPlease give Volunteer Input!!\n\n\n\n");
            }
    }
    else if(start==8&&(end!=8&&(end>=1&&end<=10)))
    {
        printf("\n\n\n---POSSIBLE ROUTES---\n\n\n");
        FILE *fptr8;
        float time1,time2,time3;int result;
        fptr8=fopen("possible_routes\\badda_to_all.txt","r");
        if(fptr8!=NULL)
            {
                fscanf(fptr8,"%f %f %f",&time1,&time2,&time3);
                fflush(stdin);
                printf("1.Bir-Uttam-Rafiqul-Islam-Avenue\n\nTime to Destination:%f",time1);
                printf("\n\n2.Link-Road\n\nTime to Destination:%f",time2);
                printf("\n\n3.Pragati-Avenue\n\nTime to Destination:%f",time3);
                int result=time_check2(time1,time2,time3);
                if(result=1)
                {
                     printf("\n\nRecommended Route is Bir-Uttam-Rafiqul-Islam-Avenue!!\n\n\n\n");
                }
                else if(result=2)
                {
                     printf("\n\nRecommended Route is Link-Road!!\n\n\n\n");
                }
                else if(result=3)
                {
                     printf("\n\nRecommended Route is Pragati-Avenue!!\n\n\n\n");
                }
                fclose(fptr8);
            }
        else
            {
                printf("\n\nThere is no input for Routes!!\n\nPlease give Volunteer Input!!\n\n\n\n");
            }
    }
    else if(start==9&&(end!=9&&(end>=1&&end<=10)))
    {
        printf("\n\n\n---POSSIBLE ROUTES---\n\n\n");
        FILE *fptr9;
        float time1,time2;int result;
        fptr9=fopen("possible_routes\\rampura_to_all.txt","r");
        if(fptr9!=NULL)
            {
                fscanf(fptr9,"%f %f",&time1,&time2);
                fflush(stdin);
                printf("1.Bir-Uttam-Rafiqul-Islam-Avenue\n\nTime to Destination:%f",time1);
                printf("\n\n2.Hatirjheel-to-Rampura-Bridge-Road\n\nTime to Destination:%f",time2);
                int result=time_check1(time1,time2);
                if(result==1)
                    {
                        printf("\n\nRecommended Route is Bir-Uttam-Rafiqul-Islam-Avenue!!\n\n\n\n");
                    }
                else if(result==2)
                    {
                        printf("\n\nRecommended Route is Hatirjheel-to-Rampura-Bridge-Road!!\n\n\n\n");
                    }
                fclose(fptr9);
            }
        else
            {
                printf("\n\nThere is no input for Routes!!\n\nPlease give Volunteer Input!!\n\n\n\n");
            }
    }
    else if(start==10&&(end!=10&&(end>=1&&end<=10)))
    {
        printf("\n\n\n---POSSIBLE ROUTES---\n\n\n");
        FILE *fptr10;
        float time1,time2;int result;
        fptr10=fopen("possible_routes\\hatirjheel_to_all.txt","r");
        if(fptr10!=NULL)
            {
                fscanf(fptr10,"%f %f",&time1,&time2);
                fflush(stdin);
                printf("1.Bir-Uttam-Mir-Shawkat-Sarak\n\nTime to Destination:%f",time1);
                printf("\n\n2.Hatirjheel-to-Rampura-Bridge-Road\n\nTime to Destination:%f",time2);
                int result=time_check1(time1,time2);
                if(result==1)
                    {
                        printf("\n\nRecommended Route is Bir-Uttam-Mir-Shawkat-Sarak!!\n\n\n\n");
                    }
                else if(result==2)
                    {
                        printf("\n\nRecommended Route is Hatirjheel-to-Rampura-Bridge-Road!!\n\n\n\n");
                    }
                fclose(fptr10);
            }
        else
            {
                printf("\n\nThere is no input for Routes!!\n\nPlease give Volunteer Input!!\n\n\n\n");
            }
    }

}

float time_check1(float time1,float time2)
{
    if(time1<time2)
    {
        return 1;
    }
    else
    {
        return 2;
    }
}

float time_check2(float time1,float time2,float time3)
{
    if((time1<time2)&&(time1<time3))
    {
        return 1;
    }
    else if((time2<time1)&&(time2<time3))
    {
        return 2;
    }
    else if((time3<time1)&&(time3<time2))
    {
        return 3;
    }

}

float time_check3(float time1,float time2,float time3,float time4)
{
     if((time1<time2)&&(time1<time3)&&(time1<time4))
    {
        return 1;
    }
    else if((time2<time1)&&(time2<time3)&&(time2<time4))
    {
        return 2;
    }
    else if((time3<time1)&&(time3<time2)&&(time3<time4))
    {
        return 3;
    }
    else if((time4<time1)&&(time4<time2)&&(time4<time3))
    {
        return 4;
    }
}

