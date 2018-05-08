//#include "boolexp.h"
//#include "context.h"
//#include "varexp.h"
//#include "notexp.h"
//#include "andexp.h"
#include "defs.h"

using namespace std;

int main()
{
    Context context;
    VarExp* vptr = new VarExp("B");

    VarExp var1("A");
    BoolExp* bptr = vptr;
    NotExp not1(&var1);
    NotExp not2(bptr);
    AndExp avar1(vptr,&var1);
    AndExp avar2(&avar1,&var1);
    OrExp ovar1(&avar1,&avar2);
    OrExp ovar2(&avar1,&not2);
    NotExp not3(&ovar1);
    CondExp cvar1(&var1,vptr);
    CondExp cvar2(&var1,&not2);

    context.Assign(&var1,true);
    context.Assign(vptr,false);
    AndExp* vptr1 = new AndExp(&cvar1,&avar1);
    BoolExp* bptr1 = vptr1;

    Prover proof;
    proof.AddPremise(&var1, VAR_EXP);
    proof.AddPremise(&cvar1, COND_EXP);
    proof.AddPremise(&avar1, AND_EXP);

    cout << var1.Name()  << ": " << var1.Evaluate(context) << endl;
    cout << bptr->Name() << ": " << bptr->Evaluate(context) << endl;
    cout << not1.Name() << ": " << not1.Evaluate(context) << endl;
    cout << not2.Name() << ": " << not2.Evaluate(context) << endl;
    bptr = &not1;
    cout << bptr->Name() << ": " << bptr->Evaluate(context) << endl;
    bptr = &not2;
    cout << bptr->Name() << ": " << bptr->Evaluate(context) << endl;
    cout << avar1.Name() << ": " << avar1.Evaluate(context) << endl;
    cout << avar2.Name() << ": " << avar2.Evaluate(context) << endl;
    cout << ovar1.Name() << ": " << ovar1.Evaluate(context) << endl;
    cout << not3.Name() << ": " << not3.Evaluate(context) << endl;
    cout << ovar2.Name() << ": " << ovar2.Evaluate(context) << endl;
    bptr = &ovar1;
    cout << bptr->Name() << ": " << bptr->Evaluate(context) << endl;
    bptr = &ovar2;
    cout << bptr->Name() << ": " << bptr->Evaluate(context) << endl;
    cout << cvar1.Name() << ": " << cvar1.Evaluate(context) << endl;
    cout << cvar2.Name() << ": " << cvar2.Evaluate(context) << endl;
    cout << bptr1->Name() << ": " << bptr1->Evaluate(context) << endl;

    proof.PrintPremises();
    proof.Infer(2);
    //proof.Infer(1);
    proof.PrintPremises();

    delete vptr;
    delete vptr1;
    return 0;
}
