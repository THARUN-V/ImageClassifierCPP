#include <iostream>
#include <opencv2/features2d.hpp>
#include <opencv2/highgui.hpp>

int main()
{
    std::string Img1 = "../test_imgs/img1.png";
    std::string Img2 = "../test_imgs/img2.png";

    cv::Mat img1 = cv::imread(Img1);
    cv::Mat img2 = cv::imread(Img2);

    // cv::imshow("image1",img1);
    // cv::imshow("image2",img2);

    cv::Ptr<cv::ORB> orb = cv::ORB::create();

    std::vector<cv::KeyPoint> kp1,kp2;
    cv::Mat des1,des2;

    orb->detectAndCompute(img1,cv::noArray(),kp1,des1);
    orb->detectAndCompute(img2,cv::noArray(),kp2,des2);

    cv::Ptr<cv::DescriptorMatcher> matcher = cv::DescriptorMatcher::create(cv::DescriptorMatcher::BRUTEFORCE);
    std::vector<cv::DMatch> matches;

    matcher->match(des1,des2,matches);

    cv::Mat img_matches;
    cv::drawMatches(img1,kp1,img2,kp2,matches,img_matches);

    cv::imshow("Matches",img_matches);

    cv::waitKey(0);

    std::cout << "Hello OpenCV " << std::endl;
    return 0;
}