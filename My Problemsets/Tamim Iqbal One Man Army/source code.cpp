#include <bits/stdc++.h>

using namespace std;

int main()
{
	int over,ball,run,t=0;

	///freopen("input.txt","rt",stdin);
	///freopen("output.txt","wt",stdout);

	while(scanf("%d%d",&over,&ball)==2)
	{
            run=(((over-1)*(ball-1))*6)+((over-1)*3)+(ball*6);
		cout << "Case " << ++t << ": ";
		cout << run << endl;
	}
	return 0;
}
