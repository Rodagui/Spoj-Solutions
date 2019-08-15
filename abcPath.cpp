/*abdPath*/

#include <bits/stdc++.h>

using namespace std;

int n, m;

vector <vector <int> > visitados;

const int neighbors[8][2] = {
	{-1, 0}, 
	{0, -1},
	{0, 1},
	{1, 0},
	{-1, -1},
	{-1, 1},
	{1, -1},
	{1, 1}

};

bool isGood(int& x, int& y){
	return x >= 0 and x < n and y >= 0 and y < m;
}

int dfs(int x, int y, vector <vector <char> >& matrix){
	
	if(visitados[x][y] == -1){

		int maxLength = 0;

			for (int i = 0; i < 8; ++i)
			{
				int newX = x + neighbors[i][0];
				int newY = y + neighbors[i][1];

				if( isGood(newX, newY) and matrix[x][y] + 1 == matrix[newX][newY])
					maxLength = max(maxLength, dfs(newX, newY, matrix));

			}

		visitados[x][y] = 1 + maxLength;
	}

	return visitados[x][y];
}

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int k = 1;

	while(cin >> n >> m and n and m){

		cout << "Case " << k<<": ";
		k++;

		int maxAns = 0;

		vector <vector <char> > matrix(n, vector <char> (m));
		visitados = vector <vector <int> > (n, vector <int> (m, -1));

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				cin >> matrix[i][j];


		for (int i = 0; i < n ; ++i)
		{
			for (int j = 0; j < m ; ++j)
			{
				if(matrix[i][j] == 'A'){
					maxAns = max(maxAns, dfs(i, j, matrix));
				}

			}
		}

		cout << maxAns << '\n';

	}

	return 0;
}