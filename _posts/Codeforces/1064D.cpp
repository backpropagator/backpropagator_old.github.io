#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n, m, r, c, x, y, ans=0;
char maze[2002][2002];

bool isvalid(ll x, ll y){
	if(x >= 0 && x < m && y >= 0 && y < n)
		return true;
	else
		return false;
}

void backtrack(ll curx, ll cury, ll xleft, ll yleft){
	//if(curx )
	if(isvalid(curx,cury) && xleft >= 0 && yleft >= 0){
		ans++;
	}else{
		return;
	}

	if(curx-1 >= 0 && maze[curx-1][cury] != '*'){
		backtrack(curx-1, cury, xleft-1, yleft);
	}
	if(curx+1 < m && maze[curx+1][cury] != '*'){
		backtrack(curx+1, cury, xleft, yleft-1);
	}
	if(cury+1 < n && maze[curx][cury+1] != '*'){
		backtrack(curx, cury+1, xleft, yleft);
	}
	if(cury-1 >= 0 && maze[curx][cury-1] != '*'){
		backtrack(curx, cury-1, xleft, yleft);
	}
}

int main(){
	//int n, m, r, c, x, y;
	//ans = 0;
	cin>>n>>m>>r>>c>>x>>y;
	//char maze[n][m];
	char c;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin>>maze[i][j];
		}
	}
	backtrack(r-1,c-1,x,y);
	cout<<ans<<"\n";
}