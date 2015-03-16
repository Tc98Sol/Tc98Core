#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

namespace Tc98
{
	namespace Core
	{
		template<typename T>
		class Node
		{
		public:
			Node()
			{
				next = nullptr;
			}
			
			Node* next;
			T data;			
		};

		template<typename T>
		class LinkedList
		{
		public:
			LinkedList()
			{
				head = tail = nullptr;
			}
			
			void CreateNodes(unsigned int nodeCount, T defaultDataValue)
			{
				for(unsigned int i=0; i<nodeCount; ++i)
				{
					Node<T>* node = new Node<T>();
					node->data = defaultDataValue;
					//node->next = nullptr;
					PushBack(node);
				}
				return;
			}

			void PushBack(Node<T>* node)
			{
				if(IsEmpty())
				{
					head = node;
					head->next = nullptr;
					tail = head;
				}
				else
				{
					tail->next =  node;
					tail = node;
					//tail->next = nullptr;
				}
				return;
			}

			Node<T>* PopHead()
			{
				if(IsEmpty())
					return nullptr;
				
				Node<T>* tempNode = head;
				head = tempNode->next;
				return tempNode;
			}

			bool IsEmpty() const
			{
				return head == nullptr;
			}

			Node<T>* GetHead() const
			{
				return head;
			}

			Node<T>* GetTail() const
			{
				return tail;
			}
		
		private:
			Node<T> *head, *tail;
		};
	}
}

#endif
