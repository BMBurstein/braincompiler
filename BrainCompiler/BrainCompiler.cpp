#include "Brain.h"

#include <string>
using namespace std;

void parseBF(BrainProg* prog, string in);
void genC(BrainProg const& p);

int main()
{
	string s = "++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.";
	BrainProg p;
	parseBF(&p, s);
	genC(p);
	return 0;
}
