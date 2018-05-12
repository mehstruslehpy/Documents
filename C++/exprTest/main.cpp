//#include "boolexp.h"
//#include "context.h"
//#include "varexp.h"
//#include "notexp.h"
//#include "andexp.h"
#include "defs.h"

using namespace std;

BoolExp* buildExpr(BoolExp*);

int main()
{
    string input = "";
    Context context;
    BoolExp* current = nullptr;
    BoolExp* conclusion = nullptr;
    Prover proof;

    cout << "Building argument enter q to end:" << endl;
    while (input != "q")
    {
        current = buildExpr(current);
        proof.AddPremise(current, current->Type(), "given");
        proof.PrintPremises();
        cout << endl;
        cout << "Building argument enter q to end or c to continue:" << endl;
        cin >> input;
        cin.ignore(256,'\n');
    }
    proof.PrintPremises();

    cout << "Build your conclusion" << endl;
    conclusion = buildExpr(current);
    current = new NotExp(conclusion);
    proof.AddPremise(current, current->Type(), "~Conclusion");
    proof.PrintPremises();
    cout << endl;

    input = "";
    cout << "Beginning inference step enter q to quit:" << endl;
    for (int i = 0; input != "q" && !proof.FindContradiction() && proof.HighestAssumption() >= 0; i++)
    {
        proof.Infer(i%proof.PremiseCount());
        proof.PrintPremises();
        cout << "Continue inferences or quit?(c/q)" << endl;
        cin >> input;
        cin.ignore(256,'\n');
        proof.MakeAssumption();
    }
    proof.PrintPremises();
    cout << "Therefore " << conclusion->Name() << " is a valid conclusion" << endl;
    cout << "Program Ending" << endl;
    return 0;
}

BoolExp* buildExpr(BoolExp* current)
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
            return current;
        }
        if (input == "n")
        {
            cout << "Continuing to interior of negation: " << endl;
            BoolExp* temp;
            temp = buildExpr(current);
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
            temp1 = buildExpr(current);
            cout << "Building right side of And: " << endl;
            temp2 = buildExpr(current);
            current = new AndExp(temp1,temp2);
            return current;
        }
        if (input == "o")
        {
            BoolExp* temp1;
            BoolExp* temp2;
            cout << "Building left side of Or: " << endl;
            temp1 = buildExpr(current);
            cout << "Building right side of Or: " << endl;
            temp2 = buildExpr(current);
            current = new OrExp(temp1,temp2);
            return current;
        }
        if (input == "c")
        {
            BoolExp* temp1;
            BoolExp* temp2;
            cout << "Building left side of Conditional: " << endl;
            temp1 = buildExpr(current);
            cout << "Building right side of Conditional: " << endl;
            temp2 = buildExpr(current);
            current = new CondExp(temp1,temp2);
            return current;
        }

    }
    return nullptr;
}
