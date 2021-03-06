#include <iostream>
#include <fstream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/stitching/stitcher.hpp"

using namespace std;
using namespace cv;

bool picture = false;
vector<Mat> imgs;
string result_name = "result.jpg";

int main(int argc, char* argv[])
{
	Mat img = imread("1.jpg");
	imgs.push_back(img);
	img = imread("2.jpg");
	imgs.push_back(img);
	img = imread("3.jpg");
	imgs.push_back(img);

	Mat pano;
	Stitcher stitcher = Stitcher::createDefault(picture);
	Stitcher::Status status = stitcher.stitch(imgs, pano);

	if (status != Stitcher::OK)
	{
		cout << int(status) << endl;
		return -1;
	}


	imwrite(result_name, pano);
	img = imread("result.jpg");
	imshow("result", img);
	waitKey(600000);

	return 0;
}