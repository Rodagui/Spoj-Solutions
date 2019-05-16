/*ONP - Transform the Expression*/

#include <bits/stdc++.h>

using namespace std;

int precede(char op);

int main(){
	
	int cases;

	cin >> cases;

	while(cases--){

		string expression;

		cin >> expression;

		stack <char> operators;

		for (int i = 0; i < expression.size(); ++i){
		

			if(expression[i] == '(')
				operators.push('(');

			else if (expression[i] == ')'){

				while(!operators.empty()){
				
					if(operators.top() == '('){
						operators.pop();
						break;
					}
					cout<< operators.top();
					operators.pop();
				}
			}
			else if(isalpha(expression[i])){
				cout << expression[i];
			}
			else{ 

				int valorTop = 0;
				int valorNvo = precede(expression[i]);

				if(!operators.empty() and operators.top() != '(')
					valorTop = precede(operators.top());
				
				if(operators.empty() or operators.top()=='(' or valorNvo > valorTop)
					operators.push(expression[i]);
				
				else{

					while(!operators.empty() or valorTop < valorNvo){
						
						if(operators.top()== '('){
							operators.pop();
							break;
						}

						cout << operators.top();
						operators.pop();

						if(!operators.empty() and operators.top() != '(')
							valorTop = precede(operators.top());

					}

					operators.push(expression[i]);
				}

			}		

		}

		while(!operators.empty() ){
						
			cout << operators.top();
			operators.pop();

		}

		cout <<'\n';
	}

	return 0;
}

int precede(char op){

	if(op == '+')
		return 1;
	if(op == '-')
		return 2;
	if(op == '*')
		return 3;
	if(op == '/')
		return 4;
	if(op == '^')
		return 5;

	return 0;

}