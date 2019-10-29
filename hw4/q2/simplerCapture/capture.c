/*
 *
 *  Example by Sam Siewert 
 *
 */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <string.h>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;


int main( int argc, char** argv )
{
    cvNamedWindow("Capture Example", CV_WINDOW_AUTOSIZE);
    CvCapture* capture = cvCreateCameraCapture(0);
    IplImage* frame;

    int numFrames = 120, numCaptured = 0;

    time_t start, end;

    time(&start);

    while(numCaptured < numFrames)
    {
      frame=cvQueryFrame(capture);
     
      if(!frame) break;
      else ++numCaptured;
      
      cvShowImage("Capture Example", frame);
    }

    time(&end);
    double seconds = difftime (end, start);
    double fps = numFrames/seconds;
    string fpsStr = to_string(fps);

    setWindowTitle("Capture Example", fpsStr);

    while(1)
    {
      char c = cvWaitKey(33);
      if( c == 27 ) break;
    }

    cvReleaseCapture(&capture);
    cvDestroyWindow("Capture Example");
    
};

