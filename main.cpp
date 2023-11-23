#include <iostream>
#include <fstream>

using namespace std;

void La(string x[],int len)
{
    bool identifier[len], variable[len], func[len],
    keyword[len], operatoR[len], punctuation[len];
    //identifier
    int c=0;
    string y;
    for(int i=0;i<len;i++)
    {
        y=x[i];
        for(int k=0;k<y.length();k++)
        {
            for(int j=65;j<=90;j++)
            {
                if((int)y[k] == j)
                {
                    c++;
                }
            }
            for(int m=97;m<=122;m++)
            {
                if((int)y[k] == m)
                {
                    c++;
                }
            }
         }
         if(c==y.length())
         {
             variable[i] = true;
             func[i] = false;
             identifier[i]= true;
         }
         else if(c==y.length()-2 && (int)y[y.length()-1] == 41 && (int)y[y.length()-2] == 40)
         {
             variable[i]=false;
             func[i] = true;
             identifier[i]= true;
         }
         else
         {
             func[i] = false;
             variable[i] = false;
             identifier[i]= false;
         }
         c=0;

         //keyword
          string s[]={"int","string","float","double","short","long",
         "char","bool","void","return","cout","cin","endl","for","while",
         "do","if","else","break","try","static","goto","class","struct","case"};

         int length = sizeof(s)/sizeof(s[0]);
         int l=0;
         for(int m=0;m<len;m++)
         {
             for(int n=0;n<length;n++)
             {
                 if(x[m]==s[n])
                 {
                     l++;
                 }
             }
             if(l>0)
             {
                keyword[m] = true;
                identifier[m] = false;
                variable[m] = false;
             }
             else
             {
                 keyword[m] = false;
             }
             l=0;
         }
     }

    //operator*
    string ope[12]={"+","-","*","/","=","==","<=",">=",">","<","%","!="};
    for(int i=0;i<len;i++)
    {
        for(int w=0;w<12;w++)
        {
            if(x[i]==ope[w])
            {
                operatoR[i]=true;
            }
        }
    }

    //punctuation
    string pun[8]={",",";","{","}","(",")","<<",">>"};
    for(int i=0;i<len;i++)
    {
        for(int p=0;p<8;p++)
        {
            if(x[i]==pun[p])
            {
                punctuation[i]=true;
            }
        }
    }

     for(int i=0;i<len;i++)
     {

         if(variable[i]==true && identifier[i]==true)
         {
             cout<<"["<<x[i]<<"] = It Is Identifier(Variable)"<<endl;
         }
         else if(func[i]==true && identifier[i]==true)
         {
             cout<<"["<<x[i]<<"] = It Is Identifier(Function)"<<endl;
         }
         else if(identifier[i]==false && keyword[i] == false && operatoR[i]==false && punctuation[i]==false)
         {
             cout<<"["<<x[i]<<"] = It Is Not Identifier"<<endl;
         }
         else if(keyword[i] == true)
         {
             cout<<"["<<x[i]<<"] = It Is Keyword"<<endl;
         }
         else if(operatoR[i] == true && punctuation[i] != true)
         {
             cout<<"["<<x[i]<<"] = It Is Operator"<<endl;
         }
         else if(punctuation[i] == true )
         {
             cout<<"["<<x[i]<<"] = It Is punctuation"<<endl;
         }
     }
}
int main()
{
    string x;
    ifstream MyReadFile("Expression.txt");
    getline(MyReadFile,x);
    cout<<"The String Is: "<<x<<endl;
    cout<<endl;
    MyReadFile.close();

    int c=1;
    for(int i=0;i<x.length();i++)
    {
        if((int)x[i]==32)
        {
            c++;
        }
    }
    string s[c];
    int index=0;
    for(int i=0;i<x.length();i++)
    {
        if ((int)x[i]==32)
        {
            index++;
        }
        else
        {
            s[index] = s[index] + x[i];
        }
    }
    La(s,c);
    return 0;
}
