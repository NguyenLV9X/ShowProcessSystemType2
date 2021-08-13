#include "ProcessExplorer.h"

bool ProcessExplorer::set_processes()
{
	PROCESSENTRY32 pe32 = { sizeof(PROCESSENTRY32) };
	HANDLE hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	if (hProcessSnap == INVALID_HANDLE_VALUE)
		return false;

	if (!Process32First(hProcessSnap, &pe32))
	{
		CloseHandle(hProcessSnap);
		return false;
	}

	do
	{

		mapProcesses.insert(pair<DWORD, PROCESSENTRY32>(pe32.th32ProcessID, pe32));

	} while (Process32Next(hProcessSnap, &pe32));

	CloseHandle(hProcessSnap);
	return true;
}

void ProcessExplorer::sort_processes()
{
	for (auto it_map = mapProcesses.begin(); it_map != mapProcesses.end(); it_map++)
	{
		map< DWORD, PROCESSENTRY32>::iterator pParent = mapProcesses.find(it_map->second.th32ParentProcessID);
		if (pParent == mapProcesses.end() || it_map->second.th32ParentProcessID == 0 && it_map->first != 0)
		{
			stProcess stParent = { it_map->first, it_map->second.th32ParentProcessID, it_map->second.szExeFile };
			Tree.Append(stParent);
		}
	}

	for (auto it_map = mapProcesses.begin(); it_map != mapProcesses.end(); it_map++)
	{
		CNode* pPr = Tree.find(it_map->first);
		if (pPr != NULL)
		{
			continue;
		}

		CNode* pParent = Tree.find(it_map->second.th32ParentProcessID);
			
		if (pParent != NULL)
		{
				
			stProcess stPr = { it_map->first, it_map->second.th32ParentProcessID, it_map->second.szExeFile };
			Tree.Append(stPr);
			mapProcesses.erase(it_map);
			it_map = mapProcesses.begin();
		}
	}
}

void ProcessExplorer::show_processes()
{
	Tree.Show();
}

void ProcessExplorer::start()
{
	if (!set_processes())
		return;

	sort_processes();
	show_processes();

}

ProcessExplorer::ProcessExplorer()
{
}

ProcessExplorer::~ProcessExplorer()
{
}
