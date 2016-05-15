//*****************//
// CODING GRAMMARS //
//*****************//

#include "mpc.h"

int main (int argc, char** argv) {

    //build a parser named: "Adjective" to recognize descriptions
    mpc_parser_t* Adjective = mpc_or(4,
        mpc_sym("wow"), mpc_sym("many"),
        mpc_sym("so"),  mpc_sym("such")
    );

    //build a parser named: "Noun" to recognize things
    mpc_parser_t* Noun = mpc_or(5,
        mpc_sym("lisp"), mpc_sym("language"),
        mpc_sym("book"), mpc_sym("build"),
        mpc_sym("c")
    );
    
    //Creating our phrase parser to combine nouns and adjectives
    //the mpc_and function means one thing is required AND THEN another
    mpc_parser_t* Phrase = mpc_and(2, mpcf_strfold,
        Adjective, Noun, free);
    
    //...
    mpc_parser_t* Doge = mpc_many(mpcf_strfold, Phrase);

    /*DO SOME PARSING HERE*/
    
    mpc_delete(Doge);

    return 0;
}
