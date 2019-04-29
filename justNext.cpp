#include <bits/stdc++.h>

using namespace std;

int main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int cases, tam;

	cin >> cases;

	while(cases--){
	
	cin >> tam; 

	vector <int> arr(tam);
	vector <int> aux;
	int pos, posElemMayor = 0, num = -1;

		for (int i = 0; i < tam; ++i){
			cin >> arr[i];
		}

		for (int i = tam - 1; i > 0 ; --i){

			if(arr[i-1] < arr[i]){
				pos = i - 1;
				aux.push_back(arr[i]);
				aux.push_back(arr[i-1]);
				num = arr[i - 1];
				break;
			}

			aux.push_back(arr[i]);	
		}

		if(num == -1)
			cout<<"-1\n";
		else{

			sort(aux.begin(), aux.end());

			vector<int>::iterator lower,upper; 
	    	//lower = lower_bound (aux.begin(), aux.end(), num);  
	    	upper = upper_bound (aux.begin(), aux.end(), num); 

	    	//posi1 = (lower - aux.begin());
	    	posElemMayor = (upper - aux.begin());



	    	arr[pos] = aux[posElemMayor];


			int j = 0;
			for (int i = pos + 1; i < tam ; ++i)
			{
				if(j == posElemMayor)
					j++;

				arr[i] = aux[j];
				j++;

			}

			for (int i = 0; i < tam; ++i){
				cout<<arr[i];
			}

			cout<<'\n';
			
		}

	}

	return 0;
}