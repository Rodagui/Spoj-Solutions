/*streetParade*/

#include <bits/stdc++.h>

using namespace std;

int main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tam;

	while(cin>>tam and tam){

		vector <int> arr(tam);

		for (int i = 0; i < tam; ++i){
			cin >> arr[i];
		}

		stack <int> orignal;
		stack <int> lateral;
		stack <int> final;

		int num = 1;

		for (int i = tam - 1; i >= 0; --i)
		{
			orignal.push(arr[i]);
		}
		
		while( !orignal.empty()){
			
			if(orignal.top() == num){
				arr[num - 1] = num;
				orignal.pop();
				num++;
			}
			else{
				if(!lateral.empty()){
					if(lateral.top() == num){
						arr[num - 1] = num;
						lateral.pop();
						num++;
					}
					else{
						lateral.push(orignal.top());
						orignal.pop();
					}
				}
				else{
					lateral.push(orignal.top());
					orignal.pop();
				}
			}
		}

		//cout<<"num: "<<num<<'\n';

		while( !lateral.empty()){
			arr[num-1] = lateral.top();
			//cout<<lateral.top()<<' ';
			lateral.pop();
			num++;
		}

		bool answer = true;
		for (int i = 0; i < tam; ++i){
			if(arr[i] != i+1){
				answer = false;
				break;
			}
		}

		if(answer)
			cout<<"yes\n";
		else
			cout<<"no\n";


	}

	return 0;
}