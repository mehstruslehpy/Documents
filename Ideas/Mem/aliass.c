#include <stdio.h>
	void use_ptr(void *p){
	printf("%s",*p);
	}
    #define x10(x) x x x x x x x x x x
    #define x100(x) x10(x10(x))
    #define x1000(x) x10(x100(x))
 
    volatile int qqz;
    void test(int n)
    {
      int a=0;
      x100( if (n==a++) { struct {int x;} *p[1000]; use_ptr(p); } else)
      qqz=a;
    }

int main() {
	test(100);
}
