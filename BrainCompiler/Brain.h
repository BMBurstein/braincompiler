#pragma once

#include <vector>

enum NodeOp
{
	ADD  = '+',
	SUB  = '-',
	MOVR = '<',
	MOVL = '>',
	IN   = ',',
	OUT  = '.',
	LOOP = '[',
};

class BrainNode;
class BrainNodeProg;
typedef std::vector<BrainNode* > NodeVec;

class Coder;

class BrainNode
{
public:
	BrainNodeProg* parent;
	virtual void codeGen(Coder const& c) = 0;
	virtual ~BrainNode() = 0;
};
inline BrainNode::~BrainNode() {}

class BrainNodeProg : public BrainNode
{
	NodeVec nodes;
public:
	BrainNodeProg() { parent = NULL; }
	virtual void codeGen(Coder const& c);
	BrainNode* addNode(BrainNode* node) { node->parent = this; nodes.push_back(node); return node; }
	~BrainNodeProg();
};

class BrainNodeOp : public BrainNode
{
	NodeOp op;
	int param;
public:
	BrainNodeOp(NodeOp op, int param) : op(op), param(param) {}
	virtual void codeGen(Coder const& c);
};

class BrainNodeInteract : public BrainNode
{
	NodeOp op;
public:
	BrainNodeInteract(NodeOp op) : op(op) {}
	virtual void codeGen(Coder const& c);
};

class BrainNodeLoop : public BrainNodeProg
{
public:
	virtual void codeGen(Coder const& c);
};