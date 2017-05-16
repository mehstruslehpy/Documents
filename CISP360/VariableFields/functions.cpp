#include "definitions.h"

///this makes things simpler
#define INT_BEFORE_DBL args.find("int") < args.find("double")
#define INT_BEFORE_CHAR args.find("int") < args.find("char")

#define DBL_BEFORE_CHAR args.find("double") < args.find("char")
#define DBL_BEFORE_INT args.find("double") < args.find("int")

#define CHAR_BEFORE_INT args.find("char") < args.find("int")
#define CHAR_BEFORE_DBL args.find("char") < args.find("double")

///just a local function
void stackInt(string,string&);
void stackDouble(string,string&);
void stackChar(string,string&);
///compile a library via calls to system()
void dumbFunction()
{
    ///this string will compile an executable
    ///-if you don't specify -lstd++ std::cout and more is undefined
    ///string command = "gcc -Wall -Wextra -Werror ./temp_src.cpp -lstdc++";

    ///this string will compile a library..
    ///this command seems to work, and when I compare the format of the file created
    ///it is very similar to other DLL's scattered throughout my hdd..
    ///I really do not know a ton of stuff about libraries other than that they can be dynamic or static
    ///string command = "gcc -Wall -Wextra -shared ./temp_src.cpp -lstdc++ -o temp_lib.dll";

    string command = "gcc -Wall -Wextra -shared ";
    string funcName = "";
    string source = "";
    string retType = "";
    string args = "";
    string prologCode = "";
    string sum = "";
    ofstream temp;
    int typeFlag = 0;

    ///generate the actual compilation command and output files
    cout << "Enter a name for your function: " << endl;
    cout << "(the files generated: yourfunction.cpp and yourfunction.dll)" << endl;
    getline(cin, funcName);
    command += (funcName + ".cpp -lstdc++ -o " + funcName + ".dll");

    ///we only have three kinds of types that our function pointers can currently return
    cout << command << endl;
    cout << "Specify your function return type: (int, double or char )" << endl;
    getline(cin,retType);

    ///convenience stuff
    sum = "#include <iostream>\nusing namespace std;\n";
    ///this will be for output later
    if (retType == "int")
    {
        sum += "int " + funcName + "()\n{\n";
    }
    else if (retType == "double")
    {
        typeFlag = FLOAT;
        sum += "double " + funcName + "()\n{\n";
    }
    else if (retType == "char")
    {
        typeFlag = TEXT;
        sum += "\nchar " + funcName + "()\n{\n";
    }

    ///we want to generate a function prolog now
    cout << "Specify a list of argument types and variable names:" << endl
         <<"int name1 int name2 ... char name3 etc:" << endl;
    cout << "you can only use char, int, or double currently" << endl;
    getline(cin, args);
    genFunctionProlog(args,prologCode);

    cout << "Type your source code then type :q on a new line to compile and quit" << endl;
    cout << "COMPILATION: " + command << endl << endl;
    cout << sum+prologCode;

    ///This is basically an IDE for people who hate themselves..
    do
    {
        sum += source + '\n';
        getline(cin, source);
    }
    while(source != ":q");

    cout << source << endl;
    cout << retType << endl;
    cout << args << endl;

    temp.open(funcName+".cpp");
    temp << sum;
    temp.close();

    system(command.c_str());

}

void genFunctionProlog(string args, string& retString)
{
    int intSpec = 0;    ///how many ints did the user want?
    int dblSpec = 0;    ///how many doubles did the user want?
    int charSpec = 0;   ///how many chars did the user want?
    int pos = 0;        ///where are we in the argument string?

    ///keep checking for if "int" "double" or "char" are still in the string
    while (args.find("int") != string::npos || args.find("double") != string::npos || args.find("char") != string::npos)
    {
        if (INT_BEFORE_CHAR && INT_BEFORE_DBL)
        {
            ///find each instance of "int," and count them up
            pos = args.find("int");
            while (args.find("int")!=string::npos)
            {
                intSpec++;  ///increment the count
                args.erase(pos,4);  ///erase the type info
                if (args.find(" ") == string::npos)
                {
                    pos = args.length();
                }
                else
                {
                    pos = args.find(" ");
                }
                stackInt(args.substr(0,pos),retString);
                args.erase(0,pos+1);  ///erase
                pos = args.find("int");

            }

            ///generate part of the prolog pertaining to ints here
            cout << "fizz " << intSpec<< endl;
            ///the name leftover should be the subtring from one whitespace to the next

        }
        else if (DBL_BEFORE_CHAR && DBL_BEFORE_INT)
        {
            ///find each instance of "double," and count them up
            pos = args.find("double");
            while (args.find("double")!=string::npos)
            {
                dblSpec++;  ///increment the count
                args.erase(pos,7);  ///erase the type info
                if (args.find(" ") == string::npos)
                {
                    pos = args.length();
                }
                else
                {
                    pos = args.find(" ");
                }
                stackDouble(args.substr(0,pos),retString);
                args.erase(0,pos+1);  ///erase
                pos = args.find("double");
            }
            ///generate the bit of the prolog dealing with doubles here
            cout << "bang " << dblSpec << endl;
        }
        else if (CHAR_BEFORE_DBL && CHAR_BEFORE_INT)
        {
            ///find each instance of "char," and count them up
            pos = args.find("char");
            while (args.find("char")!=string::npos)
            {
                charSpec++;  ///increment the count
                args.erase(pos,5);  ///erase the type info
                if (args.find(" ") == string::npos)
                {
                    pos = args.length();
                }
                else
                {
                    pos = args.find(" ");
                }
                stackChar(args.substr(0,pos),retString);
                args.erase(0,pos+1);  ///erase
                pos = args.find("char");
            }

            ///generate the bit of the prolog dealing with doubles here
            cout << "buzz " << charSpec << endl;
        }
    }
}

///http://wiki.osdev.org/Inline_Assembly
///https://www.codeproject.com/articles/15971/using-inline-assembly-in-c-c
///here is the actual code generation for an integer
void stackInt(string varName,string& prologCode)
{
    ///cout << "Int inline asm:" << endl;
    prologCode += ("int " + varName + " = 0;\n" ); ///init stmt
    prologCode += "asm (\"popl %%eax;\"\n \"movl %%eax, %0;\"\n"; ///the next couple lines
    prologCode += ":\"=r\"(" + varName + ")\n";     ///specify output to inline assembler
    prologCode += ":\"%eax\"\n";    ///specify clobbered register to inline asm
    prologCode += ");\n";
    ///cout << prologCode;
}
void stackDouble(string varName,string& prologCode)
{
    ///cout << "Double inline asm:" << endl;
    prologCode += ("double " + varName + " = 0;\n" ); ///init stmt
    prologCode += "asm (\"popl %%eax;\"\n \"movl %%eax, %0;\"\n"; ///the next couple lines
    prologCode += ":\"=r\"(" + varName + ")\n";     ///specify output to inline assembler
    prologCode += ":\"%eax\"\n";    ///specify clobbered register to inline asm
    prologCode += ");\n";
    ///cout << prologCode;

}
void stackChar(string varName,string& prologCode)
{
    ///cout << "Char inline asm:" << endl;
    prologCode += ("char " + varName + " = 0;\n" ); ///init stmt
    prologCode += "asm (\"popl %%eax;\"\n \"movl %%eax, %0;\"\n"; ///the next couple lines
    prologCode += ":\"=r\"(" + varName + ")\n";     ///specify output to inline assembler
    prologCode += ":\"%eax\"\n";    ///specify clobbered register to inline asm
    prologCode += ");\n";
    ///cout << prologCode;
}
///this is the inline assembler code to read from the stack into an int called b
//int b = 0;
//asm ("popl %%eax;"
//     "movl %%eax, %0;"
//     :"=r"(b)        /* output */
//     :               /* no input */
//     :"%eax"         /* clobbered register */
//     );
//     cout << "b::" << b;
