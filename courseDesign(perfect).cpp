/*****************************************************************************
  Copyright (C) , 1988-1999 , 17�������.
  Filename: courseDesign.cpp
  Author:���    Version:0.3    Date: 2018-6-20
  Description:ʵ��ȫ�����ܵĴ�ģ�� ֻ��ְ�������ļ�gz.dat����ϵ ��������ø�������//ģ������
  Function List: 
      1. read    ���ļ��ж�ȡȫ��ְ������
      2. write   ������д���ļ���
      3. list    ������ְ���������г���
      4. find    ��ѯ��Ӧ���ŵ�ְ������
      5. grsds   �����������˰,ʵ�����룬��Ӧ������
      6. modify  �޸Ķ�Ӧ����ְ��������
      7. del     ɾ����Ӧ����ְ��������
      8. add     ����ְ��������
  History: // ��ʷ�޸ļ�¼
      <author>    <time>     <version >   <desc>
        me        18/6/16    0.1          build this cpp
        me        18/6/16    0.3          modify this cpp
*****************************************************************************/
#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;
struct Worker_Salary           /*ְ��������������*/
{
    char ID[10];
    char name[10];
    float p_salary;
    float p_salary1;
    float p_salary2;
    float p_salary3;
    float s_salary;
    float tax;
    float real_salary;
    Worker_Salary *pre;
    Worker_Salary *next;
}*head,*p;
int data_num=0;
/*************************************************
Function:    read                                         // ��������
Description: ��ȡְ�������ļ� gz.dat���Թ�������          // �������ܡ����ܵȵ�����
Calls:       ��                                           // �����������õĺ����嵥
Called By:   ������ main()                                // ���ñ������ĺ����嵥
Input: �����������ݵ�ֵ                                   // �������˵��������ÿ����������
                                                          // �á�ȡֵ˵�����������ϵ��
Output:                                                   // �����������˵����
Return:ְ�����ݵĸ���                                     // ��������ֵ��˵��
*************************************************/
int read(Worker_Salary ws[])   
{
    FILE *fp;
    if(( fp = fopen("gz.dat","rb"))==NULL)
    {
        printf("\t�ļ������ڻ������\n");
        getchar();
        exit(-1);
    }

    head=&ws[0];
    int num = 0 ;

    while(fread(&ws[num],sizeof(struct Worker_Salary)-8,1,fp))
    {   
        if(num==0)
        {
            ws[0].pre=NULL;
            ws[0].next=&ws[1];
        }
        else
        {
            ws[num].pre=&ws[num-1];
            ws[num].next=&ws[num+1];
        }
        num = num + 1;
    };
    data_num=num;
    ws[num].pre=&ws[num-1];
    ws[num].next=NULL;

    for( int i = 0 ; i < num ; i++ )   //�Զ�ȡ��ʼ���ݹ��Ž�������
    {
        for( int j = i + 1; j < num ; j++ )
        {
            if(strcmp(ws[i].ID,ws[j].ID)>0)
            {
                Worker_Salary temp;
                temp=ws[i];
                strcpy(ws[i].ID,ws[j].ID);
                strcpy(ws[i].name,ws[j].name);
                ws[i].p_salary=ws[j].p_salary;
                ws[i].p_salary1=ws[j].p_salary1;
                ws[i].p_salary2=ws[j].p_salary2;
                ws[i].p_salary3=ws[j].p_salary3;
                ws[i].s_salary=ws[j].s_salary;
                ws[i].tax=ws[j].tax;
                ws[i].real_salary=ws[j].real_salary;
                
                strcpy(ws[j].ID,temp.ID);
                strcpy(ws[j].name,temp.name);
                ws[j].p_salary=temp.p_salary;
                ws[j].p_salary1=temp.p_salary1;
                ws[j].p_salary2=temp.p_salary2;
                ws[j].p_salary3=temp.p_salary3;
                ws[j].s_salary=temp.s_salary;
                ws[j].tax=temp.tax;
                ws[j].real_salary=temp.real_salary;
            }
        }
    }
    fclose(fp);
    return num;
}
/*************************************************
Function:    write                             // ��������
Description: ����ְ�����ݵ��ļ�gz.dat��        // �������ܡ����ܵȵ�����
Calls:       ��                                // �����������õĺ����嵥
Called By:   ������ main()                     // ���ñ������ĺ����嵥
Input:ws��ֵ����д���ļ�����                   // �������˵��������ÿ����������
                                               // �á�ȡֵ˵�����������ϵ��
Output:                                        // �����������˵����
Return:��                                      // ��������ֵ��˵��
*************************************************/
void write(Worker_Salary ws[]) 
{ 
    FILE *fp;
    if((fp=fopen("gz.dat","wb"))==NULL)
    {
        printf("\t�ļ������ڻ������\n");
        getchar();
        exit(-1);
    }

    p=head;
    while( (*p).next != NULL )
    {
        fwrite(p,sizeof(struct Worker_Salary)-8,1,fp);
        p=(*p).next;
    }
    fclose(fp);
    printf("\t����ɹ�!!!!!\n");
}
/*************************************************
Function:    list                              // ��������
Description: ��ʾְ�����ݵ���ʾ��              // �������ܡ����ܵȵ�����
Calls:       ��                                // �����������õĺ����嵥
Called By:   ������ main()                     // ���ñ������ĺ����嵥
Input:ws��ֵ�������ո�������                   // �������˵��������ÿ����������
                                               // �á�ȡֵ˵�����������ϵ��
Output:                                        // �����������˵����
Return:��                                      // ��������ֵ��˵��
*************************************************/
void list(Worker_Salary ws[])
{   
    p=head;
    while((*p).next!=NULL)
    {   
        printf("\t���ţ�%s  |  ������%s | ��λ���ʣ�%.2f | ",(*p).ID,(*p).name,(*p).p_salary);
        printf("н�����ʣ�%.2f | \n\tְ�������%.2f | ��Ч���ʣ�%.2f | Ӧ�����ʣ�%.2f | \n",(*p).p_salary1,(*p).p_salary2,(*p).p_salary3,(*p).s_salary);
        printf("\t��������˰��%.2f | ʵ�����ʣ�%.2f\n",(*p).tax,(*p).real_salary);
        printf("___________________________________________________________________________________\n\n");
        p=p->next;
    }
}
/*************************************************
Function:    list                              // ��������
Description: ��ʾ��Ӧ����ְ�����ݵ���ʾ��      // �������ܡ����ܵȵ�����
Calls:       ��                                // �����������õĺ����嵥
Called By:   ������ main()                     // ���ñ������ĺ����嵥
Input:ws��ֵ�������ո������ݣ�id����ҵĹ���   // �������˵��������ÿ����������
                                               // �á�ȡֵ˵�����������ϵ��
Output:                                        // �����������˵����
Return:��                                      // ��������ֵ��˵��
*************************************************/
void find(Worker_Salary ws[],char id[]) 
{   
    p=head;
    while((*p).next!=NULL)
    {
        if(strcmp((*p).ID,id)==0)
        {
            printf("\n\t���ţ�%s  |  ������%s | ��λ���ʣ�%.2f | ",(*p).ID,(*p).name,(*p).p_salary);
            printf("н�����ʣ�%.2f | \n\tְ�������%.2f | ��Ч���ʣ�%.2f | Ӧ�����ʣ�%.2f | \n",(*p).p_salary1,(*p).p_salary2,(*p).p_salary3,(*p).s_salary);
            printf("\t��������˰��%.2f | ʵ�����ʣ�%.2f\n",(*p).tax,(*p).real_salary);
            printf("___________________________________________________________________________________\n\n");
            return;
        }
        p=p->next;
    }
    printf("\t�����ڴ˹��ŵ�ְ��,��ȷ����������Ĺ���!!!\n");
}
/*************************************************
Function:    grsds                             // ��������
Description: �����������˰                    // �������ܡ����ܵȵ�����
Calls:       ��                                // �����������õĺ����嵥
Called By:   modify  add                       // ���ñ������ĺ����嵥
Input:ws��ֵ�������մ���������                 // �������˵��������ÿ����������
                                               // �á�ȡֵ˵�����������ϵ��
Output:                                        // �����������˵����
Return:��                                      // ��������ֵ��˵��
*************************************************/
void grsds(Worker_Salary *ws)
{   
    ws->s_salary=ws->p_salary+ws->p_salary1+ws->p_salary2+ws->p_salary3;
    if(ws->s_salary<500)
    {
        ws->tax=ws->s_salary*0.05;
    }
	
    else if(ws->s_salary<2000)
    {
        ws->tax=500*0.05+(ws->s_salary-500)*0.1;
    }

    else if(ws->s_salary<5000)
    {
        ws->tax=500*0.05+1500*0.1+(ws->s_salary-2000)*0.15;
    }

    else if(ws->s_salary<20000)
    {
        ws->tax=500*0.05+1500*0.1+3000*0.15+(ws->s_salary-5000)*0.20;
    }

    else if(ws->s_salary<40000)
    {	
        ws->tax=500*0.05+1500*0.1+3000*0.15+15000*0.2+(ws->s_salary-20000)*0.25;
    }

    else if(ws->s_salary<60000)
    {
        ws->tax=500*0.05+1500*0.1+3000*0.15+15000*0.2+20000*0.25+(ws->s_salary-40000)*0.3;
    }

    else if(ws->s_salary<80000)
    {	
        ws->tax=500*0.05+1500*0.1+3000*0.15+15000*0.2+20000*0.25+20000*0.30+(ws->s_salary-60000)*0.35;
    }

    else if(ws->s_salary<100000)
    {
        ws->tax=500*0.05+1500*0.1+3000*0.15+15000*0.2+20000*0.25+20000*0.30+20000*0.35+(ws->s_salary-60000)*0.40;
    }

    else
    {
        ws->tax=500*0.05+1500*0.1+3000*0.15+15000*0.2+20000*0.25+20000*0.30+20000*0.35+20000*0.4+(ws->s_salary-80000)*0.45;
    }
    ws->real_salary=ws->s_salary-ws->tax;	
}
/*************************************************
Function:    modify                            // ��������
Description: �޸Ķ�Ӧ����ְ������              // �������ܡ����ܵȵ�����
Calls:       grsds                             // �����������õĺ����嵥
Called By:   main()                            // ���ñ������ĺ����嵥
Input:ws��ֵ�������ո������ݣ�num���ݸ���      // �������˵��������ÿ����������
      id�����޸ĵĹ���                         // �á�ȡֵ˵�����������ϵ��
Output:                                        // �����������˵����
Return:��                                      // ��������ֵ��˵��
*************************************************/
void modify(Worker_Salary ws[],char id[])
{   
    p=head;
    while((*p).next!=NULL)
    {
        if(strcmp((*p).ID,id)==0)
        {   
            printf("\t�����������ְ���Ļ�����Ϣ��\n");
            printf("\t������ְ�����ţ�");
            scanf("%s",(*p).ID);
            printf("\t������ְ��������");
            scanf("%s",(*p).name);
            printf("\t������ְ����λ���ʣ�");
            scanf("%f",&(*p).p_salary);
            printf("\t������ְ��н�����ʣ�");
            scanf("%f",&(*p).p_salary1);
            printf("\t������ְ��ְ�������");
            scanf("%f",&(*p).p_salary2);
            printf("\t������ְ����Ч���ʣ�");
            scanf("%f",&(*p).p_salary3);
            grsds(p);
            printf("\t�޸ĳɹ�!!!!!!\n");
            return;
        }
        p=p->next;
    }
    printf("\t�����ڴ˹��ŵ�ְ��,��ȷ����������Ĺ���!!!\n");
}
/*************************************************
Function:    del                               // ��������
Description: ɾ����Ӧ����ְ������              // �������ܡ����ܵȵ�����
Calls:                                         // �����������õĺ����嵥
Called By:   main()                            // ���ñ������ĺ����嵥
Input:ws��ֵ�������ո������ݣ�num���ݸ���      // �������˵��������ÿ����������
      id����ɾ���Ĺ���                         // �á�ȡֵ˵�����������ϵ��
Output:                                        // �����������˵����
Return:��                                      // ��������ֵ��˵��
*************************************************/
void del(Worker_Salary ws[],int &num,char id[])
{  
    p=head;
    while((*p).next!=NULL)
    {
        if(strcmp((*p).ID,id)==0)
        {
            break;
        }
        p=p->next;
    }
    if( (*p).next == NULL)
    {
        printf("\t�����ڴ˹��ŵ�ְ��,��ȷ����������Ĺ���!!!\n");  
        return;
    }

    char code;

    printf("\t�Ƿ�ȷ��ɾ������ȷ������1����ȡ�������1��");
    scanf("\n%c",&code);
    if( code == '1' )
    {    
        if( (*p).pre == NULL )
        {
            (*(*p).next).pre=NULL;
            p=(*p).next;
            head=p;
        } 
        else
        {  
            (*(*p).pre).next=p->next;
            (*(*p).next).pre=p->pre;
            p=p->next;
        }
        num=num-1;
        printf("\tɾ���ɹ�!!!!!!\n");
    }
    else
    {
        printf("\t��ȡ��ɾ������!!!!!\n");
    }
}
/*************************************************
Function:    add                               // ��������
Description: ����ְ������                      // �������ܡ����ܵȵ�����
Calls:       grsds                             // �����������õĺ����嵥
Called By:   main()                            // ���ñ������ĺ����嵥
Input:ws��ֵ�������ո������ݣ�num���ݸ���      // �������˵��������ÿ����������
                                               // �á�ȡֵ˵�����������ϵ��
Output:                                        // �����������˵����
Return:��                                      // ��������ֵ��˵��
*************************************************/
void add(Worker_Salary ws[],int &num)
{     
    char gonghao[10];
    printf("\t����������ְ���Ļ�����Ϣ��");
    while(true)
    {
        printf("\t������ְ�����ţ�");
        scanf("%s",gonghao);
        p=head;
        while((*p).next!=NULL)
        {
            if(strcmp((*p).ID,gonghao)==0)
            {
                printf("\t�˹����Ѿ����ڣ�����������\n");
                break;
            }
			p=p->next;
        }
        if( (*p).next==NULL )
        {   
            strcpy(ws[data_num].ID,gonghao);
            printf("\t������ְ��������");
            scanf("%s",ws[data_num].name);
            printf("\t������ְ����λ���ʣ�");
            scanf("%f",&ws[data_num].p_salary);
            printf("\t������ְ��н�����ʣ�");
            scanf("%f",&ws[data_num].p_salary1);
            printf("\t������ְ��ְ�������");
            scanf("%f",&ws[data_num].p_salary2);
            printf("\t������ְ����Ч���ʣ�");
            scanf("%f",&ws[data_num].p_salary3);
            grsds(&ws[data_num]);
            num=num+1;
            data_num+=1;
            (*p).next=&ws[data_num];
            ws[data_num].pre=p;
            ws[data_num].next=NULL;
            printf("\t�����ɹ�������\n");
            break;
        }
        else 
        {
            continue;
        }
    }		 
}
int main(){
    Worker_Salary zggz[100];
    int num = read(zggz);   //���ļ��ж�ȡ���ݣ����������ݵĸ���
    bool key = true;
    int code;
    char gonghao[10];

    while(true)
    {   
        printf("\n\n\t### ��ӭʹ�ù��������ѧ�������Ϣ��ȫѧԺְ�����ʹ���ϵͳ ###\n\n\n");
        printf("\t��ѡ�� (1 - 7) :\n");
        printf("\t======================================================================\n");
        printf("\t|\t1. ��ѯְ�����ʼ�¼                                          |\n");
        printf("\t|\t2. �޸�ְ�����ʼ�¼                                          |\n");
        printf("\t|\t3. ���ְ�����ʼ�¼                                          |\n");
        printf("\t|\t4. ɾ��ְ�����ʼ�¼                                          |\n");
        printf("\t|\t5. �������ݵ��ļ�                                            |\n");
        printf("\t|\t6. ���ְ����¼                                              |\n");
        printf("\t|\t7. �˳�ϵͳ                                                  |\n");
        printf("\t======================================================================\n\n");
        printf("\t���ѡ���ǣ�");
        scanf("%d",&code);   //������������
        switch(code)
        {
            case 1:   //��ѯ	       
                printf("\t������������ѯְ�����ţ�");
                scanf("%s",gonghao);
                find(zggz,gonghao);
                break;

            case 2:  //�޸�
                printf("\t�����������޸ĵ�ְ�����ţ�");
                scanf("%s",gonghao);
                modify(zggz,gonghao);
                key=false;
                break;

            case 3:    //����
                add(zggz,num);
                key=false;
                break;

            case 4:   //ɾ��
                printf("\t����������ɾ����ְ�����ţ�");
                scanf("%s",gonghao);
                del(zggz,num,gonghao);
                key=false;
                break;

            case 5:    //����
                write(zggz);
                key=true;
                break;

            case 6:    //���
                printf("\n");
                list(zggz);
                break;

            case 7:      //�˳�
                if(key)
                {
                    printf("\t�˳�����!!!!\n");
                    return 0;
                }
                else      //û�����޸ĺ�����ݣ����е���ʾ
                {   
                    char save_code;    
                    printf("\t�����޸ģ���û�б����ļ��У�����\n");
                    printf("\t������������1�����б������²��������1\n");
                    scanf("\n%c",&save_code);
                    if( save_code == '1')
                    {
                        printf("�˳�����������\n");                        
                        return 0;
                    }
                    else
                    {
                        break;
                    }
                }
            	
            default:
                printf("\t������Ĵ��벻��ȷ������ ���������룡����\n");
        }
    }
    return 0;
}