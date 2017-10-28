#pragma once
#include<vector>

using namespace std;
struct	MinValData
{
	int i;
	int j;
	int value;
	MinValData():
		i(-1),
		j(-1),
		value(INT_MAX)
	{
	}
	static MinValData find_minimum(vector<MinValData>& data)
	{
		MinValData min;
		for (int i = 0; i < data.size(); ++i)
		{
			if (data[i].value<min.value)
			{
				min = data[i];
			}
		}
		return min;
	}
};