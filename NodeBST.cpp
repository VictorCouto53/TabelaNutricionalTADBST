#include "NodeBST.h"
#include "Utils.h"
#include "Alimentos.h"

NodeBST::NodeBST(Alimentos* data, NodeBST* parent, NodeBST* left, NodeBST* right)
	: m_Data(data)
	, m_Parent(parent)
	, m_Left(left)
	, m_Right(right)
{
}

NodeBST::~NodeBST()
{
	m_Parent = nullptr;
	m_Left = nullptr;
	m_Right = nullptr;
}

void NodeBST::CopyDataFrom(const NodeBST* node)
{
	m_Data = node->GetData();
}

Alimentos* NodeBST::GetData() const
{
	return m_Data;
}

void NodeBST::SetData(Alimentos* data)
{
	m_Data = data;
}

std::string NodeBST::GetName() const
{
  return GetData() -> Get_foodAndServing();
}

NodeBST* NodeBST::GetParent() const
{
	return m_Parent;
}

void NodeBST::SetParent(NodeBST* parent)
{
	m_Parent = parent;
}

NodeBST* NodeBST::GetLeft() const
{
	return m_Left;
}

void NodeBST::SetLeft(NodeBST* left)
{
	m_Left = left;
}

NodeBST* NodeBST::GetRight() const
{
	return m_Right;
}

void NodeBST::SetRight(NodeBST* right)
{
	m_Right = right;
}

bool NodeBST::IsRoot() const
{
	return m_Parent == nullptr;
}

bool NodeBST::IsLeaf() const
{
	return m_Left == nullptr && m_Right == nullptr;
}

int NodeBST::GetDegree() const
{
	int degree = 0;

	if (m_Left != nullptr)
		++degree;
	if (m_Right != nullptr)
		++degree;

	return degree;
}

int NodeBST::GetDepth() const
{
	return GetDepthInternal(this);
}

int NodeBST::GetDepthInternal(const NodeBST* node) const
{
	if (node->IsRoot())
	{
		return 0;
	}
	else
	{
		return 1 + GetDepthInternal(node->GetParent());
	}
}

int NodeBST::GetHeight() const
{
	return GetHeightInternal(this);
}

int NodeBST::GetHeightInternal(const NodeBST* node) const
{
	if (node == nullptr || node->IsLeaf())
	{
		return 0;
	}
	else
	{
		return 1 + Utils::Max(GetHeightInternal(node->GetLeft()), GetHeightInternal(node->GetRight()));
	}
}
