//文件：标程.cpp
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
//文件：随机数据.cpp
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
		system("标程.exe");
	}
} 
/*
操作方法：
在文件"标程.cpp"中写出标程，在文件"随机数据.cpp"中写出随机数据
在"随机数据.cpp"中，输出必须使用fprintf，cout和printf无效，其格式为：fprintf(fp,"...",...)，"fp,"后面的部分与普通printf相同 
在"标程.cpp"中不需要使用fprintf
然后将"***"修改为自己的文件名
i的范围默认为1~100，即生成100个数据，可自行调整，若上限超过100，请使用注释中的代码（应该不会超过1000吧，超过1000我也没办法）
最后先编译"标程.cpp"，再运行"随机数据.cpp"即可 
*/
