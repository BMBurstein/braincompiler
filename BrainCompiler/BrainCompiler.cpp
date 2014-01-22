#include "Brain.h"

#include <string>
using namespace std;

void parseBF(BrainProg* prog, string in);

int main()
{
	string s = "+++--+<%>>.<[+[[,,.-[<<>><-=+]+]-]],..-";
	BrainProg p;
	parseBF(&p, s);
	return 0;
}

