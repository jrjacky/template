//�ļ������.cpp
#include<iostream>
using namespace std;
int n,m,ba[4010][2],bb[4010][2],len[4010][4010],ans[4010][4010];
char a[4010],b[4010];
int main()
{
	FILE *fp;
	char NUMBER[100];
	string number,infilename,outfilename;
	fp=fopen("infilenumber.txt","r");
	fscanf(fp,"%s",NUMBER);
	fclose(fp);
	number=NUMBER;
	infilename="***"+number+".in",outfilename="***"+number+".out";
	freopen(infilename.c_str(),"r",stdin);
	freopen(outfilename.c_str(),"w",stdout);
	......
}
//�ļ����������.cpp
#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
	for(int i=1;i<=100;i++){
		srand(i);
		string number,filename;
		number.clear();
		filename.clear();
		if(i<10) number="00",number+=(char)(i+'0');
		else if(i<100) number="0",number+=(char)(i/10+'0'),number+=(char)(i%10+'0');
		else number="100";
		/*
		if(i<10) number="000",number+=(char)(i+'0');
		else if(i<100) number="00",number+=(char)(i/10+'0'),number+=(char)(i%10+'0');
		else if(i<1000) number="0",number+=(char)(i/100+'0'),number+=(char)((i/10)%10+'0'),number+=(char)(i%10+'0');
		else number="1000"
		*/
		filename="***"+number+".in";
		FILE *fp;
		fp=fopen("infilenumber.txt","w");
		fprintf(fp,"%s",number.c_str());
		fclose(fp);
		fp=fopen(filename.c_str(),"w");
		......
		fclose(fp);
		system("���.exe");
	}
} 
/*
����������
���ļ�"���.cpp"��д����̣����ļ�"�������.cpp"��д���������
��"�������.cpp"�У��������ʹ��fprintf��cout��printf��Ч�����ʽΪ��fprintf(fp,"...",...)��"fp,"����Ĳ�������ͨprintf��ͬ 
��"���.cpp"�в���Ҫʹ��fprintf
Ȼ��"***"�޸�Ϊ�Լ����ļ���
i�ķ�ΧĬ��Ϊ1~100��������100�����ݣ������е����������޳���100����ʹ��ע���еĴ��루Ӧ�ò��ᳬ��1000�ɣ�����1000��Ҳû�취��
����ȱ���"���.cpp"��������"�������.cpp"���� 
*/
