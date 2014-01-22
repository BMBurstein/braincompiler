#pragma once

#include <string>
#include <list>

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
typedef std::list<BrainNode*> NodeContainer;
typedef NodeContainer::iterator NodeItr;
typedef NodeContainer::const_iterator NodeItrC;

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
	BrainNode(NodeOp op) : op(op) {}
	virtual void codeGen(Coder* c) const = 0;
	virtual ~BrainNode() = 0;

	BrainNodeBlock* parent;
	NodeOp op;
};
inline BrainNode::~BrainNode() {}

class BrainNodeBlock : public BrainNode
{
public:
	BrainNodeBlock() : BrainNode(LOOP) {}
	BrainNode* addNode(BrainNode* node) { node->parent = this; nodes.push_back(node); return node; }
	virtual ~BrainNodeBlock();

	NodeContainer nodes;
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
	BrainNodeOp(NodeOp op, int param) : BrainNode(op), param(param) {}
	virtual void codeGen(Coder* c) const { c->gen(this); }

	int param;
};

class BrainNodeInteract : public BrainNode
{
public:
	BrainNodeInteract(NodeOp op) : BrainNode(op) {}
	virtual void codeGen(Coder* c) const { c->gen(this); }
};

class BrainNodeLoop : public BrainNodeBlock
{
public:
	virtual void codeGen(Coder* c) const { c->gen(this); }
};