#include "GraphBellmanFord.h"
#include <iostream>

using namespace std;

const int UNDEFINED_DIST = 9999999;

void Solution::fillDistances(vector<vector<int>>& edges, int distances[], int n)
{
	for (int i = 1; i < n; i++)
	{
		for (auto edge : edges)
		{
			int start = edge[0];
			int end = edge[1];
			int weight = edge[2];

			if (distances[start] != UNDEFINED_DIST && distances[start] + weight < distances[end])
			{
				distances[end] = distances[start] + weight;
			}

			if (distances[end] != UNDEFINED_DIST && distances[end] + weight < distances[start])
			{
				distances[start] = distances[end] + weight;
			}
		}
	}
}

int Solution::findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
	int** shortestPathMatrix = new int*[n];
	for (int i = 0; i < n; i++)
	{
		shortestPathMatrix[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			shortestPathMatrix[i][j] = UNDEFINED_DIST;
		}
	}

	for (int i = 0; i < n; i++)
	{
		shortestPathMatrix[i][i] = 0;
	}

	for (auto edge : edges)
	{
		shortestPathMatrix[edge[0]][edge[1]] = edge[2];
		shortestPathMatrix[edge[1]][edge[0]] = edge[2];
	}

	for (int i = 0; i < n; i++)
	{
		fillDistances(edges, shortestPathMatrix[i], n);
	}

	int cityNumber = 0;
	int minCitiesReached = UNDEFINED_DIST;

	for (int i = 0; i < n; i++)
	{
		int citiesReached = 0;
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				continue;
			}

			if (shortestPathMatrix[i][j] <= distanceThreshold)
			{
				citiesReached += 1;
			}
		}

		if (citiesReached <= minCitiesReached)
		{
			minCitiesReached = citiesReached;
			cityNumber = i;
		}
	}

	return cityNumber;
}

void Solution::test()
{

	std::vector<std::vector<int>> edges{
		{3, 5, 9558},
		{1, 2, 1079},
		{1, 3, 8040},
		{0, 1, 9258},
		{4, 7, 7558},
		{5, 6, 8196},
		{3, 4, 7284},
		{1, 5, 6327},
		{0, 4, 5966},
		{3, 6, 8575},
		{2, 5, 8604},
		{1, 7, 7782},
		{4, 6, 2857},
		{3, 7, 2336},
		{0, 6, 6},
		{5, 7, 2870},
		{4, 5, 5055},
		{0, 7, 2904},
		{1, 6, 2458},
		{0, 5, 3399},
		{6, 7, 2202},
		{0, 2, 3996},
		{0, 3, 7495},
		{1, 4, 2262},
		{2, 6, 1390}
	};

	std::cout << findTheCity(8, edges, 7937);
}