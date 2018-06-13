#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

#include "VimbaCPP/Include/VimbaCPP.h"
#include "Common/StreamSystemInfo.h"
#include "Common/ErrorCodeToMessage.h"
using namespace AVT::VmbAPI;
int main(int argc, char* argv[]) {
	VimbaSystem& sys = VimbaSystem::GetInstance();
	VmbVersionInfo_t version;
	VmbErrorType	err = sys.Startup();
	if ( VmbErrorSuccess == err ) {
		std::cout << "Vimba C++ Version: " << sys << "\n\n";
	}

	std::string strID;
	std::ostringstream ErrorStream;
	CameraPtrVector cameras;
	CameraPtr camera;
	if ( VmbErrorSuccess == err ) {
		err = sys.GetCameras(cameras);
		if ( VmbErrorSuccess == err ) {
			std::cout << "Cameras found: " << cameras.size() << "\n";
			
			err = (*cameras.begin())->GetID( strID );
			if ( VmbErrorSuccess != err ) {
				ErrorStream << "[Could not get Camera ID.]";
				strID = ErrorStream.str();
			} else {
				std::cout << "// Camera ID: " << strID << "\n\n";
				const char *ptrID = strID.c_str();
				err = sys.OpenCameraByID(ptrID,VmbAccessModeFull,camera);
				if ( VmbErrorSuccess == err ) {
					std::cout << "Camera Opened" << "\n";
				}

				// the " camera " object points to an opened camera
				err = camera->Close();
				if ( VmbErrorSuccess == err ) {
					std::cout << "Camera Closed " << std::endl;
				}
			}
		}
		sys.Shutdown();
	}
	
	// sys.Startup();

	// sys.Shutdown();
	return 0;
}
