#include "NodeBST.h"
#include "BST.h"
#include "Utils.h"
#include <sstream>
#include <queue> // TraverseDepthOrderInternal


BST::BST()
	: m_Root(nullptr)
{
}

BST::~BST()
{
	Clear();
}

NodeBST* BST::GetRoot() const
{
	return m_Root;
}

bool BST::IsEmpty() const
{
	return m_Root == nullptr;
}

void BST::Clear()
{
	Destroy(m_Root);
	m_Root = nullptr;
}

void BST::Destroy(NodeBST* node)
{
	if (node != nullptr)
	{
		Destroy(node->GetLeft());
		Destroy(node->GetRight());

		delete node;
		node = nullptr;
	}
}

int BST::GetDegree() const
{
	return GetDegreeInternal(m_Root);
}

int BST::GetDegreeInternal(const NodeBST* node) const
{
	if (node != nullptr)
	{
		int left = GetDegreeInternal(node->GetLeft());
		int right = GetDegreeInternal(node->GetRight());
		return Utils::Max(node->GetDegree(), Utils::Max(left, right));
	}

	return 0;
}

int BST::GetHeight() const
{
	if (m_Root == nullptr)
		return -1;

	return m_Root->GetHeight();
}

std::string BST::TraverseInOrder() const
{
	return TraverseInOrderInternal(m_Root);
}

std::string BST::TraverseInOrderInternal(const NodeBST* node) const
{
	if (node != nullptr)
	{
		std::ostringstream oss;
		oss << TraverseInOrderInternal(node->GetLeft());
		oss << node->GetName() << " - ";
		oss << TraverseInOrderInternal(node->GetRight());
		return oss.str();
	}
	return "";
}

std::string BST::TraversePreOrder() const
{
	return TraversePreOrderInternal(m_Root);
}

std::string BST::TraversePreOrderInternal(const NodeBST* node) const
{
	if (node != nullptr)
	{
		std::ostringstream oss;
		oss << node->GetName() << " - ";
		oss << TraversePreOrderInternal(node->GetLeft());
		oss << TraversePreOrderInternal(node->GetRight());
		return oss.str();
	}

	return "";
}

std::string BST::TraversePostOrder() const
{
	return TraversePostOrderInternal(m_Root);
}

std::string BST::TraversePostOrderInternal(const NodeBST* node) const
{
	if (node != nullptr)
	{
		std::ostringstream oss;
		oss << TraversePostOrderInternal(node->GetLeft());
		oss << TraversePostOrderInternal(node->GetRight());
		oss << node->GetName() << " - ";
		return oss.str();
	}

	return "";
}

std::string BST::TraverseDepthOrder() const
{
	return TraverseDepthOrderInternal(m_Root);
}

std::string BST::TraverseDepthOrderInternal(const NodeBST* node) const
{
	if (node != nullptr)
	{
		std::ostringstream oss;
		std::queue<const NodeBST*> queue;

		queue.push(node);

		while (!queue.empty())
		{
			const NodeBST* n = queue.front();
			queue.pop();

			oss << n->GetName() << "(" << n->GetData() << ") ";

			if (n->GetLeft() != nullptr)
				queue.push(n->GetLeft());

			if (n->GetRight() != nullptr)
				queue.push(n->GetRight());
		}

		return oss.str();
	}

	return "";
}

NodeBST* BST::FindMin() const
{
	return FindMinInternal(m_Root);
}

NodeBST* BST::FindMinInternal(NodeBST* node) const
{
	if (node == nullptr)
		return nullptr;
	else if (node->GetLeft() == nullptr)
		return node;
	else
		return FindMinInternal(node->GetLeft());
}

NodeBST* BST::FindMax() const
{
	return FindMaxInternal(m_Root);
}

NodeBST* BST::FindMaxInternal(NodeBST* node) const
{
	if (node == nullptr)
		return nullptr;
	else if (node->GetRight() == nullptr)
		return node;
	else
		return FindMaxInternal(node->GetRight());
}

NodeBST* BST::Predecessor(std::string name) const
{
	NodeBST* node = SearchInternal(m_Root, name);
	return node == nullptr ? nullptr : PredecessorInternal(node);
}

NodeBST* BST::PredecessorInternal(NodeBST* node) const
{
	if (node->GetLeft() != nullptr)
	{
		return FindMaxInternal(node->GetLeft());
	}
	else
	{
		NodeBST* current = node;
		NodeBST* currentParent = node->GetParent();
		while (currentParent != nullptr && current == currentParent->GetLeft())
		{
			current = currentParent;
			currentParent = current->GetParent();
		}

		return currentParent;
	}
}

NodeBST* BST::Successor(std::string name) const
{
	NodeBST* node = SearchInternal(m_Root, name);
	return node == nullptr ? nullptr : SuccessorInternal(node);
}

NodeBST* BST::SuccessorInternal(NodeBST* node) const
{
	if (node->GetRight() != nullptr)
	{
		return FindMinInternal(node->GetRight());
	}
	else
	{
		NodeBST* current = node;
		NodeBST* currentParent = node->GetParent();
		while (currentParent != nullptr && current == currentParent->GetRight())
		{
			current = currentParent;
			currentParent = current->GetParent();
		}

		return currentParent;
	}
}

NodeBST* BST::SearchIterative(std::string name) const
{
	NodeBST* current = m_Root;
	while (current != nullptr && current->GetName() != name)
	{
		if (current->GetName() > name)
			current = current->GetLeft();
		else
			current = current->GetRight();
	}

	return current;
}

NodeBST* BST::Search(std::string name) const
{
	return SearchInternal(m_Root, name);
}

NodeBST* BST::SearchInternal(NodeBST* node, std::string &name) const
{
	if (node == nullptr)
		return nullptr;
	else if (node->GetName() == name)
		return node;
	else if (node->GetName() > name)
		return SearchInternal(node->GetLeft(), name);
	else
		return SearchInternal(node->GetRight(), name);
}

NodeBST* BST::InsertIterative(Alimentos* data)
{
	NodeBST* newNode = new NodeBST(data);
	if (IsEmpty())
	{
		m_Root = newNode;
		return m_Root;
	}
	else
	{
		NodeBST* current = m_Root;
		NodeBST* currentParent = nullptr;
		while (current != nullptr)
		{
			currentParent = current;

			if (current->GetName() == data -> Get_foodAndServing())
			{
				delete newNode;
				return nullptr;
			}

			if (current->GetName() > data -> Get_foodAndServing())
				current = current->GetLeft();
			else
				current = current->GetRight();
		}

		if (currentParent != nullptr)
		{
			if (currentParent->GetName() > data -> Get_foodAndServing())
				currentParent->SetLeft(newNode);
			else
				currentParent->SetRight(newNode);
		}
	}

	return newNode;
}

NodeBST* BST::Insert(Alimentos* data)
{
	if (IsEmpty())
	{
		m_Root = new NodeBST(data);
		return m_Root;
	}

	return InsertInternal(m_Root, nullptr, data);
}

NodeBST* BST::InsertInternal(NodeBST* node, NodeBST* parent, Alimentos* data)
{
  std::string name = data -> Get_foodAndServing();
	if (node == nullptr)
		node = new NodeBST(data, parent);
  else if (node->GetName() == name)
		return nullptr;
  else if (node->GetName() > name)
		node->SetLeft(InsertInternal(node->GetLeft(), node, data));
  else if (node->GetName() < name)
		node->SetRight(InsertInternal(node->GetRight(), node, data));
  
	return node;
}

bool BST::RemoveIterative(std::string name)
{
	NodeBST* current = m_Root;
	while (current != nullptr && current->GetName() != name)
	{
		if (current->GetName() > name)
			current = current->GetLeft();
		else
			current = current->GetRight();
	}

	if (current == nullptr)
		return false;

	RemoveNode(current);
	return true;
}

void BST::Remove(std::string name)
{
	RemoveInternal(m_Root, name);
}

NodeBST* BST::RemoveInternal(NodeBST* node, std::string name)
{
	if (node == nullptr)
		return nullptr;
	else if (node->GetName() == name)
		node = RemoveNode(node);
	else if (node->GetName() > name)
		node->SetLeft(RemoveInternal(node->GetLeft(), name));
	else
		node->SetRight(RemoveInternal(node->GetRight(), name));
	
	return node;
}

NodeBST* BST::RemoveNode(NodeBST* node)
{
	NodeBST* parent = node->GetParent();

	// Casse 1: O nó a ser removido é uma folha.
	if (node->IsLeaf())
	{
		UpdateParentChild(parent, node, nullptr);

		delete node;
		node = nullptr;
	}
	// Case 2: O nó a ser removido não possui filho ou sub-árvore a esquerda.
	else if (node->GetLeft() == nullptr)
	{
		NodeBST* newChild = node->GetRight();
		UpdateParentChild(parent, node, newChild);

		delete node;
		node = newChild;
	}
	// Case 3: O nó a ser removido não possui filhou ou sub-árvore a direita.
	else if (node->GetRight() == nullptr)
	{
		NodeBST* newChild = node->GetLeft();
		UpdateParentChild(parent, node, newChild);

		delete node;
		node = newChild;
	}
	// Case 4: O nó a ser removido não possui filho ou sub-árovre em ambos os lados.
	else
	{
		NodeBST* predecessor = Predecessor(node->GetName());

		node->CopyDataFrom(predecessor);
		node->SetLeft(RemoveInternal(node->GetLeft(), predecessor->GetName()));
	}

	return node;
}

void BST::UpdateParentChild(NodeBST* parent, const NodeBST* child, NodeBST* newChild)
{
	if (parent != nullptr)
	{
		if (parent->GetLeft() == child)
			parent->SetLeft(newChild);
		else
			parent->SetRight(newChild);
	}
	else
	{
		m_Root = newChild;
	}

	if (newChild != nullptr)
		newChild->SetParent(parent);
}
