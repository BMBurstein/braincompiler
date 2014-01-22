#include "Brain.h"

void BrainNodeProg::codeGen(Coder const& c)
{
}

BrainNodeProg::~BrainNodeProg()
{
	for(unsigned int i=0; i<nodes.size(); i++)
		delete nodes[i];
}

void BrainNodeOp::codeGen(Coder const& c)
{
}
void BrainNodeInteract::codeGen(Coder const& c)
{
}
void BrainNodeLoop::codeGen(Coder const& c)
{
}