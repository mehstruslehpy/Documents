//****************//
//NATURAL GRAMMARS//
//****************//

#include "mpc.h"

int main (int argc, char** argv) {

    mpc_parser_t* Adjective = mpc_new("adjective");
    mpc_parser_t* Noun      = mpc_new("noun");
    mpc_parser_t* Phrase    = mpc_new("phrase");
    mpc_parser_t* Doge      = mpc_new("Doge");

    mpca-lang(MPCA_LANG_DEFAULT,
            "                                                           
                adjective : \"wow\" | \"many\" |    \
                          | \"so\"  | \"such\";     \
                noun      : \"lisp\"| \"language\"  \ 
                          | \"book\"| \"build\";    \
                phrase    : <adjective> <noun>;     \ 
                doge      : <phrase>*;              \ 
            ",            
        Adjective, Noun, Phrase, Doge);

    mpc_cleanup(4, Adjective, Noun, Phrase, Doge);

    return 0;
}

/**********************************************/
/*adj    = wow OR many OR so OR such;         */
/*noun   = lisp OR languages OR book OR build */
/*phrase = adj + noun                         */
/*doge   = zero or more phrases               */
/**********************************************/
//The "\" operator can be used to continue a statement to another line...
//The "\" operator also specifies string literals: \" means litarally quote character rather than the C language end quote. usage: \char
