#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	cv::Mat dstMat;
	cv::Mat srcMat = cv::imread("E:\\PIC\\lena.jpg",1);

	if (srcMat.empty())return -1;

	float angle = -10.0, scale = 1;

	cv::Point2f center(srcMat.cols*0.5, srcMat.rows*0.5);

	const cv::Mat affine_matrix = cv::getRotationMatrix2D(center, angle, scale);

	cv::warpAffine(srcMat, dstMat, affine_matrix, srcMat.size());

	imshow("src1", srcMat);
	imshow("src2", dstMat);
	waitKey();
}