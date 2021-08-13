#include <Windows.h>
#include <iostream>
using namespace std;

struct stProcess
{
	DWORD ID;
	DWORD IDparent;
	wstring wstrName;
};

class CNode
{
private:
	CNode* prootnext;
	CNode* pchild;
	stProcess data;
public:
	CNode* pRootNext();
	CNode* pChild();
	stProcess getData();
	CNode(stProcess aData, CNode* aRootNext, CNode* aChild);
	void setRootNext(CNode* aRootNext);
	void setChild(CNode* aChild);
	void setData(stProcess value);
};

