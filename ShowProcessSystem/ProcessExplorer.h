#include "TreeProcees.h"
#include <map>
#include <tlhelp32.h>

struct IsProcessObjectReturnID
{
	DWORD ID;
	explicit IsProcessObjectReturnID(DWORD paraID) : ID(paraID) {}

	bool operator()(const stProcess& process) const
	{
		return process.ID == ID;
	}
};

class ProcessExplorer 
{
private:
	TreeProcees Tree;
	map<DWORD, PROCESSENTRY32> mapProcesses;

	bool set_processes();
	void sort_processes();
	void show_processes();

public:
	void start();
	ProcessExplorer();
	~ProcessExplorer();
};