#include <bits/stdc++.h>

using namespace std;

int main()
{
	map<string, string> M = 
	{
	{"brasil"              ,"Feliz Natal!"},
	{"alemanha"            ,"Frohliche Weihnachten!"},
	{"austria"             ,"Frohe Weihnacht!"},
	{"coreia"              ,"Chuk Sung Tan!"},
	{"espanha"             ,"Feliz Navidad!"},
	{"grecia"              ,"Kala Christougena!"},
	{"estados-unidos"      ,"Merry Christmas!"},
	{"inglaterra"          ,"Merry Christmas!"},
	{"australia"           ,"Merry Christmas!"},
	{"portugal"            ,"Feliz Natal!"},
	{"suecia"              ,"God Jul!"},
	{"turquia"             ,"Mutlu Noeller"},
	{"argentina"           ,"Feliz Navidad!"},
	{"chile"               ,"Feliz Navidad!"},
	{"mexico"              ,"Feliz Navidad!"},
	{"antardida"           ,"Merry Christmas!"},
	{"canada"              ,"Merry Christmas!"},
	{"irlanda"             ,"Nollaig Shona Dhuit!"},
	{"belgica"             ,"Zalig Kerstfeest!"},
	{"italia"              ,"Buon Natale!"},
	{"libia"               ,"Buon Natale!"},
	{"siria"               ,"Milad Mubarak!"},
	{"marrocos"            ,"Milad Mubarak!"},
	{"japao"               ,"Merii Kurisumasu!"}};

	string request;

	while (cin >> request)
	{
		if (M.find(request) != M.end())
			cout << M[request] << endl;
		else
			cout << "--- NOT FOUND ---" << endl;
	}

	return 0;
}
