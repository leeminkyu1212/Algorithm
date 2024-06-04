#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector <char> output;
stack <int> Stack;
int n;
int main(void)
{
	int count = 1;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;

		while (count <=input)
		{
			Stack.push(count);
			count++;
			output.push_back('+');
		}
		if (Stack.top() == input)
		{
			Stack.pop();
			output.push_back('-');
		}
		else
		{
			cout << "NO";
			return 0;
		}
	}
	for (int i = 0; i < output.size(); i++)
		cout << output[i] << "\n";
}