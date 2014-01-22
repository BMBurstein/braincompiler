#include "Brain.h"

BrainNodeBlock::~BrainNodeBlock()
{
	for(unsigned int i=0; i<nodes.size(); i++)
		delete nodes[i];
}