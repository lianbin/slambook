#include "DBoW3/DBoW3.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <iostream>
#include <vector>
#include <string>

using namespace cv;
using namespace std;

/***************************************************
 * 本节演示了如何根据data/目录下的十张图训练字典
 * ************************************************/

int main( int argc, char** argv )
{
    // read the image 
    cout<<"reading images... "<<endl;
    vector<Mat> images; 
    for ( int i=0; i<10; i++ )
    {
        string path = "../data/"+to_string(i+1)+".png";
        images.push_back( imread(path) );
    }
    // detect ORB features
    cout<<"detecting ORB features ... "<<endl;
    //Ptr< Feature2D > detector = ORB::create();
    Ptr<FeatureDetector> detector = FeatureDetector::create("ORB");
    Ptr<DescriptorExtractor> descriptor = DescriptorExtractor::create("ORB");
    vector<Mat> descriptors;
    for ( Mat& image:images )
    {
        vector<KeyPoint> keypoints; 
        Mat descriptor_;
        //detector->detectAndCompute( image, Mat(), keypoints, descriptor );
			    //-- 第一步:检测 Oriented FAST 角点位置
	    detector->detect ( image,keypoints );

	    //-- 第二步:根据角点位置计算 BRIEF 描述子
	    descriptor->compute ( image, keypoints, descriptor_ );
        descriptors.push_back( descriptor_ );
    }
    
    // create vocabulary 
    cout<<"creating vocabulary ... "<<endl;
    DBoW3::Vocabulary vocab;
    vocab.create( descriptors );
    cout<<"vocabulary info: "<<vocab<<endl;
    vocab.save( "vocabulary.yml.gz" );
    cout<<"done"<<endl;
    
    return 0;
}