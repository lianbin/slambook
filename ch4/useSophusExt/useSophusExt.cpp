#include <iostream>
#include <cmath>
using namespace std; 

#include <Eigen/Core>
#include <Eigen/Geometry>

#include "sophus/so3.h"
#include "sophus/se3.h"

int main( int argc, char** argv )
{
    Eigen::Matrix3d R = Eigen::AngleAxisd(M_PI /2 ,Eigen::Vector3d(0,0,1)).toRotationMatrix();
	Sophus::SO3 SO3_R(R);
	Sophus::SO3 SO3_v(0,0,M_PI /2);//欧拉角初始化
	Eigen::Quaterniond q(R);
	Sophus::SO3 SO3_q(q);
	std::cout <<"from rotation "<<std::endl;
	std::cout <<SO3_R<<std::endl;
	std::cout <<"from euler "<<std::endl;
	std::cout <<SO3_v<<std::endl;
	std::cout <<"from quaternion "<<std::endl;
	std::cout <<SO3_q<<std::endl;

    Eigen::Vector3d  so3 = SO3_R.log();
	
	std::cout <<"from log  "<<std::endl;
	std::cout <<so3<<std::endl;

	Eigen::Matrix3d hat = Sophus::SO3::hat(so3);
	
	std::cout <<"from hat  "<<std::endl;
	
	std::cout <<hat<<std::endl;
	
	std::cout <<"from vee  "<<std::endl;
	 Eigen::Vector3d vee = Sophus::SO3::vee(hat);
	 std::cout <<vee<<std::endl;

	 Eigen::Vector3d upadte_so3 (1e-4,0,0);
	 
	 Sophus::SO3 SO3_updated  = Sophus::SO3::exp(upadte_so3) * SO3_R;//左扰动

	 std::cout <<"from exp updated	"<<std::endl;
	 
	 std::cout <<SO3_updated<<std::endl;



	 /*********************************************/
	 Eigen::Vector3d t(1,0,0);
	 Sophus::SE3 SE3_Rt(R,t);
	 Sophus::SE3 SE3_q(q,t);

	 std::cout <<" R 	"<<std::endl; 
	 std::cout <<R<<std::endl; 

     //输出的时候 旋转+平移。旋转是用so3来表示的。
     std::cout <<"SE3 from R T	"<<std::endl; 
	 std::cout <<SE3_Rt<<std::endl; 
     std::cout <<"SE3 from q t	"<<std::endl;
	 std::cout <<SE3_q<<std::endl; 
	 typedef Eigen::Matrix<double,6,1> Vector6d;
	 Vector6d se3 = SE3_Rt.log();
	 
     std::cout <<"SE3 from log	"<<std::endl;
     std::cout <<se3<<std::endl;
     std::cout <<"SE3 from hat	"<<std::endl; //向量到反对称矩阵
	 std::cout <<Sophus::SE3::hat(se3)<<std::endl;;
	 

     std::cout <<"SE3 from vee	"<<std::endl; //反对称到向量
	 std::cout <<Sophus::SE3::vee(Sophus::SE3::hat(se3))<<std::endl;;
	 
	 Vector6d se3_update;
     se3_update.setZero();
	 se3_update(0,0) = 1e-4d;
	 
     Sophus::SE3 se3_updated = Sophus::SE3::exp(se3_update) * SE3_Rt;
	 
	 
     std::cout <<"SE3 from updated	"<<se3_updated.matrix()<<std::endl; //反对称到向量
    return 0; 
}
