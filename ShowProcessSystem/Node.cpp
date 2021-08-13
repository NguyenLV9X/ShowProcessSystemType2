#include "Node.h"

CNode* CNode::pRootNext()
{
    return prootnext;
}

CNode* CNode::pChild()
{
    return pchild;
}

stProcess CNode::getData()
{
    return data;
}

CNode::CNode(stProcess aData, CNode* aRootNext, CNode* aChild)
{
    data = aData;
    prootnext = aRootNext;
    pchild = aChild;
}

void CNode::setRootNext(CNode* aRootNext)
{
    prootnext = aRootNext;
}

void CNode::setChild(CNode* aChild)
{
    pchild = aChild;
}

void CNode::setData(stProcess value)
{
    data = value;
}
