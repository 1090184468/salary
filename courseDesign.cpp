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
int read(Worker_Salary ws[]){   //���ļ�gx.dat��ȡ����
	FILE *fp;
	if((fp=fopen("gx.dat","rb"))==NULL){
		cout<<"�ļ������ڻ������";
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
void write(Worker_Salary ws[],int n){  //�������  ������д���ļ��� gx.dat
	FILE *fp;
	if((fp=fopen("gx.dat","wb"))==NULL){
		cout<<"�ļ������ڻ������";
		getchar();
		exit(-1);
	}
   fwrite(ws,sizeof(struct Worker_Salary),n,fp);
   fclose(fp);
   cout<<"����ɹ�!!!!!"<<endl;
}
void list(Worker_Salary ws[],int n){  //���ȫ������
	for(int i=0;i<n;i++){
	cout<<"���ţ�"<<ws[i].ID<<"  |  "<<"������"<<ws[i].name<<"  |  "<<"��λ���ʣ�"<<ws[i].p_salary<<"  |  ";
    cout<<"н�����ʣ�"<<ws[i].p_salary1<<"  |  "<<'\n'<<"ְ�������"<<ws[i].p_salary2<<"  |  ";
	cout<<"��Ч���ʣ�"<<ws[i].p_salary3<<"  |  "<<"Ӧ�����ʣ�"<<ws[i].s_salary<<"  |  "<<'\n';
	cout<<"��������˰��"<<ws[i].tax<<"  |  "<<"ʵ�����ʣ�"<<ws[i].real_salary<<"  |"<<endl;
	cout<<"________________________________________________________________________________"<<endl;
	}
}
void find(Worker_Salary ws[],int n,char id[]){  //��ѯ����
	for(int i=0;i<n;i++){
		if(strcmp(ws[i].ID,id)==0){
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
void grsds(Worker_Salary ws[],int n){   //˰�ʼ��㺯��
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
void modify(Worker_Salary ws[],int n,char id[]){  //�޸�����
    for(int i=0;i<n;i++){
		if(strcmp(ws[i].ID,id)==0){
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
		 grsds(&ws[i],1);
		 cout<<"�޸ĳɹ�!!!!!!"<<endl;
		 return;
		}
	}
	cout<<"�����ڴ˹��ŵ�ְ��,��ȷ����������Ĺ���!!!"<<endl;
}

void del(Worker_Salary ws[],int &n,char id[]){  //ɾ������
	int i;
	char y;
	for(i=0;i<n;i++){
			if(strcmp(ws[i].ID,id)==0){
		       break;
			}
	}
	if(i==n){
	cout<<"�����ڴ˹��ŵ�ְ��,��ȷ����������Ĺ���!!!"<<endl;
	return;
	}
	cout<<"�Ƿ�ȷ��ɾ������ȷ������1����ȡ�������1��";
	cin>>y;
if(y=='1'){
	for(;i<n-1;i++){
	ws[i]=ws[i+1];
	}
	n--;
	cout<<"ɾ���ɹ�!!!!!!"<<endl;
}else{
    cout<<"��ȡ��ɾ������!!!!!"<<endl;
}
}
void add(Worker_Salary ws[],int &n){     //��������
	     int i;
         cout<<"����������ְ���Ļ�����Ϣ��";
		 while(true){
			 cout<<"������ְ�����ţ�";
			 cin>>ws[n].ID;
			 for(i=0;i<n;i++){
				 if(strcmp(ws[i].ID,ws[n].ID)==0){
				 cout<<"�˹����Ѿ����ڣ�����������"<<endl;
				 break;
				 }
			 }
			 if(i==n){
				 cout<<"������ְ��������";
				 cin>>ws[n].name;
				 cout<<"������ְ����λ���ʣ�";
				 cin>>ws[n].p_salary;
				 cout<<"������ְ��н�����ʣ�";
				 cin>>ws[n].p_salary1;
				 cout<<"������ְ��ְ�������";
				 cin>>ws[n].p_salary2;
				 cout<<"������ְ����Ч���ʣ�";
				 cin>>ws[n].p_salary3;
				 grsds(&ws[n],1);
				 n++;
				 cout<<"�����ɹ�������"<<endl;
				 break;
			 }else {
			 continue;
			 }
		 }
		 
		 
}
int main(){
	Worker_Salary ws[100];
	int n=read(ws);   //���ļ��ж�ȡ����
	bool key=true;
	int c;
	while(true){
	cout<<"����������Ҫ�����Ĵ��룺"<<endl;
	cout<<"1.��ѯ--2.�޸�--3.���--4.ɾ��--5.����--6.���--7.�˳�"<<endl;
	cin>>c;   //������������
	switch(c){       //��������
	case 1:   //��ѯ
	   char id[10];
	   cout<<"������������ѯְ�����ţ�"<<endl;
	   cin>>id;
	   find(ws,n,id);
	   break;
	case 2:  //�޸�
       char id1[10];
	   cout<<"�����������޸ĵ�ְ�����ţ�"<<endl;
	   cin>>id1;
	   modify(ws,n,id1);
	   key=false;
	   break;
	case 3:    //����
       add(ws,n);
	   key=false;
	   break;
	case 4:   //ɾ��
	   char id2[10];
	   cout<<"����������ɾ����ְ�����ţ�"<<endl;
	   cin>>id2;
       del(ws,n,id2);
	   key=false;
	   break;
	case 5:    //����
		write(ws,n);
		key=true;
		break;
	case 6:    //���
		list(ws,n);
		break;
    case 7:      //�˳�
		if(key){
		cout<<"�˳�����!!!!"<<endl;
		return 0;
		}else{
		cout<<"�����޸ģ���û�б����ļ��У�����"<<endl;
		cout<<"������������1�����б������²��������1"<<endl;
		char y;
		cin>>y;
		if(y=='1'){
			return 0;
		}else{
			break;
		}
		}
		
	default:
		cout<<"������Ĵ��벻��ȷ������"<<endl;
	}
	}
	return 0;
}