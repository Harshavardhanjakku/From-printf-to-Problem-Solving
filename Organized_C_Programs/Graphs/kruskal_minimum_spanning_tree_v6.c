#include <stdio.h>
#include <limits.h>

#define MAX 100
int parent[MAX];

int find(int i) {

	while (parent[i] != i)
		i = parent[i];
	return i;
}

void unionSet(int i, int j) {

	int a = find(i);
	int b = find(j);
	parent[a] = b;
}

void kruskal(int n, int edges[][3], int e) {

	int minCost = 0;
	for (int i = 0; i < n; i++) {

		parent[i] = i;
	}
	for (int i = 0; i < e - 1; i++) {

		for (int j = 0; j < e - i - 1; j++) {

			if (edges[j][2] > edges[j + 1][2]) {

				int temp0 = edges[j][0];
				int temp1 = edges[j][1];
				int temp2 = edges[j][2];
				edges[j][0] = edges[j + 1][0];
				edges[j][1] = edges[j + 1][1];
				edges[j][2] = edges[j + 1][2];
				edges[j + 1][0] = temp0;
				edges[j + 1][1] = temp1;
				edges[j + 1][2] = temp2;
			}
		}
	}
	printf("\nEdges in the Minimum Spanning Tree:");
	for (int i = 0; i < e; i++) {

		int u = edges[i][0];
		int v = edges[i][1];
		int cost = edges[i][2];

		if (find(u) != find(v)) {

			unionSet(u, v);
			minCost += cost;
			printf("%d - %d : %d", u + 1, v + 1, cost);
		}
	}
	printf("\nMinimum cost to connect all warehouses: %d", minCost);
}

int main() {

	int n, e;

	printf("Enter the number of warehouses: ");
	scanf("%d", &n);

	printf("Enter the numb of routes (edges): ");
	scanf("%d", &e);

	int edges[MAX][3];
	printf("Enter the routes between warehouses (Format: u v cost):");
	for (int i = 0; i < e; i++) {

		scanf("%d %d %d", &edges[i][0], &edges[i][1], &edges[i][2]);
		edges[i][0]--;
		edges[i][1]--;
	}

	kruskal(n, edges, e);

	return 0;
}
