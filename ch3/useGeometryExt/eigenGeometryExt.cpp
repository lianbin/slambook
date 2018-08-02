#include <iostream>
#include <cmath>
using namespace std;

#include <Eigen/Core>
// Eigen 几何模块
#include <Eigen/Geometry>

/****************************
* 本程序演示了 Eigen 几何模块的使用方法
****************************/

int main ( int argc, char** argv )
{
    Eigen::Matrix3d rotation_matrix = Eigen::Matrix3d::Identity();
	Eigen::AngleAxisd rotation_vector (M_PI / 4,Eigen::Vector3d(0,0,1));
	cout.precision(3);
	cout <<rotation_vector.matrix() <<endl;
	rotation_matrix = rotation_vector.matrix();
	
	cout <<"matrix "<<"\n"<<rotation_matrix <<endl;
	
}
