/*
GeeksforGeeks - find if an expression has duplicate parenthesis
ques:-
Given a balanced expression, find if it contains duplicate parenthesis or not. A set of parenthesis are duplicate if the same subexpression is surrounded by multiple parenthesis.

Examples:

Below expressions have duplicate parenthesis - 
((a+b)+((c+d)))
The subexpression "c+d" is surrounded by two
pairs of brackets.

(((a+(b)))+(c+d))
The subexpression "a+(b)" is surrounded by two 
pairs of brackets.

(((a+(b))+c+d))
The whole expression is surrounded by two 
pairs of brackets.

Below expressions don't have any duplicate parenthesis -
((a+b)+(c+d)) 
No subsexpression is surrounded by duplicate
brackets.

((a+(b))+(c+d))
No subsexpression is surrounded by duplicate
brackets.
*/

bool findDuplicateparenthesis(string str)
{
    stack<char> st;
    for(auto c:str){
    	if(c=='(' || c!=')')
    	  st.push(c);
    	else if(c==')'){
    		int count = 0;
    		while(st.top()!='('){
    			count++;
    			st.pop();
			}
			if(count<1)
			 return false;
			 
			 st.pop();
		}
	}
	return true;
}
