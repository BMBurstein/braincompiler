#pragma once

#include <string>
#include <vector>

enum NodeOp
{
	ADD  = '+',
	SUB  = '-',
	MOVR = '>',
	MOVL = '<',
	IN   = ',',
	OUT  = '.',
	LOOP = '[',
};

class BrainNode;
class BrainProg;
class BrainNodeBlock;
class BrainNodeOp;
class BrainNodeInteract;
class BrainNodeLoop;
typedef std::vector<BrainNode*> NodeVec;

class Coder
{
public:
	virtual void gen(const BrainProg*) = 0;
	virtual void gen(const BrainNodeOp*) = 0;
	virtual void gen(const BrainNodeInteract*) = 0;
	virtual void gen(const BrainNodeLoop*) = 0;
	virtual ~Coder() {};
};

class BrainNode
{
public:
	BrainNodeBlock* parent;
	virtual void codeGen(Coder* c) const = 0;
	virtual ~BrainNode() = 0;
};
inline BrainNode::~BrainNode() {}

class BrainNodeBlock : public BrainNode
{
public:
	BrainNode* addNode(BrainNode* node) { node->parent = this; nodes.push_back(node); return node; }
	virtual ~BrainNodeBlock();

	NodeVec nodes;
};

class BrainProg : public BrainNodeBlock
{
public:
	BrainProg() { parent = NULL; }
	virtual void codeGen(Coder* c) const { c->gen(this); }
};

class BrainNodeOp : public BrainNode
{
public:
	BrainNodeOp(NodeOp op, int param) : op(op), param(param) {}
	virtual void codeGen(Coder* c) const { c->gen(this); }

	NodeOp op;
	int param;
};

class BrainNodeInteract : public BrainNode
{
public:
	BrainNodeInteract(NodeOp op) : op(op) {}
	virtual void codeGen(Coder* c) const { c->gen(this); }

	NodeOp op;
};

class BrainNodeLoop : public BrainNodeBlock
{
public:
	virtual void codeGen(Coder* c) const { c->gen(this); }
};