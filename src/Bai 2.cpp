#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <io.h>
#include <string>
#include <sstream>
using namespace std;

int TimKiem(string &output, int ln, char s[], char s1[]) 
{
	int len = strlen(s); 
    int len1 = strlen(s1); 
    char *p=strstr(s,s1);
    int i; 
    int dem =0;
    ostringstream stm;
    while (p) 
    { 		i = p - s + 1;
           p++;
			p=strstr(p,s1);
           cout << "\t Line " << ln << " Col " << i << endl;
           stm << "\t Line " << ln << " Col " << i<< endl;
           dem ++;
    }
    output= output + stm.str()+ "\n";
    return dem;
}
void thaythe(string &text, char s[],char s1[],char s2[])
{
	char kq[255];
	int t=0,i=0,j,k,ns1=strlen(s1),ns2=strlen(s2);
	strcat(s,"|");

    while(s[i]!='|')
    {
    	k=i; j=0;
    	while (s[k]==s1[j]) {
    		k++; j++;
		}
		if(j==ns1) {
			for(int m=0;m<ns2;m++)
				kq[t++]=s2[m];
				i=ns1+i;
		}
		else {
			kq[t++]=s[i++];
		}
		
	}
	printf("\n");
	for(int i=0;i<t;i++) 
	{
	printf("%c",kq[i]);
	}
	text = text + kq + "\n";
}
int main()  {
	char a[255];
	char s[255];
	char s1[255];
	char s2[255];
	char kq[255];
	int m;
	int d=0;
	int ln=1;
	printf("> Nhap duong dan file: ");
	gets(a);
	string text;
   	string output;
   	ostringstream stm;    
	fstream fileinput;
    fileinput.open(a, ios::in);

    ofstream file ("output.txt");
	file<<"File nhap vao: "<< a <<endl;
    if (access(a, 0) != -1)
    {
        printf("> File ton tai, moi ban dua ra lua chon: \n");
        printf("------------------------------ \n");
        printf("\t 1. Tim kiem \n");
        printf("\t 2. Sua \n");
        printf("\t 3. Thoat \n");
        printf("------------------------------ \n");
		printf("> ");
		scanf("%d",&m);
		fflush(stdin);
		switch(m)
   {
   case 1 :
		file<<"Context 1: Tim kiem tu khoa " <<endl;
		cout << "> Moi nhap tu khoa: ";
	  	cin >> s1;
	  	file<<"\t Tu khoa: "<<s1<<endl;	
		while(fileinput.getline(s,255)) {
        	d= d+ TimKiem(output, ln, s, s1);
	  		ln++;
	  	}
	  	
	  	cout << "> So lan xuat hien " << d << endl;
	  	stm << "> So lan xuat hien " << d << endl;
	  	file << stm.str() +"\n";
		file << output;
	  	file.close();
	  	break;
    
   case 2 :
   	  file<<"Context 2: Thay the bang tu khoa moi"<<endl;
	  cout << "> Moi nhap tu khoa: " << endl;
	  cin >>s1;
	  file<<"\t Tu khoa: "<<s1<<endl;
	  cout << "> Moi nhap tu khoa moi: " << endl;
	  cin >> s2;
	  file<<"\t Tu khoa moi: "<<s2<<endl;
	 while(fileinput.getline(s,255)) {
        	d= d+ TimKiem(output, ln, s, s1);
	  		ln++;
	  	}
	  	
	  	cout << "> So vi tri thay the: " << d << endl;
	  	stm << "> So vi tri thay the: " << d << endl;
	  	file << stm.str() +"\n";
		file << output;
	  	file.close();
	  	fileinput.close();
	  	fileinput.open(a, ios::in);

	  while(fileinput.getline(s,255)) {
		thaythe(text,s,s1,s2);
	  	}
	  	fileinput.close();
		fileinput.open(a, ios::out | ios::trunc);
		fileinput << text ;
		file.close();
		
      	break;
	case 3 :
      exit(0);
      break;	    
    default :
      cout << "Gia tri khong hop le" << endl;
   }
    }else
    {
        printf("File khong hop le");
    }


    return 0;
}
