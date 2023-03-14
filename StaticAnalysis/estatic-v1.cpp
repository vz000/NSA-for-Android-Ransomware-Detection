// estatic-v1.cpp : Defines the entry point for the application.
//

#include "estatic-v1.h"

using namespace std;

int main()
{
	std::vector<std::string> raw;
	StaticData staticData;
	raw = staticData.getPermissions();
	for (int i = 0; i < raw.size(); i++) {
		std::cout << raw[i] << '\n';
	}
	return 0;
}
