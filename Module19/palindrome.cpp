#include <bits/stdc++.h>
using namespace std;

bool canFormPalindrome(string str)
{
	vector<char> list;

	for (int i = 0; i < str.length(); i++)
	{
		auto pos = find(list.begin(),
						list.end(), str[i]);
		if (pos != list.end()) {
			auto posi
				= find(list.begin(),
					list.end(), str[i]);
			list.erase(posi);
		}
		else
			list.push_back(str[i]);
	}

	if (str.length() % 2 == 0
			&& list.empty()
		|| (str.length() % 2 == 1
			&& list.size() == 1))
		return true;

	else
		return false;
}

int main()
{
    string str;
    cin>>str;
	if (canFormPalindrome(str))
		cout << ("YES") << endl;
	else
		cout << ("NO") << endl;
}
