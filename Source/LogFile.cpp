#include <iostream>
#include <string>
#include <stdio.h>
#include <LogFile.h>

LogFile::LogFile() 
{
}

LogFile::~LogFile() 
{
}

void LogFile::OpenLogFile() {
	FrameLogFile = fopen("FrameLog.bin","wb");
}

void LogFile::SaveLogFile(uint8_t frameID) {
	fwrite(&frameID,sizeof(uint8_t),sizeof(frameID),FrameLogFile);
}