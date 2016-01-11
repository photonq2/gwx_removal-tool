// gwx_removal-tool.cpp: start point
//

#include "gwx_removal-tool.h"

#include <iostream>
#include <cstring>

#include <Windows.h>

using namespace std;


int main()
{
	unsigned int option;
	cout << "Please, run with administrator privileges.\n ";
	while (1) {
		//Select OS menu.
		cout << "Select option\n";

		cout << "\n -----For Windows 7 ----------------------\n";
		
		cout << " 1. Launch KB3035583 update uninstaller. The GWX mainly update\n";
		cout << " 2. Launch KB2952664 update uninstaller. To be compatibible stuff\n";
		cout << " 3. Launch KB3021917 update uninstaller. This one detects software/hardware compatibility\n";
		cout << " 4. Launch KB2990214 update uninstaller. This one allows the OS to install the new OS\n";
		cout << "\n -----For Windows 8 and 8.1 ----------------------\n";
		cout << " 5. Launch KB3044374 update uninstaller. This one detects software/hardware compatibility\n";
		cout << " 6. Launch KB2976978 update uninstaller. This one allows the OS to install the new OS\n"; 
		cout << "\n\n";
		cout << "   7. Exit";
		
		cout << "\n\n";

		cin >> option;
		cout << "\n";
		while (option < 1 && option > 7) {
			cout << "Please, enter a valid option: ";
			cin >> option;
			cout << "\n";
		}
		
		switch (option)
		{
		case 1:
			wusa32_uninstall("3035583");
			break;
		case 2:
			wusa32_uninstall("2952664");
			break;
		case 3:
			wusa32_uninstall("3021917");
			break;
		case 4:
			wusa32_uninstall("2990214");
			break;
		case 5:
			wusa32_uninstall("3044374");
			break;
		case 6:
			wusa32_uninstall("2976978");
			break;
		case 7:
			exit(EXIT_SUCCESS);
			break;
		default:
			break;
		}


	}
    return EXIT_SUCCESS;
}

int wusa32_uninstall(char* kb_code) {
	PVOID OldValue = NULL;
		
	if (Wow64DisableWow64FsRedirection(&OldValue))
	{
		//  Anything in this block uses the system native files and not the WoW64 ones  
		// put native WoW64 code here

		cout <<"\n\n Launching KB:" <<kb_code<<" update uninstaller... \n\n";
		
		string cmd("\"wusa /uninstall /kb:"); 
		cmd += kb_code;						  
		cmd += "\"";						  
		system(cmd.c_str());

		//system("wusa /?"); // use this for testing

		//  Immediately re-enable redirection. Note that any resources
		//  associated with OldValue are cleaned up by this call.
		if (FALSE == Wow64RevertWow64FsRedirection(OldValue))
		{
			//  Failure to re-enable redirection should be considered
			//  a criticial failure and execution aborted.
			return -1;
		}
		else {
			return 0;
		}
		
	}
}
