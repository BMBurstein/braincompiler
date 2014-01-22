#include "Brain.h"

#include <string>
using namespace std;

void parseBF(BrainNodeProg* prog, string in)
{
	BrainNodeProg* current = prog;
	BrainNodeLoop* loopNode;

	for(unsigned int i = 0; i < in.length(); i++)
	{
		switch(in[i])
		{
		case '+':
		case '-':
		case '<':
		case '>':
			prog->addNode(new BrainNodeOp((NodeOp)in[i], 1));
			break;
		case '.':
		case ',':
			prog->addNode(new BrainNodeInteract((NodeOp)in[i]));
			break;
		case '[':
			loopNode = new BrainNodeLoop();
			prog->addNode(loopNode);
			prog = loopNode;
			break;
		case ']':
			if(prog->parent)
				prog = prog->parent;
			break;
		default:
			break;
		}
	}
}