
   #include "string.h"
#include "iostream"
using namespace std;
#define FALSE 0
#define TRUE 1
#define W 10
#define R 20
int M=4 ; //�ܽ�����
int N=3 ; //��Դ����
int ALL_RESOURCE[3]={9,3,6};//������Դ����Ŀ�ܺ�
int MAX[4][3]={{3,2,2},{6,1,3},{3,1,4},{4,2,2}}; //M�����̶�N����Դ�����Դ������
int AVAILABLE[R]; //ϵͳ������Դ��
int ALLOCATION[4][3]={{1,0,0},{6,1,2},{2,1,1},{0,0,2}}; //M�������Ѿ��õ�N����Դ����Դ��
int NEED[W][R]; //M�����̻���ҪN����Դ����Դ��
int Request[R]; //������Դ����
 
void showdata() //����showdata,�����Դ�������
{
   int i,j;
   cout<<"������Դ��������(all):";
   cout<<" [";
   for (j=0;j<N;j++)cout<<" "<<ALL_RESOURCE[j];
   cout<<" ]";
   cout<<endl<<endl;
   cout<<"ϵͳĿǰ������Դ���õ���Ϊ(available):";
   cout<<" [";
   for (j=0;j<N;j++)cout<<" "<<AVAILABLE[j];
   cout<<" ]";
   cout<<endl<<endl;
 
   cout<<" �������Ѿ��õ�����Դ��(allocation): "<<endl<<endl;
   cout<<"       ��Դ0"<<"     ��Դ1"<<"     ��Դ2"<<endl;
   for (i=0;i<M;i++)
   {
     cout<<"����p"<<i<<":    ";
     for (j=0;j<N;j++)cout<<ALLOCATION[i][j]<<"       ";
     cout<<endl;
   }
   cout<<endl;
   cout<<" �����̻���Ҫ����Դ��(need):"<<endl<<endl;
   cout<<"       ��Դ0"<<"     ��Դ1"<<"    ��Դ2"<<endl;
   for (i=0;i<M;i++)
   for (i=0;i<M;i++)
   {
     cout<<"����p"<<i<<":   ";
     for (j=0;j<N;j++)cout<<NEED[i][j]<<"        ";;
     cout<<endl;
   }
   cout<<endl;
}
void changdata(int k) //������Դ
{
   int j;
   for (j=0;j<N;j++)
   {
     AVAILABLE[j]=AVAILABLE[j]-Request[j];
     ALLOCATION[k][j]=ALLOCATION[k][j]+Request[j];
     NEED[k][j]=NEED[k][j]-Request[j];}}
 
void rstordata(int k) //�ָ��ֳ�
{
   int j;
   for (j=0;j<N;j++)
   { AVAILABLE[j]=AVAILABLE[j]+Request[j];
     ALLOCATION[k][j]=ALLOCATION[k][j]-Request[j];
     NEED[k][j]=NEED[k][j]+Request[j];}}
 
int chkerr(int s) //����chkerr,����Ƿ�ȫ
{ int WORK,FINISH[W];
    int i,j,k=0;
    for(i=0;i<M;i++)FINISH[i]=FALSE;
    for(j=0;j<N;j++)
     {
            WORK=AVAILABLE[j];
        i=s;
        do
            {
          if(FINISH[i]==FALSE&&NEED[i][j]<=WORK)
            {
               WORK=WORK+ALLOCATION[i][j];
               FINISH[i]=TRUE;
               i=0;
            }
          else
            { i++;
            }
            }while(i<M);
        for(i=0;i<M;i++)
        if(FINISH[i]==FALSE)
            {
            cout<<endl;
           cout<<" ϵͳ����ȫ!!! ������Դ���벻�ɹ�!!!"<<endl;
           cout<<endl;
           return 1;
            }
     }
    cout<<endl;
    cout<<" ����ȫ�Լ�飬ϵͳ��ȫ�����η���ɹ���"<<endl;
    cout<<endl;
    return 0;
}
void bank()   //���м��㷨����
{
     int i=0,j=0;
     char flag='Y';
    
     while(flag=='Y'||flag=='y')
     {
       i=-1;
       while(i<0||i>=M)
        {
         cout<<" ��������������Դ�Ľ��̺ţ���P0��P"<<M-1<<"������������!��:";
         cout<<"P";cin>>i;
         if(i<0||i>=M)cout<<" ����Ľ��̺Ų����ڣ���������!"<<endl;
        }
      cout<<" ���������P"<<i<<"�������Դ��:"<<endl;
     for (j=0;j<N;j++)
     {
        cout<<" ��Դ"<<j<<": ";
        cin>>Request[j];
      if(Request[j]>NEED[i][j]) //���������Դ�����ڽ��̻���Ҫi����Դ����Դ��j
     {
         cout<<" ����P"<<i<<"�������Դ�����ڽ���P"<<i<<"����Ҫ"<<j<<"����Դ����Դ��!";
         cout<<"���벻��������!������ѡ��!"<<endl<<endl;
         flag='N';
         break;
     }
    else
     {
     if(Request[j]>AVAILABLE[j]) //���������Դ�����ڿ�����Դ��
     {
      cout<<" ����P"<<i<<"�������Դ������ϵͳ����"<<j<<"����Դ����Դ��!";
      cout<<"���벻��������!������ѡ��!"<<endl<<endl;
     flag='N';
      break;
            }
     }
     }
     if(flag=='Y'||flag=='y')
     {
      changdata(i); //����changdata(i)�������ı���Դ��
      if(chkerr(i)) //��ϵͳ��ȫ
     {
         rstordata(i); //����rstordata(i)�������ָ���Դ��
         showdata();   //�����Դ�������
     }
      else       //��ϵͳ����ȫ
      showdata(); //�����Դ�������
     }
      else      //��flag=N||flag=n
      showdata();
      cout<<endl;
      cout<<" �Ƿ�������м��㷨��ʾ,��'Y'��'y'������,��'N'��'n'���˳���ʾ: ";
      cin>>flag;
     }
}
//������
void main() 
{
   int i=0,j=0,p;
     //��ʼ����Դ����
      for (j=0;j<N;j++)
      { p=ALL_RESOURCE[j];
         for (i=0;i<M;i++)
          {
           p=p-ALLOCATION[i][j];//��ȥ�Ѿ���ռ�ݵ���Դ
           AVAILABLE[j]=p;
           if(AVAILABLE[j]<0)
           AVAILABLE[j]=0;
           }
     }
      for (i=0;i<M;i++)
      for(j=0;j<N;j++)
         NEED[i][j]=MAX[i][j]-ALLOCATION[i][j];
      showdata();
      bank();
}
