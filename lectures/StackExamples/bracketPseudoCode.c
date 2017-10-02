/**
 * This program receives () and [] statements in any order annd
 * determines if each '(' or '[' has a matching ')' or ']' pair.
 *
 * The logic is whenever  we see a ) or ] we check if the previous 
 * character was a [ or ( because we know those are closed matches.
 * When we move the internal () and [] statement eventually we should
 * be able to remove the outer () and [] unless the statement 
 * wasn't valid to begin with.
 */

int main( int argc, char ** argv )
{
	Stack * stack = malloc(sizeof(Stack));

	char ch;
	ch = getchar();
	while( ch != '\n' && ch != EOF )
	{
		char* stackTop = (char*)top(stack);
		if( ch == ']' && stackTop == '[')
		{
			// Pop off the '['
			pop(stack);
		}
		else if( ch == ')' && stackTop == '(')
		{
			// Pop off the '('
			pop(stack);
		}
		else if( ch == '(' || ch == '[') 
			push(stack,ch);
	}

	if( isEmpty(stack) )
		printf("Valid statement!\n");
	else
		pritnf("Statement was not valid!\n");
}	
