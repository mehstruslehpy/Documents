//This code won't actually run I'm just writing it to teach myself 
//the procedure for infix to postfix translation
expr()
{
	term();
	rest();
}

rest()
{
	if (lookahead == '+') {
		match('+');
		term();
		putchar('+');
		rest();
	} else if (lookahead == '-')
		match('-');
		term();
		putchar('-');
		rest();
	} 
	else;
}

term()
{
	if (isdigit(lookahead)) {
		putchar(lookahead);
		match(lookahed);
	}
	else error();
}
