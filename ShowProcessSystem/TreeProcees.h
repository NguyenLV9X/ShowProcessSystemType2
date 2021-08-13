#include "Node.h"

class TreeProcees
{
private:
	CNode* pRoot;
public:
	void Append(stProcess data);
	void Show();
	CNode* find(DWORD id);
	TreeProcees();
};
