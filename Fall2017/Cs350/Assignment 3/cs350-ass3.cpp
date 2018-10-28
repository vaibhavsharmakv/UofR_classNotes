void expr()
{
	printf("enter <expr>\n");
	term();

	while (nextToken==ADD_OP|| nextToken ==SUB_OP)
		{
			lex();
			term();
		}
	printf("Exit<expr>\n");
}
	
		