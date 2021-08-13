#include "TreeProcees.h"
#include <stack>

void TreeProcees::Append(stProcess data)
{
	CNode* newNode = new CNode(data, NULL, NULL);
	CNode* pTemp = pRoot;
	if (pTemp == NULL)
	{
		pRoot = newNode;
		return;
	}
	else
	{
		stack<CNode*> stackNode;
		while (1)
		{
			DWORD idNode = pTemp->getData().ID;
			if (idNode == data.IDparent)
			{
				if (pTemp->pChild() == NULL)
				{
					pTemp->setChild(newNode);
					return;
				}
				else
				{
					pTemp = pTemp->pChild();
					while (pTemp->pRootNext() != NULL)
					{
						pTemp = pTemp->pRootNext();
					}
					pTemp->setRootNext(newNode);
					return;
				}

			}
			else
			{
				
				if (pTemp->pChild() != NULL)
				{
					stackNode.push(pTemp);
					pTemp = pTemp->pChild();
				}	
				else
				{
					if (pTemp->pRootNext() != NULL)
					{
						pTemp = pTemp->pRootNext();
					}
					else
					{
						do
						{
							bool empty = stackNode.empty();
							if (!empty)
							{
								pTemp = stackNode.top();
								stackNode.pop();
								pTemp = pTemp->pRootNext();
							}
							else
							{
								pTemp->setRootNext(newNode);
								return;
							}
						}while(pTemp == NULL);
					}
				}
			}
		}	
	}
}

void TreeProcees::Show()
{
	CNode* pTemp = pRoot;
	if (pTemp == NULL)
	{
		return;
	}
	else
	{	
		stack<CNode*> stackNode;
		while (1)
		{
			for(int i=0; i < stackNode.size() + 1; i++)
				std::cout << "|-";
			std::wstring a1(pTemp->getData().wstrName);
			std::string str(a1.begin(), a1.end());
			std::cout << " " << str << std::endl;

				if (pTemp->pChild() != NULL)
				{
					stackNode.push(pTemp);
					pTemp = pTemp->pChild();
				}
				else
				{
					if (pTemp->pRootNext() != NULL)
					{
						pTemp = pTemp->pRootNext();
					}
					else
					{
						do
						{
							bool empty = stackNode.empty();
							if (!empty)
							{
								pTemp = stackNode.top();
								stackNode.pop();
								pTemp = pTemp->pRootNext();
							}
							else
							{
								return;
							}
						} while (pTemp == NULL);
					}
				}
			
		}
	}
}

CNode* TreeProcees::find(DWORD id)
{
	CNode* pTemp = pRoot;
	if (pTemp == NULL)
		return NULL;
	else
	{
		stack<CNode*> stackNode;
		while (1)
		{
			DWORD idNode = pTemp->getData().ID;
			if (idNode == id)
			{
				return pTemp;
			}
			else
			{

				if (pTemp->pChild() != NULL)
				{
					stackNode.push(pTemp);
					pTemp = pTemp->pChild();
				}
				else
				{
					if (pTemp->pRootNext() != NULL)
					{
						pTemp = pTemp->pRootNext();
					}
					else
					{
						do 
						{
							bool empty = stackNode.empty();
							if (!empty)
							{
								pTemp = stackNode.top();
								stackNode.pop();
								pTemp = pTemp->pRootNext();
							}
							else
							{
								return NULL;
							}
						}while(pTemp == NULL);
					}
				}
			}
		}
	}
}

TreeProcees::TreeProcees()
{
	pRoot = NULL;
}
