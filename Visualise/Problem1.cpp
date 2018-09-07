#include "opencv2/opencv.hpp"
#include <iostream>
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
 
using namespace std;
using namespace cv;

int iterations = 2;
int lower_area = 10000;
int upper_area = 200000;
int gray_low = 0;
int gray_high = 140;

int canny_threshold_high = 255;
int canny_threshold_low = 100;
int canny_kernel = 3;

int colors[5][2];


static void on_trackbar( int, void* )
{}

void createTrackbars()
{
    char trackbarWindowName[50] = "trackbars";
    namedWindow(trackbarWindowName,0);
    createTrackbar("Iterations", trackbarWindowName, &iterations, 10, on_trackbar);
    createTrackbar("Canny High", trackbarWindowName, &iterations, 10, on_trackbar);
    createTrackbar("Canny Low", trackbarWindowName, &canny_threshold_high, 10, on_trackbar);
    createTrackbar("Canny Threshold", trackbarWindowName, &canny_threshold_low, 10, on_trackbar);
    createTrackbar("Lower Area", trackbarWindowName, &lower_area, 1000000, on_trackbar);
    createTrackbar("Upper Area", trackbarWindowName, &upper_area, 1000000, on_trackbar);
}



int main(){
  VideoCapture cap("2.mp4"); 
    
  if(!cap.isOpened()){
    cout << "Error" << endl;
    return -1;
  }
     
  while(1){
 
    Mat src;
    cap >> src;
    if (src.empty())
    {
        cap.set(CV_CAP_PROP_POS_FRAMES, 0); //Set index to 0 (start frame)
        continue;
    }
 
    // Press  ESC on keyboard to exit
    char c=(char)waitKey(25);
    if(c==27)
      break;

    Mat frame;  
    Mat dst;
    Mat HSV;
    Mat threshold;
    int vertices;
    String str;
    double epsilon, x, y, ratio;
    int side1, side2;
    Moments moment;  
    
    cvtColor(src, frame, CV_RGB2GRAY);
    cvtColor(src, HSV, CV_RGB2HSV);
    blur(frame,frame, Size(3, 3), Point(-1,-1));
	//inRange(frame,Scalar(H_MIN,S_MIN,V_MIN),Scalar(H_MAX,S_MAX,V_MAX),threshold);    
	inRange(frame,gray_low, gray_high,threshold);        
    vector<vector<Point> > contours;
    vector<vector<Point> > approximation;
    vector<Vec4i> hierarchy;

    cv::Mat opening_closing_kernel = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(3,3), cv::Point(-1, -1));
    cv::morphologyEx(threshold, threshold, cv::MORPH_OPEN, opening_closing_kernel, cv::Point(-1, -1), iterations);
    cv::morphologyEx(threshold, threshold, cv::MORPH_CLOSE, opening_closing_kernel, cv::Point(  -1, -1), iterations+3); 
    Canny(threshold, threshold, canny_threshold_low, canny_threshold_high, canny_kernel);
    findContours(threshold, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0,0));
    findContours(threshold, approximation, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0,0));    
    createTrackbars();
    Size s = src.size();
    int color_r, color_g, color_b;
    int count;
    if(contours.size()>0)
    {
       Scalar color = Scalar(200,0,0);
       count = 0;
       for(int i = 0; i < contours.size(); i++)
       {
            if(contourArea(contours[i]) > lower_area && contourArea(contours[i]) < upper_area)
            {
                //cout<<"area"<<contourArea(contours[i])<<endl;
                //cout<<"contours size"<<contours.size();
                count++;
                double epsilon = 0.01*arcLength(contours[i], true);
                approxPolyDP(contours[i], approximation[i], epsilon, true);
                Rect boundRect = boundingRect(approximation[i]);
                drawContours(frame, contours, i, color, 2, 8, hierarchy, 0, Point());

                moment = moments(contours[i]);
                x = moment.m10 / moment.m00; //center of polygon
                y = moment.m01 / moment.m00;
                vertices = approximation[i].size();
                if(vertices == 3) str = "Triangle";
                if(vertices ==4) str = "Rectangle";
                if(vertices == 5) str = "Pentagon";
                if(vertices == 6) str = "Hexagon";
                if(vertices>7) str="Circle";
                putText(frame, str, Point(x,y), 1, 2, Scalar(255,0,0),2);
                            
                color_r = HSV.at<Vec3b>(Point(x, y))[0];
                color_g = HSV.at<Vec3b>(Point(x, y))[1];
                color_b = HSV.at<Vec3b>(Point(x, y))[2];              
                cout<<str << "\n" << color_r<< "\n" << color_g << "\n" <<color_b<<endl;

            }
      }
    }
    
    cout << count << endl ;
    imshow("Thresholded", threshold);
    
    imshow("Frame", frame);
  }
  
  cap.release();
  destroyAllWindows();
  return 0;
}
