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
};
/*************************************************
Function:    read                              // ��������
Description: ��ȡְ�������ļ� gz.dat           // �������ܡ����ܵȵ�����
Calls:       ��                                // �����������õĺ����嵥
Called By:   ������ main()                     // ���ñ������ĺ����嵥
Input: �����������ݵ�ֵ                        // �������˵��������ÿ����������
                                               // �á�ȡֵ˵�����������ϵ��
Output:                                        // �����������˵����
Return:ְ�����ݵĸ���                          // ��������ֵ��˵��
*************************************************/
int read(Worker_Salary ws[])   
{
	FILE *fp;
	if(( fp = fopen("gz.dat","rb"))==NULL){
	    printf("�ļ������ڻ������");
		getchar();
		exit(-1);
	}
	int num = 0 ;
	while(fread(&ws[num],sizeof(struct Worker_Salary),1,fp))
	{
	    num = num + 1;
	};
   fclose(fp);
   return num;
}
/*************************************************
Function:    write                             // ��������
Description: ����ְ�����ݵ��ļ�gz.dat��        // �������ܡ����ܵȵ�����
Calls:       ��                                // �����������õĺ����嵥
Called By:   ������ main()                     // ���ñ������ĺ����嵥
Input:ws��ֵ����д���ļ����ݣ�num���ݸ���      // �������˵��������ÿ����������
                                               // �á�ȡֵ˵�����������ϵ��
Output:                                        // �����������˵����
Return:��                                      // ��������ֵ��˵��
*************************************************/
void write(Worker_Salary ws[],int num) 
{ 
    FILE *fp;
    if((fp=fopen("gz.dat","wb"))==NULL)
	{
	    cout<<"�ļ������ڻ������";
	    getchar();
	    exit(-1);
	}
    fwrite(ws,sizeof(struct Worker_Salary),num,fp);
    fclose(fp);
    cout<<"����ɹ�!!!!!"<<endl;
}
/*************************************************
Function:    list                              // ��������
Description: ��ʾְ�����ݵ���ʾ��              // �������ܡ����ܵȵ�����
Calls:       ��                                // �����������õĺ����嵥
Called By:   ������ main()                     // ���ñ������ĺ����嵥
Input:ws��ֵ�������ո������ݣ�num���ݸ���      // �������˵��������ÿ����������
                                               // �á�ȡֵ˵�����������ϵ��
Output:                                        // �����������˵����
Return:��                                      // ��������ֵ��˵��
*************************************************/
void list(Worker_Salary ws[],int num)
{   int i;
    for(i=0;i<num;i++)
	{
        cout<<"���ţ�"<<ws[i].ID<<"  |  "<<"������"<<ws[i].name<<"  |  "<<"��λ���ʣ�"<<ws[i].p_salary<<"  |  ";
        cout<<"н�����ʣ�"<<ws[i].p_salary1<<"  |  "<<'\n'<<"ְ�������"<<ws[i].p_salary2<<"  |  ";
        cout<<"��Ч���ʣ�"<<ws[i].p_salary3<<"  |  "<<"Ӧ�����ʣ�"<<ws[i].s_salary<<"  |  "<<'\n';
        cout<<"��������˰��"<<ws[i].tax<<"  |  "<<"ʵ�����ʣ�"<<ws[i].real_salary<<"  |"<<endl;
        cout<<"________________________________________________________________________________"<<endl;
	}
}
/*************************************************
Function:    list                              // ��������
Description: ��ʾ��Ӧ����ְ�����ݵ���ʾ��      // �������ܡ����ܵȵ�����
Calls:       ��                                // �����������õĺ����嵥
Called By:   ������ main()                     // ���ñ������ĺ����嵥
Input:ws��ֵ�������ո������ݣ�num���ݸ���      // �������˵��������ÿ����������
      id����ҵĹ���                           // �á�ȡֵ˵�����������ϵ��
Output:                                        // �����������˵����
Return:��                                      // ��������ֵ��˵��
*************************************************/
void find(Worker_Salary ws[],int num,char id[]) 
{   int i;
	for( i = 0 ;i<num;i++)
	{
        if(strcmp(ws[i].ID,id)==0)
		{
		    cout<<"���ţ�"<<ws[i].ID<<"  |  "<<"������"<<ws[i].name<<"  |  "<<"��λ���ʣ�"<<ws[i].p_salary<<"  |  ";
			cout<<"н�����ʣ�"<<ws[i].p_salary1<<"  |  "<<'\n'<<"ְ�������"<<ws[i].p_salary2<<"  |  ";
			cout<<"��Ч���ʣ�"<<ws[i].p_salary3<<"  |  "<<"Ӧ�����ʣ�"<<ws[i].s_salary<<"  |  "<<'\n';
			cout<<"��������˰��"<<ws[i].tax<<"  |  "<<"ʵ�����ʣ�"<<ws[i].real_salary<<"  |"<<endl;
			cout<<"________________________________________________________________________________"<<endl;
			return;
		}
	}
	cout<<"�����ڴ˹��ŵ�ְ��,��ȷ����������Ĺ���!!!"<<endl;
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
void modify(Worker_Salary ws[],int num,char id[])
{   int i;
    for( i=0;i<num;i++)
	{
	    if(strcmp(ws[i].ID,id)==0)
		{
		    cout<<"�����������ְ���Ļ�����Ϣ��";
		    cout<<"������ְ�����ţ�";
		    cin>>ws[i].ID;
		    cout<<"������ְ��������";
		    cin>>ws[i].name;
		    cout<<"������ְ����λ���ʣ�";
		    cin>>ws[i].p_salary;
		    cout<<"������ְ��н�����ʣ�";
		    cin>>ws[i].p_salary1;
		    cout<<"������ְ��ְ�������";
		    cin>>ws[i].p_salary2;
		    cout<<"������ְ����Ч���ʣ�";
		    cin>>ws[i].p_salary3;
		    grsds(&ws[i]);
		    cout<<"�޸ĳɹ�!!!!!!"<<endl;
		    return;
		}
	}
	cout<<"�����ڴ˹��ŵ�ְ��,��ȷ����������Ĺ���!!!"<<endl;
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
    int i;
	char code;
	for( i=0; i < num ; i++)
	{
		if(strcmp(ws[i].ID,id)==0)
		{
		    break;
		}
	}
	if( i == num )
	{
	    cout<<"�����ڴ˹��ŵ�ְ��,��ȷ����������Ĺ���!!!"<<endl;  
	    return;
	}

	cout<<"�Ƿ�ȷ��ɾ������ȷ������1����ȡ�������1��";
	cin>>code;

    if( code == '1' )
	{
	    for(; i < num-1 ;i++)
		{
	        ws[i]=ws[i+1];
		}

	    num=num-1;
	    cout<<"ɾ���ɹ�!!!!!!"<<endl;
	}
	else
	{
        cout<<"��ȡ��ɾ������!!!!!"<<endl;
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
    int i;
    cout<<"����������ְ���Ļ�����Ϣ��";
    while(true)
	{
	    cout<<"������ְ�����ţ�";
	    cin>>ws[num].ID;
		for(i=0;i<num;i++)
		{
			if(strcmp(ws[i].ID,ws[num].ID)==0)
			{
			    cout<<"�˹����Ѿ����ڣ�����������"<<endl;
				break;
			}
		}
		if( i == num )
		{
			cout<<"������ְ��������";
			cin>>ws[num].name;
			cout<<"������ְ����λ���ʣ�";
			cin>>ws[num].p_salary;
			cout<<"������ְ��н�����ʣ�";
			cin>>ws[num].p_salary1;
			cout<<"������ְ��ְ�������";
			cin>>ws[num].p_salary2;
			cout<<"������ְ����Ч���ʣ�";
			cin>>ws[num].p_salary3;
			grsds(&ws[num]);
			num=num+1;
			cout<<"�����ɹ�������"<<endl;
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
	    cout<<"����������Ҫ�����Ĵ��룺"<<endl;
	    cout<<"1.��ѯ--2.�޸�--3.���--4.ɾ��--5.����--6.���--7.�˳�"<<endl;
	    cin>>code;   //������������
	    switch(code)
		{
	        case 1:   //��ѯ	       
	            cout<<"������������ѯְ�����ţ�"<<endl;
	            cin>>gonghao;
	            find(zggz,num,gonghao);
	            break;

	        case 2:  //�޸�
	            cout<<"�����������޸ĵ�ְ�����ţ�"<<endl;
	            cin>>gonghao;
	            modify(zggz,num,gonghao);
	            key=false;
	            break;

	        case 3:    //����
                add(zggz,num);
	            key=false;
	            break;

	        case 4:   //ɾ��
	            cout<<"����������ɾ����ְ�����ţ�"<<endl;
	            cin>>gonghao;
                del(zggz,num,gonghao);
	            key=false;
	            break;

	        case 5:    //����
		        write(zggz,num);
	    	    key=true;
	    	    break;

	        case 6:    //���
		        list(zggz,num);
	            break;

            case 7:      //�˳�
	            if(key)
				{
		            cout<<"�˳�����!!!!"<<endl;
		            return 0;
				}
		        else      //û�����޸ĺ�����ݣ����е���ʾ
				{   
					char code1;    
		            cout<<"�����޸ģ���û�б����ļ��У�����"<<endl;
		            cout<<"������������1�����б������²��������1"<<endl;
		            cin>>code1;
		            if( code1 == '1')
					{
		                return 0;
					}
		            else
					{
		                break;
					}
				}
            	
	        default:
		    cout<<"������Ĵ��벻��ȷ������"<<endl;
		}
	}
    return 0;
}