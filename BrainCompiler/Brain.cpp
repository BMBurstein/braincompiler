#include "Brain.h"

BrainNodeBlock::~BrainNodeBlock()
{
	for(NodeItrC it=nodes.begin(); it!=nodes.end(); it++)
		delete *it;
}