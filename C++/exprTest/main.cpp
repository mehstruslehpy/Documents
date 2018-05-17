#include "defs.h"
#include <math.h>
#include <algorithm>

using namespace std;

BoolExp* buildExpr(BoolExp*,Context&);
bool testEveryPermutation(vector<bool>&,Prover&,Context&,int,int);
int prover();
int calculator();

int main()
{
    string choice = "";
    cout << "Calculate or Prove?(c/p):" << endl;
    cin >> choice;
    cin.ignore(256,'\n');
    if (choice == "c")
        calculator();
    if (choice == "p")
        prover();
    return 0;
}

int prover()
{
    string input = "";
    Context context;
    BoolExp* current = nullptr;
    BoolExp* conclusion = nullptr;
    Prover proof;
    int premisecount = 0;
    int conclusionindex = 0;
    bool counterarg = false;

    cout << "Building argument enter q to end:" << endl;
    while (input != "q")
    {
        current = buildExpr(current,context);
        proof.AddPremise(current, current->Type(), "given");
        proof.PrintPremises();
        cout << endl;
        cout << "Building argument enter q to end or c to continue:" << endl;
        cin >> input;
        cin.ignore(256,'\n');
        premisecount++;
        conclusionindex++;
    }
    proof.PrintPremises();

    cout << "Build your conclusion" << endl;
    conclusion = buildExpr(current,context);
    current = new NotExp(conclusion);
    proof.AddPremise(current, current->Type(), "~ of the conclusion");
    proof.PrintPremises();
    cout << endl;

    input = "";
    cout << "Beginning inference step enter q to quit:" << endl;
    for (int i = 0; input != "q"; i++)
    {
        cout << "Iteration: " << i << endl;
        proof.FindContradiction();
        cout << "Continue inferences or quit?(c/q)" << endl;
        cin >> input;
        cin.ignore(256,'\n');
        if (!(i%50)&&i!=0)proof.MakeAssumption();
        proof.Infer(i%proof.PremiseCount());
        cout << "Assumptions: " << proof.HighestAssumption() << endl;
        cout << "Premises: "<< proof.PremiseCount() << endl;
        proof.FindContradiction();
        //proof.PrintPremises();
        //if(!(i%1)&&i!=0)
        if(!(i%100)&&i!=0)
        {
            vector<bool> truthvec(context.VarCount(),false);
            counterarg = testEveryPermutation(truthvec,
                                              proof,
                                              context,
                                              premisecount,
                                              conclusionindex);
        }
        if (proof.HighestAssumption()==0||counterarg) break;
    }
    if(!counterarg)
    {
        proof.PrintPremises();
        cout << "Therefore " << conclusion->Name() << " is a valid conclusion." << endl;
        cout << "Program Ending" << endl;
    }
    else
    {
        cout << "The conclusion is invalid, because the above counterargument can make all"
             << " the premises true \nand the negation of the conclusion true too, which makes"
             << " the intended conclusion false."
             << endl;
    }
    return 0;
}

int calculator()
{
    string input = "";
    Context context;
    BoolExp* current = nullptr;
    Prover proof;

    cout << "Building argument enter q to end:" << endl;
    while (input != "q")
    {
        current = buildExpr(current,context);
        proof.AddPremise(current, current->Type(), "given");
        proof.PrintPremises();
        cout << endl;
        cout << "Building argument enter q to end or c to continue:" << endl;
        cin >> input;
        cin.ignore(256,'\n');
    }
    proof.PrintPremises();
    //assign values here
    cout << "Beginning variable assignment step:" << endl;
    context.AssignValues();
    cout << "Beginning calculation step enter q to quit:" << endl;
    for (int i = 0; i < proof.PremiseCount(); i++)
    {
        cout << proof.PremiseName(i) << " = " << proof.Evaluate(i,context) << endl;
    }
    cout << "Program Ending" << endl;
    return 0;
}

BoolExp* buildExpr(BoolExp* current, Context& context)
{
    string input = "";
    do
    {
        cout << "Unary or Binary?(u/b): " << endl;
        cin >> input;
        cin.ignore(256,'\n');
    }
    while (input != "u" && input != "b");
    if(input == "u")
    {
        do
        {
            cout << "Variable or Negation?(v/n)" << endl;
            cin >> input;
            cin.ignore(256,'\n');
        }
        while (input != "v" && input != "n");

        if (input == "v")
        {
            cout << "Enter a variable name:" << endl;
            cin >> input;
            cin.ignore(256,'\n');
            current = new VarExp(input.c_str());
            context.DefaultAssign(input.c_str());
            return current;
        }
        if (input == "n")
        {
            cout << "Continuing to interior of negation: " << endl;
            BoolExp* temp;
            temp = buildExpr(current,context);
            current = new NotExp(temp);
            return current;
        }
    }
    if (input == "b")
    {
        do
        {
            cout << "And, Or, or Conditional?(a/o/c)" << endl;
            cin >> input;
            cin.ignore(256,'\n');
        }
        while (input != "a" && input != "o" && input != "c");

        if (input == "a")
        {
            BoolExp* temp1;
            BoolExp* temp2;
            cout << "Building left side of And: " << endl;
            temp1 = buildExpr(current,context);
            cout << "Building right side of And: " << endl;
            temp2 = buildExpr(current,context);
            current = new AndExp(temp1,temp2);
            return current;
        }
        if (input == "o")
        {
            BoolExp* temp1;
            BoolExp* temp2;
            cout << "Building left side of Or: " << endl;
            temp1 = buildExpr(current,context);
            cout << "Building right side of Or: " << endl;
            temp2 = buildExpr(current,context);
            current = new OrExp(temp1,temp2);
            return current;
        }
        if (input == "c")
        {
            BoolExp* temp1;
            BoolExp* temp2;
            cout << "Building left side of Conditional: " << endl;
            temp1 = buildExpr(current,context);
            cout << "Building right side of Conditional: " << endl;
            temp2 = buildExpr(current,context);
            current = new CondExp(temp1,temp2);
            return current;
        }

    }
    return nullptr;
}

bool testEveryPermutation(vector<bool>& myvec,Prover& proof, Context& context,int premises,int conclusion)
{
    cout << "Checking if the argument is invalid" << endl;
    bool premchk = true;
    bool concchk = true;
    bool counterarg = false;
    sort(myvec.begin(),myvec.end());

    for (unsigned i=0; i<=myvec.size(); i++)
    {
        for(unsigned k=0; k<myvec.size(); k++)myvec[k]=0;
        for(unsigned k=0; k<i; k++)myvec[k]=1;

        sort(myvec.begin(),myvec.end());
        do
        {
            context.AssignCombination(myvec);
            premchk = true;
            for(int i=0; i < premises; i++)
            {
                if (!proof.Evaluate(i,context)) premchk = false;
            }
            concchk=proof.Evaluate(conclusion,context);
            if (premchk&&concchk)
            {
                cout << endl;
                cout << "Counter-argument:" << endl;
                context.DumpContext();
                cout << endl;
                cout << "Evaluation:" << endl;
                for(int i=0; i<premises+1; i++)
                {
                    cout << proof.PremiseName(i) << "="<<proof.Evaluate(i,context)<<endl;
                }
                counterarg = true;
                cout << endl;
            }

        }
        while(next_permutation(myvec.begin(),myvec.end()));
    }
    return counterarg;
}

