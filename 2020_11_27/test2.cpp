#include <iostream>
using namespace std;

int cake[1000][1000] = {0};

int main()
{
	int W, H;
	cin >> W >> H;
	int res = 0;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (cake[i][j] == 0)
			{
				res++;
				if (i + 2 < H)
					cake[i + 2][j] = -1;
				if (j + 2 < W)
					cake[i][j + 2] = -1;
			}
		}
	}
	cout << res << endl;
	return 0;
}