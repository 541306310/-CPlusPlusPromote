#pragma once
#include <iostream>
#include <memory>

template <typename T>
struct TNode;

template <typename T>
using TShardPtr = std::shared_ptr<TNode<T>>;

template <typename T>
using TWeakPtr = std::weak_ptr<TNode<T>>;

template<typename T>
struct TNode
{
	T Data;
	TShardPtr<T> Next;
	TShardPtr<T> Pre;
};

template<typename T>
class TList
{

public:
	TList()
	{
		Head = std::make_shared<TNode<T>>();
		len = 0;
		
	}

	void push(T Value)
	{
		TShardPtr<T> Thead = std::make_shared<TNode<T>>();
		Thead = Head;
		while (Thead->Next != nullptr)
		{
			Thead = Thead->Next;
		}
		TShardPtr<T> Node = std::make_shared<TNode<T>>();
		Node->Data = Value;
		Thead->Next = Node;
		Node->Pre = Thead;
	}

	bool Insert(T Pos,T Value)
	{
		TShardPtr<T> Thead = std::make_shared<TNode<T>>();
		Thead = Head;
		while (Thead->Next != nullptr)
		{
			Thead = Thead->Next;
			if (Thead->Data == Pos)
			{
				TShardPtr<T> Node = std::make_shared<TNode<T>>();
				Node->Data = Value;
				Thead->Next->Pre = Node;
				Node->Next = Thead->Next;
				Node->Pre = Thead;
				Thead->Next = Node;
				return true;
			}
		}
		return false;
	}

	bool Remove(T Pos)
	{
		TShardPtr<T> Thead = std::make_shared<TNode<T>>();
		Thead = Head;
		while (Thead->Next != nullptr)
		{
			Thead = Thead->Next;
			if (Thead->Data == Pos)
			{
				Thead->Pre->Next = Thead->Next;
				Thead->Next->Pre = Thead->Pre;
				return true;
			}
		}
		return false;
	
	}
	void Show()
	{
		TShardPtr<T> Node = std::make_shared<TNode<T>>();
		Node = Head;
		while (Node->Next != nullptr)
		{
			Node = Node->Next;
			std::cout << Node->Data << " ";
		}
		std::cout << std::endl;
	}
private:
	TShardPtr<T> Head;
	int len;
	
};