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
class BrainNodeBlock;
typedef std::vector<BrainNode* > NodeVec;

class Coder;

class BrainNode
{
public:
	BrainNodeBlock* parent;
	virtual void codeGen(Coder const& c) = 0;
	virtual ~BrainNode() = 0;
};
inline BrainNode::~BrainNode() {}

class BrainNodeBlock : public BrainNode
{
	NodeVec nodes;
public:
	virtual void codeGen(Coder const& c);
	BrainNode* addNode(BrainNode* node) { node->parent = this; nodes.push_back(node); return node; }
	~BrainNodeBlock();
};

class BrainProg : public BrainNodeBlock
{
public:
	BrainProg() { parent = NULL; }
	virtual void codeGen(Coder const& c);
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

class BrainNodeLoop : public BrainNodeBlock
{
public:
	virtual void codeGen(Coder const& c);
};

class Coder
{
public:
	virtual void gen(BrainProg);
	virtual void gen(BrainNodeOp);
	virtual void gen(BrainNodeInteract);
	virtual void gen(BrainNodeLoop);
	virtual ~Coder() {};
};