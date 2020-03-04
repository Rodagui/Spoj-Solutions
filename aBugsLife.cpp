/*BUGLIFE - A Bugâ��s Life*/
 
#include <bits/stdc++.h>
using namespace std;
 
bool bfs(const vector < vector <int> >& relation, vector <int>& status, int start);
 
int main(){
 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
 
	int cases;
	int edges;
	int bugs;
	int u, v;
 
	cin >> cases;
 
	int q = 1;
	while(cases--){
 
		cin >> bugs >> edges;
 
		vector < vector <int> > relation(bugs);
		vector <int> status(bugs, -1);
		bool ans = true;
 
		for (int i = 0; i < edges; ++i)
		{
 
			cin >> u >> v;
			u--;
			v--;
 
			relation[u].push_back(v);
			relation[v].push_back(u);

		}

		bool aux = true;

		for (int i = 0; i < bugs; ++i)
		{
			if (status[i] == -1)
			{
				aux = bfs(relation, status, i);

				ans =ans and aux;

				if (not ans)
					break;
			}

		}
 
		cout << "Scenario #" << q << ":\n";
		
		if(ans)
			cout << "No suspicious bugs found!\n";
			//cerr << "Se puede";
		else
			cout << "Suspicious bugs found!\n";
			//cerr << "No se puede";
	
 
		q++;
	}
	return 0;
}
 
bool bfs(const vector < vector <int> >& relation, vector <int>& status, int start){
 
	int currNode = start;
	int currState = 0;

	queue <int> cola;
 	bool ans = true;

	int newState;
	int newNode;

	if(status[currNode] != -1)
		currState = status[currNode];

	status[currNode] = currState;

	cola.push(currNode);

	while(!cola.empty()){

		currNode = cola.front();
		currState = status[currNode];
		cola.pop();

		if(currState == 1)
			newState = 0;
		else
			newState = 1;


		for (int i = 0; i < relation[currNode].size(); ++i)
		{
			newNode = relation[currNode][i];

		//	cerr << currNode << ' ' << currState << ' ' << newNode << ' ' << newState << "*\n";

			if(status[newNode] == -1){
				status[newNode] = newState;
				cola.push(newNode);
			}
			else{
				if(status[newNode] != newState){
					ans = false;
					break;
				}
			}

			if(ans == false)
				break;
		}

	}
 
	return ans;
} 