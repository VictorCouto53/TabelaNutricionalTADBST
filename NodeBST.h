#ifndef __NODE_BST_H__
#define __NODE_BST_H__

#include <string>
#include "Alimentos.h"

class NodeBST
{
public:
	NodeBST(Alimentos* data, NodeBST* parent = nullptr, NodeBST* left = nullptr, NodeBST* right = nullptr);
	~NodeBST();

	void CopyDataFrom(const NodeBST* node);
  
	Alimentos* GetData() const;
	void SetData(Alimentos* data);

  std::string GetName() const;

	NodeBST* GetParent() const;
	void SetParent(NodeBST* parent);

	NodeBST* GetLeft() const;
	void SetLeft(NodeBST* left);

	NodeBST* GetRight() const;
	void SetRight(NodeBST* right);

	bool IsRoot() const;
	bool IsLeaf() const;

	int GetDegree() const;
	int GetDepth() const;
	int GetHeight() const;

private:
	Alimentos* m_Data;
	
	NodeBST* m_Parent;
	NodeBST* m_Left;
	NodeBST* m_Right;

	int GetDepthInternal(const NodeBST* node) const;
	int GetHeightInternal(const NodeBST* node) const;
};

#endif
