#include <iostream>
#include <fstream>

using namespace std;

struct Link {
	int	nxt;
	int	len;
};

int i;

int findLen(Link links[], int i)
{
	links[i].len = 1;
	int j = links[i].nxt - 1;
	while (links[j].len == 0) {
		links[i].len++;
		j = links[j].nxt - 1;
	}
	return links[i].len;
}
int main()
{
	int	n;
	ifstream f("input.txt");
	f >> n;
	Link links[n];

	for ( i = 0; i < n; i++ ) {
		links[i].len = 0;
		f >> links[i].nxt;
	}
	int max = 0;
	for ( i = 0; i < n; i++ ) {
		links[i].len = findLen(links, i);
		if (max < links[i].len)
			max = links[i].len;
	}
	cout << max;
}
