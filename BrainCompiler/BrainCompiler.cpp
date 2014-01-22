#include "Brain.h"

#include <string>
using namespace std;

void parseBF(BrainProg* prog, string in);
void genC(BrainProg const& p);
void optimize(BrainNodeBlock* n);

int main()
{
	string s = "++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.";
	BrainProg p;
	parseBF(&p, s);
	optimize(&p);
	genC(p);
	return 0;
}
