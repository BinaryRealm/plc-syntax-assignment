//<ifstmt> -> if ‘(‘ <expr> ’)’ <statement> [else <statement>]
void ifstmt(void) {
 if (nextToken != IF_CODE)
 	error();
 else {
	lex();
 	if (nextToken != LEFT_PAREN)
 		error();
 	else {
 		lex();
 		expr();
 		if (nextToken != RIGHT_PAREN)
 			error();
 		else {
 			lex();
		 	statement();
 			if (nextToken == ELSE_CODE) {
 				lex();
 				statement();
 			}
 		}
 	}
 }
}

//<whilestmt> -> while ‘(‘ <expr> ‘)’  <statement>
void whilestmt(void) {
    if (nextToken != WHILE_CODE)
        error();
    else {
        lex();
        if (nextToken != LEFT_PAREN)
            error();
        else {
            lex();
            expr();
            if (nextToken != RIGHT_PAREN)
                error();
            else {
                lex();
                statement();
            }
        }
    }
}

//<forstmt> -> for ‘(‘ [<expr>] ; [<intexpr>] ; [<expr>] ‘)’ <statement>
void forstmt(void) {
    if (nextToken != FOR_CODE)
        error();
    else {
        lex();
        if (nextToken != LEFT_PAREN) {
            error();
        }
        else { //(
            lex();
            if (nextToken != SEMICOLON) { //(e
                expr();
                if (nextToken != SEMICOLON) {
                    error();
                }
                else {
                    lex();
                    if (nextToken != SEMICOLON) { //(e;e
                        intexpr();
                        if (nextToken != SEMICOLON)
                        {
                            error()
                        }
                        else
                        {
                            lex();
                            if (nextToken != RIGHT_PAREN) {//(e;e;e
                                expr();
                                if (nextToken != RIGHT_PAREN) {
                                    error();
                                }
                                else {//(e;e;e)
                                    lex();
                                    statement();
                                }
                            }
                            else {//(e;e;)
                                lex();
                                statement();
                            }
                        }
                    }
                    else {//(e;;
                        lex();
                        if (nextToken != RIGHT_PAREN) {//(e;;e
                            expr();
                            if (nextToken != RIGHT_PAREN) {
                                error();
                             }
                            else {
                               lex();
                              statement();
                            }
                       }
                       else {//(e;;)
                          lex();
                          statement();
                       }
                    }
                }
            }
            else { //(;
                lex()
                if (nextToken != SEMICOLON) { //(;e
                    intexpr();
                    if (nextToken != SEMICOLON)
                    {
                        error()
                    }
                    else
                    {
                        lex();
                        if (nextToken != RIGHT_PAREN) {//(;e;e
                            expr();
                            if (nextToken != RIGHT_PAREN) {
                                error();
                            }
                            else {//(;e;e)
                                lex();
                                statement();
                            }
                        }
                        else {//(;e;)
                            lex();
                            statement();
                        }
                    }
                }
                else { //(;;
                    lex();
                    if (nextToken != RIGHT_PAREN) {//(;;e
                        expr();
                        if (nextToken != RIGHT_PAREN) {
                            error();
                        }
                        else {//(;;e)
                            lex();
                            statement();
                        }
                    }
                    else {//(;;)
                        if (nextToken != RIGHT_PAREN) {
                            error();
                        }
                        else {
                            lex();
                            statement();
                        }
                    }
                }
            }
        }
    }
}