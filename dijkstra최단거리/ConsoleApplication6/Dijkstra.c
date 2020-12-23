#include <stdio.h>
#include <limits.h> // INT_MAX에 이용
#define true 1
#define false 0
#define MAX_VERTICES 8
#define INF 9000

int weight[MAX_VERTICES][MAX_VERTICES] =
{
	{ 0, 250, 1500, INF, INF, INF, INF, INF },
	{ INF, 0, 1000, 900, 1400, INF, INF, INF },
	{ INF, INF, 0, INF, INF, 1200, INF, INF },
	{ INF, INF, INF, 0, 1000, INF, INF, INF },
	{ INF, INF, INF, INF, 0, INF, 1700, INF },
	{ INF, INF, INF, INF, INF, 0, 1000, 800 },
	{ INF ,INF, INF, INF, INF, INF, INF,INF },
	{ INF, INF,INF, INF, INF,INF, 300, 0 },
};

int distance[MAX_VERTICES];
int found[MAX_VERTICES];
int arr[MAX_VERTICES];

int choose(int distance[], int n, int found[])
{
	int i, min,  minpos;
	min = INT_MAX;
	minpos = -1;

	for (i = 0; i < n; i++)
		if (distance[i] < min && !found[i])
		{
			min = distance[i];
			minpos = i;
		}

	return minpos;
}


void printSolution(int distance[], int n)
{
	printf("Vertex   Distance from Source\n");
	for (int i = 0; i < n; i++)
		printf("%d \t\t %d\n", i, distance[i]);
}


void shortest_path(int start, int n)
{
	int i, u, w;

	for (int i = 0; i < n; i++)
	{
		distance[i] = weight[start][i];
		found[i] = false;
	}

	found[start]=true;
	distance[start]=0;
	
	for (i = 0; i < n - 2; i++)
	{
		u = choose(distance, n, found);
		found[u] = true;
		for (w = 0; w < n; w++)
			if (!found[w])
				if(distance[u] + weight[u][w]<distance[w])
				distance[w] = distance[u] + weight[u][w];
		arr[i] = u;
		printSolution(distance, MAX_VERTICES);
	}
}

int main()
{
	shortest_path(0, MAX_VERTICES);
	
	printf("start : 보스턴->");
	for (int i = 0; i < MAX_VERTICES - 2; i++) {
		switch (arr[i])
		{
		case 1: printf("뉴욕->"); break;
		case 2: printf("시카고->"); break;
		case 3: printf("마이애미->"); break;
		case 4: printf("뉴올리언스->"); break;
		case 5: printf("덴버->"); break;
		case 6: printf("로스엔젤로스->"); break; 
		case 7: printf("샌프란시스코->"); break;
		}
	}
	printf("로스엔젤로스 : end\n");


	return 0;
}

