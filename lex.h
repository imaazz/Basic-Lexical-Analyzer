#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <conio.h>
using namespace std;

string keywords_[50];   // Arrays to keep records
string libraries_[50];
string functions_[50];
string conditionals_[50];
string loops_[50];
string operators_[50];
string comments_[50];
string datatypes_[50];
string specifiers_[50];
 int a=0;
 int b=0;
 int c=0;
 int d=0;
 int e=0;
 int f=0;
 int g=0;
 int h=0;
 int l=0;
bool isaccess_specifier(string word)                 //function to check for access specifier
{
	string access[3]={"private:","protected:","public:"};
	 for (int i = 0; i < 3; ++i)
    {
        if (access[i] == word)
        {
			return true;
        }
    }

    return false;
	
}
bool isLibrary(string word)                             //function to check for libraries
{
	int flag=0;
    string library[1] = {"#include"};
    for (int i = 0; i < 1; ++i)
    {
        if (library[i] == word)
        {
			return true;
        }
    }

    return false;
}

bool isfunction(string word)              //function to check for functions
{

	for(int i=0;i<word.length();i++)
	{
		if(word[i]=='(')
		{
			i++;
			if(word[i]==')')
			{
				i++;
				if(word[i]!=';')
				{
					return true;
		    	}
			}
			else if (word[i]!=')')
			{
				return true;
			}
		}
		
	}
	return false;
}
bool iscondionalst(string word)                 //function to check for conditional statements
{

    int flag = 0;
    string conditions[4] = {"if", "else", "switch", "case"};

    for (int i = 0; i < 4; ++i)
    {
        if (conditions[i] == word)
        {
        	return true;
        }
    }

    return false;
}

bool isloop(string word)              //function to check for loops
{
	int flag=0;

    string loop[3] = {
        "do",
        "for",
        "while",
    };
    for (int i = 0; i < 3; ++i)
    {
        if (loop[i] == word)
        {
        	return true;
        }
    }

    return false;
}

bool iskeyword(string word)                   //function to check for keywords
{

    int flag = 0;
    string keyword[32] = {"auto", "break", "const", "continue", "default",
                           "enum", "extern", "goto",
                          "register", "return", "sizeof",
                          "static", "typedef", "union", "using", "namespace", "std;",
                          "unsigned", "void", "volatile"};

    for (int i = 0; i < 32; ++i)
    {
        if (keyword[i] == word)
        {
        	return true;
        }
    }

    return false;
}

bool isoperator(string word)                 //function to check for Operators
{
	int flag=0;

    string op[10] = {"+", "-", "*", "%", "=", "/"};

    for (int i = 0; i < 7; ++i)
    {
        if (op[i] == word)
        {
        	return true;
        }
    }

    return false;
}
bool iscomment(string word)           //function to check for comments
{
	int flag=0;

    string comment[10] = {"//", "/*"};

    for (int i = 0; i < 2; ++i)
    {
        if (comment[i] == word)
        {
        	return true;
        }
    }

    return false;
}

bool isdatatype(string word)                   //function to check for data types
{
	int flag=0;

    string datatype[32] = {
        "char",
        "double",
        "float",
        "int",
        "long",
        "short",
        "signed",
        "struct",
        "class"};
    for (int i = 0; i < 9; ++i)
    {
        if (datatype[i] == word)
        {
        	return true;
        }
    }

    return false;
}

void isCheck(string line, int n)            //This function will check the parsed word 
{

    cout << endl;

    istringstream ss(line);

    string word;

    while (ss >> word)          //parsing the lines into words
    {
    	
        if (isdatatype(word))
        {
        	int flag=0;
        	int k=0;
        	while(k<h){
        		if(datatypes_[k]==word)
        			flag=1;
        		k++;
			}
			if(flag==0){
        		datatypes_[h]=word;
            	h++;
			}
        	
        	
        
        }
        else if (isaccess_specifier(word))
        {
        	int flag=0;
        	int k=0;
        	while(k<c){
        		if(specifiers_[k]==line)
        			flag=1;
        		k++;
			}
			if(flag==0){
        		specifiers_[l]=line;
            	l++;
			}
         
		}
        else if (isLibrary(word))
        {
        	int flag=0;
        	int k=0;
        	while(k<c){
        		if(libraries_[k]==line)
        			flag=1;
        		k++;
			}
			if(flag==0){
        		libraries_[a]=line;
            	a++;
			}
          
        }
          else if (isloop(word))
        {
        	int flag=0;
        	int k=0;
        	while(k<d){
        		if(loops_[k]==word)
        			flag=1;
        		k++;
			}
			if(flag==0){
        		loops_[d]=word;
            	d++;
			}
        	
        }
            
        
        else if (iscondionalst(word))
        {
        	int flag=0;
        	int k=0;
        	while(k<c){
        		if(conditionals_[k]==word)
        			flag=1;
        		k++;
			}
			if(flag==0){
        		conditionals_[c]=word;
            	c++;
            	
			}
        	
        }
        
         else if (isfunction(word))
        {
        	int flag=0;
        	int i=0;
        	while(i<b){
        		
        		if(functions_[i]==word)
        			flag=1;
        			
        		i++;
			}
			if(flag==0){
        		functions_[b]=word;
            	b++;
			}
        	
            i=0;
//			cout<<"\t";
//		while(word[i]!='(')
//		{
//		cout<<word[i];
//		i++;
//	    }

        }
      
        else if (iscomment(word))
        {
        	int flag=0;
        	int k=0;
        	while(k<g){
        		if(comments_[k]==word)
        			flag=1;
        		k++;
			}
			if(flag==0){
        		comments_[g]=word;
            	g++;
            }
        	

        }
        else if (isoperator(word))
        {
        	int flag=0;
        	int i=0;
        	while(i<f){
        		if(operators_[i]==word)
        			flag=1;
        		i++;
			}
			if(flag==0){
        		operators_[f]=word;
            	f++;
			}
        	

        }

        
          else if (iskeyword(word))
        {
        	int flag=0;
        	int k=0;
        	while(k<e){
        		if(keywords_[k]==word)
        			flag=1;
        		k++;
			}
			if(flag==0){
        		keywords_[e]=word;
            	e++;
			}
        	

        }
    }
}
void print_results()               //printing the results
{
	 cout<<"\nKeywords     | ";
    for(int i=0;i<e;i++){
    	cout<<keywords_[i]<<" | ";
	}
	cout<<"\nOperators    | ";
    for(int i=0;i<f;i++){
    	cout<<operators_[i]<<"     | ";
	}
	cout<<"\nComments     | ";
    for(int i=0;i<g;i++){
    	cout<<comments_[i]<<" | ";
	}
	cout<<"\nData Types   | ";
    for(int i=0;i<h;i++){
    	cout<<datatypes_[i]<<" | ";
	}
		cout<<"\nSpecifiers   | ";
    for(int i=0;i<l;i++){
    	cout<<specifiers_[i]<<" | ";
	}
	cout<<"\nFunctions    | ";
    for(int i=0;i<b;i++){
    	int flag=1;
    	string tmp=functions_[i];
    	for(int k=0;k<functions_[i].length();k++)
    	{
    		
    		if(functions_[i][k]=='.')
    		{
			
    		flag=0;
    	
		}
	}
    	int j=0;
    
		while(tmp[j]!='('&&flag){
    		cout<<tmp[j];
    		j++;
		}
		if(flag)
		cout<<" | ";
	
	}
	cout<<"\nLoops        | ";
    for(int i=0;i<d;i++){
    	cout<<loops_[i];
		cout<<" | ";
	}
	cout<<"\nConditionals | ";
    for(int i=0;i<c;i++){
    	cout<<conditionals_[i];
		cout<<" | ";
	}
	cout<<"\nLibraries    | ";
    for(int i=0;i<a;i++){
    	cout<<libraries_[i]<<" | ";
	}
	
}

