/*stolen from stack overflow*/


//given..
typedef struct {
        int size;
        int *p;
} mystruct;
mystuct *hello;

//access p[0] of structure hello (p[0] probably needs malloced..)
hello->p[0]

//access the address of member p[1] of structure hello
&hello->p[1]
