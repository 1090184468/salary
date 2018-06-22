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
};
/*************************************************
Function:    read                              // 函数名称
Description: 读取职工数据文件 gz.dat           // 函数功能、性能等的描述
Calls:       无                                // 被本函数调用的函数清单
Called By:   主函数 main()                     // 调用本函数的函数清单
Input: 用来接收数据的值                        // 输入参数说明，包括每个参数的作
                                               // 用、取值说明及参数间关系。
Output:                                        // 对输出参数的说明。
Return:职工数据的个数                          // 函数返回值的说明
*************************************************/
int read(Worker_Salary ws[])   
{
	FILE *fp;
	if(( fp = fopen("gz.dat","rb"))==NULL){
	    printf("文件不存在或出错！！");
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
Function:    write                             // 函数名称
Description: 保存职工数据到文件gz.dat中        // 函数功能、性能等的描述
Calls:       无                                // 被本函数调用的函数清单
Called By:   主函数 main()                     // 调用本函数的函数清单
Input:ws的值用来写入文件数据，num数据个数      // 输入参数说明，包括每个参数的作
                                               // 用、取值说明及参数间关系。
Output:                                        // 对输出参数的说明。
Return:无                                      // 函数返回值的说明
*************************************************/
void write(Worker_Salary ws[],int num) 
{ 
    FILE *fp;
    if((fp=fopen("gz.dat","wb"))==NULL)
	{
	    cout<<"文件不存在或出错！！";
	    getchar();
	    exit(-1);
	}
    fwrite(ws,sizeof(struct Worker_Salary),num,fp);
    fclose(fp);
    cout<<"保存成功!!!!!"<<endl;
}
/*************************************************
Function:    list                              // 函数名称
Description: 显示职工数据到显示器              // 函数功能、性能等的描述
Calls:       无                                // 被本函数调用的函数清单
Called By:   主函数 main()                     // 调用本函数的函数清单
Input:ws的值用来接收各个数据，num数据个数      // 输入参数说明，包括每个参数的作
                                               // 用、取值说明及参数间关系。
Output:                                        // 对输出参数的说明。
Return:无                                      // 函数返回值的说明
*************************************************/
void list(Worker_Salary ws[],int num)
{   int i;
    for(i=0;i<num;i++)
	{
        cout<<"工号："<<ws[i].ID<<"  |  "<<"姓名："<<ws[i].name<<"  |  "<<"岗位工资："<<ws[i].p_salary<<"  |  ";
        cout<<"薪级工资："<<ws[i].p_salary1<<"  |  "<<'\n'<<"职务津贴："<<ws[i].p_salary2<<"  |  ";
        cout<<"绩效工资："<<ws[i].p_salary3<<"  |  "<<"应发工资："<<ws[i].s_salary<<"  |  "<<'\n';
        cout<<"个人所得税："<<ws[i].tax<<"  |  "<<"实发工资："<<ws[i].real_salary<<"  |"<<endl;
        cout<<"________________________________________________________________________________"<<endl;
	}
}
/*************************************************
Function:    list                              // 函数名称
Description: 显示对应工号职工数据到显示器      // 函数功能、性能等的描述
Calls:       无                                // 被本函数调用的函数清单
Called By:   主函数 main()                     // 调用本函数的函数清单
Input:ws的值用来接收各个数据，num数据个数      // 输入参数说明，包括每个参数的作
      id存查找的工号                           // 用、取值说明及参数间关系。
Output:                                        // 对输出参数的说明。
Return:无                                      // 函数返回值的说明
*************************************************/
void find(Worker_Salary ws[],int num,char id[]) 
{   int i;
	for( i = 0 ;i<num;i++)
	{
        if(strcmp(ws[i].ID,id)==0)
		{
		    cout<<"工号："<<ws[i].ID<<"  |  "<<"姓名："<<ws[i].name<<"  |  "<<"岗位工资："<<ws[i].p_salary<<"  |  ";
			cout<<"薪级工资："<<ws[i].p_salary1<<"  |  "<<'\n'<<"职务津贴："<<ws[i].p_salary2<<"  |  ";
			cout<<"绩效工资："<<ws[i].p_salary3<<"  |  "<<"应发工资："<<ws[i].s_salary<<"  |  "<<'\n';
			cout<<"个人所得税："<<ws[i].tax<<"  |  "<<"实发工资："<<ws[i].real_salary<<"  |"<<endl;
			cout<<"________________________________________________________________________________"<<endl;
			return;
		}
	}
	cout<<"不存在此工号的职工,请确认你所输入的工号!!!"<<endl;
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
void modify(Worker_Salary ws[],int num,char id[])
{   int i;
    for( i=0;i<num;i++)
	{
	    if(strcmp(ws[i].ID,id)==0)
		{
		    cout<<"请重新输入该职工的基本信息：";
		    cout<<"请输入职工工号：";
		    cin>>ws[i].ID;
		    cout<<"请输入职工姓名：";
		    cin>>ws[i].name;
		    cout<<"请输入职工岗位工资：";
		    cin>>ws[i].p_salary;
		    cout<<"请输入职工薪级工资：";
		    cin>>ws[i].p_salary1;
		    cout<<"请输入职工职务津贴：";
		    cin>>ws[i].p_salary2;
		    cout<<"请输入职工绩效工资：";
		    cin>>ws[i].p_salary3;
		    grsds(&ws[i]);
		    cout<<"修改成功!!!!!!"<<endl;
		    return;
		}
	}
	cout<<"不存在此工号的职工,请确认你所输入的工号!!!"<<endl;
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
	    cout<<"不存在此工号的职工,请确认你所输入的工号!!!"<<endl;  
	    return;
	}

	cout<<"是否确认删除：（确认输入1）（取消输入非1）";
	cin>>code;

    if( code == '1' )
	{
	    for(; i < num-1 ;i++)
		{
	        ws[i]=ws[i+1];
		}

	    num=num-1;
	    cout<<"删除成功!!!!!!"<<endl;
	}
	else
	{
        cout<<"已取消删除操作!!!!!"<<endl;
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
    int i;
    cout<<"请输入新增职工的基本信息：";
    while(true)
	{
	    cout<<"请输入职工工号：";
	    cin>>ws[num].ID;
		for(i=0;i<num;i++)
		{
			if(strcmp(ws[i].ID,ws[num].ID)==0)
			{
			    cout<<"此工号已经存在，请重新输入"<<endl;
				break;
			}
		}
		if( i == num )
		{
			cout<<"请输入职工姓名：";
			cin>>ws[num].name;
			cout<<"请输入职工岗位工资：";
			cin>>ws[num].p_salary;
			cout<<"请输入职工薪级工资：";
			cin>>ws[num].p_salary1;
			cout<<"请输入职工职务津贴：";
			cin>>ws[num].p_salary2;
			cout<<"请输入职工绩效工资：";
			cin>>ws[num].p_salary3;
			grsds(&ws[num]);
			num=num+1;
			cout<<"新增成功！！！"<<endl;
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
	    cout<<"请输入你所要操作的代码："<<endl;
	    cout<<"1.查询--2.修改--3.添加--4.删除--5.保存--6.浏览--7.退出"<<endl;
	    cin>>code;   //操作代码输入
	    switch(code)
		{
	        case 1:   //查询	       
	            cout<<"请输入你所查询职工工号："<<endl;
	            cin>>gonghao;
	            find(zggz,num,gonghao);
	            break;

	        case 2:  //修改
	            cout<<"请输入你所修改的职工工号："<<endl;
	            cin>>gonghao;
	            modify(zggz,num,gonghao);
	            key=false;
	            break;

	        case 3:    //新增
                add(zggz,num);
	            key=false;
	            break;

	        case 4:   //删除
	            cout<<"请输入你所删除的职工工号："<<endl;
	            cin>>gonghao;
                del(zggz,num,gonghao);
	            key=false;
	            break;

	        case 5:    //保存
		        write(zggz,num);
	    	    key=true;
	    	    break;

	        case 6:    //浏览
		        list(zggz,num);
	            break;

            case 7:      //退出
	            if(key)
				{
		            cout<<"退出操作!!!!"<<endl;
		            return 0;
				}
		        else      //没保存修改后的数据，进行的提示
				{   
					char code1;    
		            cout<<"数据修改，还没有保存文件中！！！"<<endl;
		            cout<<"不保存请输入1，进行保存重新操作输入非1"<<endl;
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
		    cout<<"你输入的代码不正确！！！"<<endl;
		}
	}
    return 0;
}