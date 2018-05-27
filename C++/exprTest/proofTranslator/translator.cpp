#include <iostream>
#include <fstream>

using namespace std;

//general functions
int readFormula(istream&,string&);
int parseFormula(ofstream& instrm,const string& str, int start, int stop);
bool isLastFormula();
int matchEndParens(const string&,int);
void hereDocPreamble(ofstream&);
void removeWhiteSpace(string&);

//conditions to check for expression type
int isVariable(const string&);
int isConditional(const string&);
int isAnd(const string&);
int isOr(const string&);
int isNot(const string&);

//emitter functions for emitting and recursing
void twoplaceemit(ofstream&,const string&,int,int,const string&);
void oneplaceemit(ofstream&,const string&,int,int,const string&);

int main()
{
    bool last = false;
    ofstream outfile;
    string input = "";
    int i = 0;

    //open the output file
    outfile.open("output_heredoc.txt");

    //emit generic preamble code to here doc
    hereDocPreamble(outfile);

    //read parse and emit every premise
    //ask the user if they want to go to the conclusion each
    //iteration
    while (!last)
    {
        cout << "Please Enter a formula:" << endl;
        readFormula(cin,input);
        removeWhiteSpace(input);
        parseFormula(outfile,input,0,input.size());
        last = isLastFormula();
        //the menu uses different ending characters for premises and conclusions
        if (last)
        {
            cout << "FILE:\tq #conclusion follows" << endl;
            outfile << "\tq #conclusion follows" << endl << endl;
        }
        else
        {
            cout << "FILE:\tc #proposition " << i << endl;
            outfile << "\tc #proposition " << i << endl << endl;
        }
        i++;
    }

    //read in the conclusion parse and emit it to the file
    cout << "Please Enter a conclusion:" << endl;
    readFormula(cin,input);
    removeWhiteSpace(input);
    parseFormula(outfile,input,0,input.size());

    //generic ending code for the file
    cout << "FILE:ENDOFMESSAGE" << endl;
    outfile << "ENDOFMESSAGE" << endl;

    //we are done close the file and exit
    outfile.close();
    return 0;
}

//returns the position of amatching end paren given a string and
//the position of a starting paren
int matchEndParens(const string& str,int start)
{
    int nesting = 0;
    int ending = -1;
    for (unsigned int i = start; i < str.size(); i++)
    {
        if ( str[i]=='(')
        {
            nesting++;
        }
        else if ( str[i]==')')
        {
            nesting--;
        }
        if (nesting==0)
        {
            ending = i;
            break;
        }
    }
    return ending;
}

//get a formula from the user
int readFormula(istream& instrm,string& str)
{
    getline(instrm,str,'\n');
    return 0;
}

//takes a formula from the user outputs correct code to the file for the outermost
//expression type and then recurses on any subexpressions
int parseFormula(ofstream& fout,const string& str, int start, int stop)
{
    int oploc = -1;

    if (isVariable(str)!=-1)
    {
        cout << "FILE:\tu" << endl;
        fout << "\tu" << endl;
        cout << "FILE:\tv" << endl;
        fout << "\tv" << endl;
        cout << "FILE:\t" << str[0] << endl;
        fout << "\t" << str[0] << endl;
        return 1;
    }
    else if ((oploc = isNot(str))!=-1)
    {
        string sub = str.substr(1,str.size()-1);
        cout << "FILE:\tu" << endl;
        fout << "\tu" << endl;
        cout << "FILE:\tn" << endl;
        fout << "\tn" << endl;
        parseFormula(fout,sub,0,0);
        return 1;
    }
    else if ((oploc = isConditional(str))!=-1)
    {
        twoplaceemit(fout,str,start,oploc,"c");
        return 1;
    }
    else if ((oploc = isOr(str))!=-1)
    {
        oneplaceemit(fout,str,start,oploc,"o");
        return 1;
    }
    else if ((oploc = isAnd(str))!=-1)
    {
        oneplaceemit(fout,str,start,oploc,"a");
        return 1;
    }
    return 1;
}

//ask the user if this is the last formula returns true or false
bool isLastFormula()
{
    bool ret = false;
    string str = "";
    do
    {
        cout << "Premise or conclusion?(c/p)" << endl;
        getline(cin,str,'\n');
    } while(str[0]!='c'&&str[0]!='p'&&str[0]!='C'&&str[0]!='P');

    if (str=="c"||str=="C")ret=true;
    else ret = false;

    return ret;
}

//every heredoc starts the same way
void hereDocPreamble(ofstream& fout)
{
    cout << "FILE: ../main <<-ENDOFMESSAGE" << endl;
    fout << "../main <<-ENDOFMESSAGE" << endl;
    fout << "\tp #this program is always prove mode" << endl;
}
//identify if the formula is a variable return 1 if true -1 if false
int isVariable(const string& str)
{
    if (isalpha(str[0]) && isupper(str[0])) return 1;
    else return -1;
}
//identify if the formula is a conditional return the position of
//the '-' part of the conditional operator if true return -1 if false
int isConditional(const string& str)
{
    int retval = -1;
    int nesting = 0;
    int start = 0;
    for (unsigned int i = start; i < str.size()&&str[0]=='('; i++)
    {
        if(i==str.size())
        {
            i=-1;
            break;
        }
        if ( str[i]=='(') nesting++;
        if ( str[i]==')'&&i!=str.size()) nesting--;
        if (i<str.size() && str[i]== '-'&& nesting==1) retval = i;
    }
    return retval;
}
//identify if the formula is an and return the position of the & operator if true
//return -1 if false
int isAnd(const string& str)
{
    int retval = -1;
    int nesting = 0;
    int start = 0;
    for (unsigned int i = start; i < str.size()&&str[0]=='('; i++)
    {
        if(i==str.size())
        {
            i=-1;
            break;
        }
        if ( str[i]=='(') nesting++;
        if ( str[i]==')'&&i!=str.size()) nesting--;
        if (i<str.size() && str[i]== '&'&&nesting==1) retval = i;
    }
    return retval;
}
//identify if the formula is an or return the position of v operator if true
//return -1 if false
int isOr(const string& str)
{
    int retval = -1;
    int nesting = 0;
    int start = 0;
    for (unsigned int i = start; i < str.size()&&str[0]=='('; i++)
    {
        if(i==str.size())
        {
            i=-1;
            break;
        }
        if ( str[i]=='(') nesting++;
        if ( str[i]==')'&&i!=str.size()) nesting--;
        if (i<str.size() && str[i]== 'v'&& nesting==1) retval = i;
    }
    return retval;

}
//identify if the formula is a not expression return 1 if true return -1 if false
int isNot(const string& str)
{
    if (str[0] == '~') return 1;
    else return -1;
}
//remove any spaces from a given string
void removeWhiteSpace(string& str)
{
    for(unsigned int i = 0; i < str.size(); i++)
    {
        if(str[i]==' ')str.erase(i,1);
    }
}
//emit and recurse to parse any children formulas this version is for two character operators
void twoplaceemit(ofstream& fout,const string& str,int start,int oploc, const string& op)
{
    cout << "FILE:\tb" << endl;
    fout << "\tb" << endl;
    cout << "FILE:\t" << op << endl;
    fout << "\t" << op << endl;
    string sub;
    int lstart = 1;
    int lend = matchEndParens(str,lstart);

    if (lstart==lend)
    {
        sub = str.substr(lstart,oploc-lstart);
    }
    else
    {
        sub = str.substr(lstart,lend-lstart+1);
    }
    parseFormula(fout,sub,0,0);

    int rstart = oploc+2;
    int rend = matchEndParens(str,rstart);

    if (rstart==rend)
    {
        sub = str.substr(oploc+2,str.size()-oploc-3);
    }
    else
    {
        sub = str.substr(rstart,rend-rstart+1);
    }
    parseFormula(fout,sub,0,0);
}
//emit and recurse to parse any children formulas this version is for one character operators
void oneplaceemit(ofstream& fout,const string& str,int start,int oploc, const string& op)
{
    cout << "FILE:\tb" << endl;
    fout << "\tb" << endl;
    cout << "FILE:\t" << op << endl;
    fout << "\t" << op << endl;
    string sub;
    int lstart = 1;
    int lend = matchEndParens(str,lstart);

    if (lstart==lend)
    {
        sub = str.substr(lstart,oploc-1);
    }
    else
    {
        sub = str.substr(lstart,lend-lstart+1);
    }
    parseFormula(fout,sub,0,0);

    int rstart = oploc+1;
    int rend = matchEndParens(str,rstart);

    if (rstart==rend)
    {
        sub = str.substr(oploc+1,str.size()-oploc-2);
    }
    else
    {
        sub = str.substr(rstart,rend-rstart+1);
    }
    parseFormula(fout,sub,0,0);
}
