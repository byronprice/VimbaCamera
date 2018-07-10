#ifndef LOGFILE_H
#define LOGFILE_H

#include <iostream>
#include <string>
#include <stdio.h>

class LogFile {
	public:
	LogFile();
	~LogFile();
	FILE* FrameLogFile;
	void OpenLogFile();
	void SaveLogFile(uint8_t frameID);
};
#endif