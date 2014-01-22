#include "Brain.h"

void optimize(BrainNodeBlock* n)
{
	if(n->nodes.size() < 2)
		return;

	NodeItr it1 = n->nodes.begin();
	if((*it1)->op == LOOP)
			optimize((BrainNodeLoop*)(*it1));

	NodeItr it2 = it1++;

	for(; it1!=n->nodes.end(); it2=it1++)
	{
		switch((*it1)->op)
		{
		case ADD:
		case SUB:
		case MOVR:
		case MOVL:
			if((*it1)->op == (*it2)->op)
			{
				((BrainNodeOp*)(*it1))->param += ((BrainNodeOp*)(*it2))->param;
				n->nodes.erase(it2);
			}
			break;
		case LOOP:
			optimize((BrainNodeLoop*)(*it1));
			break;
		}
	}
}