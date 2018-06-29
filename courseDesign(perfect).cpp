/*****************************************************************************
  Copyright (C) , 1988-1999 , 17软件工程.
  Filename: courseDesign.cpp
  Author:李波鸿    Version:0.3    Date: 2018-6-20
  Description:实现全部功能的大模块 只与职工数据文件gz.dat有联系 主程序调用各个函数//模块描述
  Function List: 
      1. read    从文件中读取全部职工数据
      2. write   把数据写入文件中
      3. list    把所有职工数据罗列出来
      4. find    查询对应工号的职工数据
      5. grsds   计算个人所得税,实际收入，和应发收入
      6. modify  修改对应工号职工的数据
      7. del     删除对应工号职工的数据
      8. add     增加职工的数据
  History: // 历史修改记录
      <author>    <time>     <version >   <desc>
        me        18/6/16    0.1          build this cpp
        me        18/6/16    0.3          modify this cpp
*****************************************************************************/
#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;
struct Worker_Salary           /*职工各项数据类型*/
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
Function:    read                                         // 函数名称
Description: 读取职工数据文件 gz.dat，对工号排序          // 函数功能、性能等的描述
Calls:       无                                           // 被本函数调用的函数清单
Called By:   主函数 main()                                // 调用本函数的函数清单
Input: 用来接收数据的值                                   // 输入参数说明，包括每个参数的作
                                                          // 用、取值说明及参数间关系。
Output:                                                   // 对输出参数的说明。
Return:职工数据的个数                                     // 函数返回值的说明
*************************************************/
int read(Worker_Salary ws[])   
{
    FILE *fp;
    if(( fp = fopen("gz.dat","rb"))==NULL)
    {
        printf("\t文件不存在或出错！！\n");
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

    for( int i = 0 ; i < num ; i++ )   //对读取初始数据工号进行排序
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
Function:    write                             // 函数名称
Description: 保存职工数据到文件gz.dat中        // 函数功能、性能等的描述
Calls:       无                                // 被本函数调用的函数清单
Called By:   主函数 main()                     // 调用本函数的函数清单
Input:ws的值用来写入文件数据                   // 输入参数说明，包括每个参数的作
                                               // 用、取值说明及参数间关系。
Output:                                        // 对输出参数的说明。
Return:无                                      // 函数返回值的说明
*************************************************/
void write(Worker_Salary ws[]) 
{ 
    FILE *fp;
    if((fp=fopen("gz.dat","wb"))==NULL)
    {
        printf("\t文件不存在或出错！！\n");
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
    printf("\t保存成功!!!!!\n");
}
/*************************************************
Function:    list                              // 函数名称
Description: 显示职工数据到显示器              // 函数功能、性能等的描述
Calls:       无                                // 被本函数调用的函数清单
Called By:   主函数 main()                     // 调用本函数的函数清单
Input:ws的值用来接收各个数据                   // 输入参数说明，包括每个参数的作
                                               // 用、取值说明及参数间关系。
Output:                                        // 对输出参数的说明。
Return:无                                      // 函数返回值的说明
*************************************************/
void list(Worker_Salary ws[])
{   
    p=head;
    while((*p).next!=NULL)
    {   
        printf("\t工号：%s  |  姓名：%s | 岗位工资：%.2f | ",(*p).ID,(*p).name,(*p).p_salary);
        printf("薪级工资：%.2f | \n\t职务津贴：%.2f | 绩效工资：%.2f | 应发工资：%.2f | \n",(*p).p_salary1,(*p).p_salary2,(*p).p_salary3,(*p).s_salary);
        printf("\t个人所得税：%.2f | 实发工资：%.2f\n",(*p).tax,(*p).real_salary);
        printf("___________________________________________________________________________________\n\n");
        p=p->next;
    }
}
/*************************************************
Function:    list                              // 函数名称
Description: 显示对应工号职工数据到显示器      // 函数功能、性能等的描述
Calls:       无                                // 被本函数调用的函数清单
Called By:   主函数 main()                     // 调用本函数的函数清单
Input:ws的值用来接收各个数据，id存查找的工号   // 输入参数说明，包括每个参数的作
                                               // 用、取值说明及参数间关系。
Output:                                        // 对输出参数的说明。
Return:无                                      // 函数返回值的说明
*************************************************/
void find(Worker_Salary ws[],char id[]) 
{   
    p=head;
    while((*p).next!=NULL)
    {
        if(strcmp((*p).ID,id)==0)
        {
            printf("\n\t工号：%s  |  姓名：%s | 岗位工资：%.2f | ",(*p).ID,(*p).name,(*p).p_salary);
            printf("薪级工资：%.2f | \n\t职务津贴：%.2f | 绩效工资：%.2f | 应发工资：%.2f | \n",(*p).p_salary1,(*p).p_salary2,(*p).p_salary3,(*p).s_salary);
            printf("\t个人所得税：%.2f | 实发工资：%.2f\n",(*p).tax,(*p).real_salary);
            printf("___________________________________________________________________________________\n\n");
            return;
        }
        p=p->next;
    }
    printf("\t不存在此工号的职工,请确认你所输入的工号!!!\n");
}
/*************************************************
Function:    grsds                             // 函数名称
Description: 计算个人所得税                    // 函数功能、性能等的描述
Calls:       无                                // 被本函数调用的函数清单
Called By:   modify  add                       // 调用本函数的函数清单
Input:ws的值用来接收传来的数据                 // 输入参数说明，包括每个参数的作
                                               // 用、取值说明及参数间关系。
Output:                                        // 对输出参数的说明。
Return:无                                      // 函数返回值的说明
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
Function:    modify                            // 函数名称
Description: 修改对应工号职工数据              // 函数功能、性能等的描述
Calls:       grsds                             // 被本函数调用的函数清单
Called By:   main()                            // 调用本函数的函数清单
Input:ws的值用来接收各个数据，num数据个数      // 输入参数说明，包括每个参数的作
      id接收修改的工号                         // 用、取值说明及参数间关系。
Output:                                        // 对输出参数的说明。
Return:无                                      // 函数返回值的说明
*************************************************/
void modify(Worker_Salary ws[],char id[])
{   
    p=head;
    while((*p).next!=NULL)
    {
        if(strcmp((*p).ID,id)==0)
        {   
            printf("\t请重新输入该职工的基本信息：\n");
            printf("\t请输入职工工号：");
            scanf("%s",(*p).ID);
            printf("\t请输入职工姓名：");
            scanf("%s",(*p).name);
            printf("\t请输入职工岗位工资：");
            scanf("%f",&(*p).p_salary);
            printf("\t请输入职工薪级工资：");
            scanf("%f",&(*p).p_salary1);
            printf("\t请输入职工职务津贴：");
            scanf("%f",&(*p).p_salary2);
            printf("\t请输入职工绩效工资：");
            scanf("%f",&(*p).p_salary3);
            grsds(p);
            printf("\t修改成功!!!!!!\n");
            return;
        }
        p=p->next;
    }
    printf("\t不存在此工号的职工,请确认你所输入的工号!!!\n");
}
/*************************************************
Function:    del                               // 函数名称
Description: 删除对应工号职工数据              // 函数功能、性能等的描述
Calls:                                         // 被本函数调用的函数清单
Called By:   main()                            // 调用本函数的函数清单
Input:ws的值用来接收各个数据，num数据个数      // 输入参数说明，包括每个参数的作
      id接收删除的工号                         // 用、取值说明及参数间关系。
Output:                                        // 对输出参数的说明。
Return:无                                      // 函数返回值的说明
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
        printf("\t不存在此工号的职工,请确认你所输入的工号!!!\n");  
        return;
    }

    char code;

    printf("\t是否确认删除：（确认输入1）（取消输入非1）");
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
        printf("\t删除成功!!!!!!\n");
    }
    else
    {
        printf("\t已取消删除操作!!!!!\n");
    }
}
/*************************************************
Function:    add                               // 函数名称
Description: 增加职工数据                      // 函数功能、性能等的描述
Calls:       grsds                             // 被本函数调用的函数清单
Called By:   main()                            // 调用本函数的函数清单
Input:ws的值用来接收各个数据，num数据个数      // 输入参数说明，包括每个参数的作
                                               // 用、取值说明及参数间关系。
Output:                                        // 对输出参数的说明。
Return:无                                      // 函数返回值的说明
*************************************************/
void add(Worker_Salary ws[],int &num)
{     
    char gonghao[10];
    printf("\t请输入新增职工的基本信息：");
    while(true)
    {
        printf("\t请输入职工工号：");
        scanf("%s",gonghao);
        p=head;
        while((*p).next!=NULL)
        {
            if(strcmp((*p).ID,gonghao)==0)
            {
                printf("\t此工号已经存在，请重新输入\n");
                break;
            }
			p=p->next;
        }
        if( (*p).next==NULL )
        {   
            strcpy(ws[data_num].ID,gonghao);
            printf("\t请输入职工姓名：");
            scanf("%s",ws[data_num].name);
            printf("\t请输入职工岗位工资：");
            scanf("%f",&ws[data_num].p_salary);
            printf("\t请输入职工薪级工资：");
            scanf("%f",&ws[data_num].p_salary1);
            printf("\t请输入职工职务津贴：");
            scanf("%f",&ws[data_num].p_salary2);
            printf("\t请输入职工绩效工资：");
            scanf("%f",&ws[data_num].p_salary3);
            grsds(&ws[data_num]);
            num=num+1;
            data_num+=1;
            (*p).next=&ws[data_num];
            ws[data_num].pre=p;
            ws[data_num].next=NULL;
            printf("\t新增成功！！！\n");
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
    int num = read(zggz);   //从文件中读取数据，并返回数据的个数
    bool key = true;
    int code;
    char gonghao[10];

    while(true)
    {   
        printf("\n\n\t### 欢迎使用广西民族大学软件与信息安全学院职工工资管理系统 ###\n\n\n");
        printf("\t请选择 (1 - 7) :\n");
        printf("\t======================================================================\n");
        printf("\t|\t1. 查询职工工资记录                                          |\n");
        printf("\t|\t2. 修改职工工资记录                                          |\n");
        printf("\t|\t3. 添加职工工资记录                                          |\n");
        printf("\t|\t4. 删除职工工资记录                                          |\n");
        printf("\t|\t5. 保存数据到文件                                            |\n");
        printf("\t|\t6. 浏览职工记录                                              |\n");
        printf("\t|\t7. 退出系统                                                  |\n");
        printf("\t======================================================================\n\n");
        printf("\t你的选择是：");
        scanf("%d",&code);   //操作代码输入
        switch(code)
        {
            case 1:   //查询	       
                printf("\t请输入你所查询职工工号：");
                scanf("%s",gonghao);
                find(zggz,gonghao);
                break;

            case 2:  //修改
                printf("\t请输入你所修改的职工工号：");
                scanf("%s",gonghao);
                modify(zggz,gonghao);
                key=false;
                break;

            case 3:    //新增
                add(zggz,num);
                key=false;
                break;

            case 4:   //删除
                printf("\t请输入你所删除的职工工号：");
                scanf("%s",gonghao);
                del(zggz,num,gonghao);
                key=false;
                break;

            case 5:    //保存
                write(zggz);
                key=true;
                break;

            case 6:    //浏览
                printf("\n");
                list(zggz);
                break;

            case 7:      //退出
                if(key)
                {
                    printf("\t退出操作!!!!\n");
                    return 0;
                }
                else      //没保存修改后的数据，进行的提示
                {   
                    char save_code;    
                    printf("\t数据修改，还没有保存文件中！！！\n");
                    printf("\t不保存请输入1，进行保存重新操作输入非1\n");
                    scanf("\n%c",&save_code);
                    if( save_code == '1')
                    {
                        printf("退出操作！！！\n");                        
                        return 0;
                    }
                    else
                    {
                        break;
                    }
                }
            	
            default:
                printf("\t你输入的代码不正确！！！ 请重新输入！！！\n");
        }
    }
    return 0;
}