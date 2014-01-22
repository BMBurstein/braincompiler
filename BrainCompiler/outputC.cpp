#include "Brain.h"

#include <fstream>
#include <string>
using namespace std;

class CoderC : public Coder
{
	ofstream f;
	string fileName;

	void gen(const BrainNodeBlock* n)
	{
		for(unsigned int i=0; i<n->nodes.size(); i++)
			n->nodes[i]->codeGen(this);
	}

public:
	CoderC(string fileName) : fileName(fileName) {}

	virtual void gen(const BrainProg* p)
	{
		f.open(fileName);

		f << "#include <stdio.h>\n";
		f << "char arr[30000];\n";
		f << "char *p = arr;\n";
		f << "int main() {\n";
		gen((BrainNodeBlock*)p);
		f << "return 0;\n";
		f << "}" << endl;

		f.close();
	}
	virtual void gen(const BrainNodeOp* n)
	{
		switch(n->op)
		{
		case ADD:
			f << "*p += " << n->param << ";\n"; break;
		case SUB:
			f << "*p -= " << n->param << ";\n"; break;
		case MOVR:
			f <<  "p += " << n->param << ";\n"; break;
		case MOVL:
			f <<  "p -= " << n->param << ";\n"; break;
		}
	}

	virtual void gen(const BrainNodeInteract* n)
	{
		switch(n->op)
		{
		case IN:
			f <<  "*p = getchar();\n"; break;
		case OUT:
			f << "putchar(*p);\n"; break;
		}
	}

	virtual void gen(const BrainNodeLoop* n)
	{
		f << "while(*p) {\n";
		gen((BrainNodeBlock*)n);
		f << "}\n";
	}

};

void genC(BrainProg const& p)
{
	CoderC c("bf.c");
	p.codeGen(&c);
}