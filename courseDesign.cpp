#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;
struct Worker_Salary{
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
int read(Worker_Salary ws[]){   //从文件gx.dat读取数据
	FILE *fp;
	if((fp=fopen("gx.dat","rb"))==NULL){
		cout<<"文件不存在或出错！！";
		getchar();
		exit(-1);
	}
	int n=0;
	while(fread(&ws[n],sizeof(struct Worker_Salary),1,fp)){
		n++;
	};
   fclose(fp);
   return n;
}
void write(Worker_Salary ws[],int n){  //保存操作  把数据写入文件中 gx.dat
	FILE *fp;
	if((fp=fopen("gx.dat","wb"))==NULL){
		cout<<"文件不存在或出错！！";
		getchar();
		exit(-1);
	}
   fwrite(ws,sizeof(struct Worker_Salary),n,fp);
   fclose(fp);
   cout<<"保存成功!!!!!"<<endl;
}
void list(Worker_Salary ws[],int n){  //浏览全部数据
	for(int i=0;i<n;i++){
	cout<<"工号："<<ws[i].ID<<"  |  "<<"姓名："<<ws[i].name<<"  |  "<<"岗位工资："<<ws[i].p_salary<<"  |  ";
    cout<<"薪级工资："<<ws[i].p_salary1<<"  |  "<<'\n'<<"职务津贴："<<ws[i].p_salary2<<"  |  ";
	cout<<"绩效工资："<<ws[i].p_salary3<<"  |  "<<"应发工资："<<ws[i].s_salary<<"  |  "<<'\n';
	cout<<"个人所得税："<<ws[i].tax<<"  |  "<<"实发工资："<<ws[i].real_salary<<"  |"<<endl;
	cout<<"________________________________________________________________________________"<<endl;
	}
}
void find(Worker_Salary ws[],int n,char id[]){  //查询数据
	for(int i=0;i<n;i++){
		if(strcmp(ws[i].ID,id)==0){
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
void grsds(Worker_Salary ws[],int n){   //税率计算函数
    for(int i=0;i<n;i++){
		if((ws[i].p_salary+ws[i].p_salary1+ws[i].p_salary2+ws[i].p_salary3)<500){
		ws[i].s_salary=ws[i].p_salary+ws[i].p_salary1+ws[i].p_salary2+ws[i].p_salary3;
		ws[i].tax=ws[i].s_salary*0.05;
		ws[i].real_salary=ws[i].s_salary-ws[i].tax;
		}
		else if((ws[i].p_salary+ws[i].p_salary1+ws[i].p_salary2+ws[i].p_salary3)<2000){
		ws[i].s_salary=ws[i].p_salary+ws[i].p_salary1+ws[i].p_salary2+ws[i].p_salary3;
		ws[i].tax=500*0.05+(ws[i].s_salary-500)*0.1;
		ws[i].real_salary=ws[i].s_salary-ws[i].tax;
		}
		else if((ws[i].p_salary+ws[i].p_salary1+ws[i].p_salary2+ws[i].p_salary3)<5000){

		ws[i].s_salary=ws[i].p_salary+ws[i].p_salary1+ws[i].p_salary2+ws[i].p_salary3;
		ws[i].tax=500*0.05+1500*0.1+(ws[i].s_salary-2000)*0.15;
		ws[i].real_salary=ws[i].s_salary-ws[i].tax;
		}
		else if((ws[i].p_salary+ws[i].p_salary1+ws[i].p_salary2+ws[i].p_salary3)<20000){
	
		ws[i].s_salary=ws[i].p_salary+ws[i].p_salary1+ws[i].p_salary2+ws[i].p_salary3;
		ws[i].tax=500*0.05+1500*0.1+3000*0.15+(ws[i].s_salary-5000)*0.20;
		ws[i].real_salary=ws[i].s_salary-ws[i].tax;
		}
		else if((ws[i].p_salary+ws[i].p_salary1+ws[i].p_salary2+ws[i].p_salary3)<40000){	
		ws[i].s_salary=ws[i].p_salary+ws[i].p_salary1+ws[i].p_salary2+ws[i].p_salary3;
		ws[i].tax=500*0.05+1500*0.1+3000*0.15+15000*0.2+(ws[i].s_salary-20000)*0.25;
		ws[i].real_salary=ws[i].s_salary-ws[i].tax;
		}
		else if((ws[i].p_salary+ws[i].p_salary1+ws[i].p_salary2+ws[i].p_salary3)<60000){
		ws[i].s_salary=ws[i].p_salary+ws[i].p_salary1+ws[i].p_salary2+ws[i].p_salary3;
		ws[i].tax=500*0.05+1500*0.1+3000*0.15+15000*0.2+20000*0.25+(ws[i].s_salary-40000)*0.3;
		ws[i].real_salary=ws[i].s_salary-ws[i].tax;
		}
		else if((ws[i].p_salary+ws[i].p_salary1+ws[i].p_salary2+ws[i].p_salary3)<80000){	
		ws[i].s_salary=ws[i].p_salary+ws[i].p_salary1+ws[i].p_salary2+ws[i].p_salary3;
		ws[i].tax=500*0.05+1500*0.1+3000*0.15+15000*0.2+20000*0.25+20000*0.30+(ws[i].s_salary-60000)*0.35;
		ws[i].real_salary=ws[i].s_salary-ws[i].tax;
		}
		else if((ws[i].p_salary+ws[i].p_salary1+ws[i].p_salary2+ws[i].p_salary3)<100000){
		ws[i].s_salary=ws[i].p_salary+ws[i].p_salary1+ws[i].p_salary2+ws[i].p_salary3;
		ws[i].tax=500*0.05+1500*0.1+3000*0.15+15000*0.2+20000*0.25+20000*0.30+20000*0.35+(ws[i].s_salary-60000)*0.40;
		ws[i].real_salary=ws[i].s_salary-ws[i].tax;
		}else{
		ws[i].s_salary=ws[i].p_salary+ws[i].p_salary1+ws[i].p_salary2+ws[i].p_salary3;
		ws[i].tax=500*0.05+1500*0.1+3000*0.15+15000*0.2+20000*0.25+20000*0.30+20000*0.35+20000*0.4+(ws[i].s_salary-80000)*0.45;
		ws[i].real_salary=ws[i].s_salary-ws[i].tax;
		}
	}
}
void modify(Worker_Salary ws[],int n,char id[]){  //修改数据
    for(int i=0;i<n;i++){
		if(strcmp(ws[i].ID,id)==0){
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
		 grsds(&ws[i],1);
		 cout<<"修改成功!!!!!!"<<endl;
		 return;
		}
	}
	cout<<"不存在此工号的职工,请确认你所输入的工号!!!"<<endl;
}

void del(Worker_Salary ws[],int &n,char id[]){  //删除数据
	int i;
	char y;
	for(i=0;i<n;i++){
			if(strcmp(ws[i].ID,id)==0){
		       break;
			}
	}
	if(i==n){
	cout<<"不存在此工号的职工,请确认你所输入的工号!!!"<<endl;
	return;
	}
	cout<<"是否确认删除：（确认输入1）（取消输入非1）";
	cin>>y;
if(y=='1'){
	for(;i<n-1;i++){
	ws[i]=ws[i+1];
	}
	n--;
	cout<<"删除成功!!!!!!"<<endl;
}else{
    cout<<"已取消删除操作!!!!!"<<endl;
}
}
void add(Worker_Salary ws[],int &n){     //新增数据
	     int i;
         cout<<"请输入新增职工的基本信息：";
		 while(true){
			 cout<<"请输入职工工号：";
			 cin>>ws[n].ID;
			 for(i=0;i<n;i++){
				 if(strcmp(ws[i].ID,ws[n].ID)==0){
				 cout<<"此工号已经存在，请重新输入"<<endl;
				 break;
				 }
			 }
			 if(i==n){
				 cout<<"请输入职工姓名：";
				 cin>>ws[n].name;
				 cout<<"请输入职工岗位工资：";
				 cin>>ws[n].p_salary;
				 cout<<"请输入职工薪级工资：";
				 cin>>ws[n].p_salary1;
				 cout<<"请输入职工职务津贴：";
				 cin>>ws[n].p_salary2;
				 cout<<"请输入职工绩效工资：";
				 cin>>ws[n].p_salary3;
				 grsds(&ws[n],1);
				 n++;
				 cout<<"新增成功！！！"<<endl;
				 break;
			 }else {
			 continue;
			 }
		 }
		 
		 
}
int main(){
	Worker_Salary ws[100];
	int n=read(ws);   //从文件中读取数据
	bool key=true;
	int c;
	while(true){
	cout<<"请输入你所要操作的代码："<<endl;
	cout<<"1.查询--2.修改--3.添加--4.删除--5.保存--6.浏览--7.退出"<<endl;
	cin>>c;   //操作代码输入
	switch(c){       //操作过程
	case 1:   //查询
	   char id[10];
	   cout<<"请输入你所查询职工工号："<<endl;
	   cin>>id;
	   find(ws,n,id);
	   break;
	case 2:  //修改
       char id1[10];
	   cout<<"请输入你所修改的职工工号："<<endl;
	   cin>>id1;
	   modify(ws,n,id1);
	   key=false;
	   break;
	case 3:    //新增
       add(ws,n);
	   key=false;
	   break;
	case 4:   //删除
	   char id2[10];
	   cout<<"请输入你所删除的职工工号："<<endl;
	   cin>>id2;
       del(ws,n,id2);
	   key=false;
	   break;
	case 5:    //保存
		write(ws,n);
		key=true;
		break;
	case 6:    //浏览
		list(ws,n);
		break;
    case 7:      //退出
		if(key){
		cout<<"退出操作!!!!"<<endl;
		return 0;
		}else{
		cout<<"数据修改，还没有保存文件中！！！"<<endl;
		cout<<"不保存请输入1，进行保存重新操作输入非1"<<endl;
		char y;
		cin>>y;
		if(y=='1'){
			return 0;
		}else{
			break;
		}
		}
		
	default:
		cout<<"你输入的代码不正确！！！"<<endl;
	}
	}
	return 0;
}