#pragma once
#ifndef BELLFORD_H
#define BELLFORD_H

#include <vector>

class Solution
{
public:
	void fillDistances(std::vector<std::vector<int>>& edges, int distances[], int n);
	int findTheCity(int n, std::vector<std::vector<int>>& edges, int distanceThreshold);
	void test();
};

#endif