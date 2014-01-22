#include "Brain.h"

#include <string>
using namespace std;

void parseBF(BrainNodeProg* prog, string in);

int main()
{
	string s = "+++--+<%>>.<[+[[,,.-[<<>><-=+]+]-]],..-";
	BrainNodeProg p;
	parseBF(&p, s);
	return 0;
}

