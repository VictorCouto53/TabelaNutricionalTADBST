#ifndef __BST_H__
#define __BST_H__

#include "NodeBST.h"

class BST
{
public:
	BST();
	~BST();

	NodeBST* GetRoot() const;

	bool IsEmpty() const;
	void Clear();

	int GetDegree() const;
	int GetHeight() const;

	std::string TraverseInOrder() const;
	std::string TraversePreOrder() const;
	std::string TraversePostOrder() const;
	std::string TraverseDepthOrder() const;
  std::string ShowNutrionalValues(NodeBST* node);

	NodeBST* FindMin() const;
	NodeBST* FindMax() const;

	NodeBST* Predecessor(std::string name) const;
	NodeBST* Successor(std::string name) const;

	NodeBST* SearchIterative(std::string name) const;
	NodeBST* Search(std::string name) const;
	NodeBST* InsertIterative(Alimentos* data);
	NodeBST* Insert(Alimentos* data);
	bool RemoveIterative(std::string name);
	void Remove(std::string name);

private:
	NodeBST* m_Root;

	void Destroy(NodeBST *node);
	
	int GetDegreeInternal(const NodeBST* node) const;

	std::string TraverseInOrderInternal(const NodeBST* node) const;
	std::string TraversePreOrderInternal(const NodeBST* node) const;
	std::string TraversePostOrderInternal(const NodeBST* node) const;
	std::string TraverseDepthOrderInternal(const NodeBST* node) const;

	NodeBST* FindMinInternal(NodeBST* node) const;
	NodeBST* FindMaxInternal(NodeBST* node) const;

	NodeBST* PredecessorInternal(NodeBST* node) const;
	NodeBST* SuccessorInternal(NodeBST* node) const;

	NodeBST* SearchInternal(NodeBST* node, std::string &name) const;
	NodeBST* InsertInternal(NodeBST* node, NodeBST* parent, Alimentos* data);
	NodeBST* RemoveInternal(NodeBST* node, std::string name);
	NodeBST* RemoveNode(NodeBST* node);
	void UpdateParentChild(NodeBST* parent, const NodeBST* child, NodeBST* newChild);
};

#endif
