#include "Brain.h"

#include <string>
using namespace std;

void parseBF(BrainProg* prog, string in)
{
	BrainNodeBlock* current = prog;
	BrainNodeLoop* loopNode;

	for(unsigned int i = 0; i < in.length(); i++)
	{
		switch(in[i])
		{
		case '+':
		case '-':
		case '<':
		case '>':
			current->addNode(new BrainNodeOp((NodeOp)in[i], 1));
			break;
		case '.':
		case ',':
			current->addNode(new BrainNodeInteract((NodeOp)in[i]));
			break;
		case '[':
			loopNode = new BrainNodeLoop();
			current->addNode(loopNode);
			current = loopNode;
			break;
		case ']':
			if(current->parent)
				current = current->parent;
			break;
		default:
			break;
		}
	}
}