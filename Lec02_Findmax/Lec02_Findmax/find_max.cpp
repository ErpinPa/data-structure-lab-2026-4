#include <cstdio>

int findArrayMax(int score[], int n)
{
	int tmp = score[0];
	for (int i = 1;i < n;i++){
		if (score[i] > tmp){
			tmp = score[i];
		}
	}
	return tmp;
}

void main()
{
	int score[4] = { 10, 20, 100, 50 };
	int out;
	out = findArrayMax(score, 4);
	printf("result = % d", out);
}