#include <iostream>
#include <stack>
#include <string>
#include <iostream>
#include <fstream>
#include <io.h>
#include <conio.h>
 
using namespace std;
int main(int argc, char *argv[])
{
	fstream filein;
    filein.open("BRACKET.INP", ios::in);
	ofstream fileout ("BRACKET.OUT");

    char strExpr[200];
    /*cout<<"Nhap vao day ngoac:";
    gets(strExpr);*/
	filein.getline(strExpr,200);
	filein.close();
    stack<int>ParentPos;
 
    for (int i=0;i<sizeof(strExpr);i++)
    {
        if (strExpr[i]=='(')
            {ParentPos.push(i);}
        else{
            if (strExpr[i]==')')
            {
                if (!ParentPos.empty())
                    ParentPos.pop();
                else
                    ParentPos.push(i);
            }
			}
    }
 
    if (ParentPos.empty()){
        cout<<"0";
        fileout<<"0"<<endl;
        }
    else
        {
            cout<<ParentPos.size()<<endl;
            fileout<<ParentPos.size()<<endl;
            while (!ParentPos.empty())
            {
			if (strExpr[ParentPos.top()]=='(') {cout<<") "<<(ParentPos.top()+1)<<endl;
				fileout<<") "<<(ParentPos.top()+1)<<endl;
				}else{ cout<<"( "<<ParentPos.top()<<endl;
				fileout<<"( "<<ParentPos.top()<<endl;
				}
                ParentPos.pop();
            }
	    }
    getch();
}

