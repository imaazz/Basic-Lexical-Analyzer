// Lexical Analyzer
// Teacher :Sir Shahzad
// Members:
// Roll:19k-0148 Muhammad Maaz
// Roll:19k-0133 Saad Ali
// Roll:19k-0346 Faizan Sadiq
//Summary:-In this project we will parse a C code into words and will identify the Keywords,Operators,Comments 
//Data Types,Specifiers,Functions ,Loops ,Conditional Statements and Libraries .   
#include "lex.h"
int main()
{
    fstream newfile;
    string line;
    int n = 1;
    newfile.open("test3.txt", ios::in);       //rename the testcase files here test files are test1 test2 and test3
    if (newfile.is_open())
    {
        while (getline(newfile, line))
        {
            isCheck(line, n);
            n++;
        }
        newfile.close();
    }
    system("cls");
    cout<<"\t\t\t\tLexical Analyzer"<<endl;
   print_results();
    return 0 ;
}
