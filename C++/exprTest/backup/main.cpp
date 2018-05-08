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
	VarExp var1("A");
	VarExp* vptr = new VarExp("B");
	BoolExp* bptr = vptr;
	NotExp not1(&var1);
	NotExp not2(bptr);
	AndExp avar1(vptr,&var1);
	AndExp avar2(&avar1,&var1);
	OrExp ovar1(&avar1,&avar2);
	OrExp ovar2(&avar1,&not2);
	NotExp not3(&ovar1);
	
	context.Assign(&var1,true);
	context.Assign(vptr,false);

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
	
	delete vptr;
	return 0;
}
