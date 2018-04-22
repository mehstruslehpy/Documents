//load 72 to 62 into ram at addr 72 to 62
ldi a, 1
ldi b, 72
ldi c, 62

//enter ram writing loop
continue:
	st (b), b
	sub b, a
	cmp b, c
//if zero jump to done else continue
jzi done
jmpi continue
done:

//exit loop
halt
