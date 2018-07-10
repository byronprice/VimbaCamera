#!/bin/bash

echo "Eye-Tracking Camera Recorder"
echo " "

echo " "

echo "Enter save filename, followed by [ENTER]: "
read filename

cd /opt/Vimba_2_1/VimbaCPP/Examples/AsynchronousOpenCVRecorder/Qt/Build/Make/binary/x86_64bit/
sudo -E ./AsynchronousOpenCVRecorder

sleep 5
extension=".avi"
filename2=$filename$extension
folder="/home/jglab/EyeTrackingVids"
cp EyeTrackerVideo.avi $folder/$filename2
# extension="-FrameLog.bin";
# filename3=$filename$extension
# cp FrameLog.bin $folder/$filename3

