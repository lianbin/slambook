#include <iostream>
#include <ctime>

using namespace std;

#include <Eigen/Core>
#include <Eigen/Dense>

#define MATRIX_SIZE 50

int main(int argc,char *argv[])
{
    Eigen::Matrix<float,2,3> matrix_23;
	Eigen::Vector3d v_3d;
	Eigen::Matrix3d matrix_33 = Eigen::Matrix3d::Zero();
	Eigen::Matrix<double,Eigen::Dynamic,Eigen::Dynamic> matrix_dynamic;
	Eigen::MatrixXd matrix_x;
	matrix_23<<1,2,3,4,5,6;
	
    cout<<"all elements"<<endl;
	cout<<matrix_23<<endl;
    cout<<"element num "<<endl;
	cout<<matrix_23.size()<<endl; //矩阵元素的个数
	
    cout<<"matrix rows  num "<<endl;
	cout<<matrix_23.rows()<<endl; //行数
	
    cout<<"matrix cols  num "<<endl;
	cout<<matrix_23.cols()<<endl; //列数

	
    cout<<"matrix fist col elements"<<endl;
	cout<<matrix_23.col(0)<<endl; //整列的值
	
    cout<<"matrix second col elements"<<endl;
	cout<<matrix_23.col(1)<<endl; //整列的值

	
    cout<<"matrix first row elements"<<endl;
	cout<<matrix_23.row(0)<<endl; //整列的值
	
    cout<<"add matrix second and first col elements"<<endl;
	cout<<matrix_23.col(0) + matrix_23.col(1)<<endl; //列数
    //使用（）访问矩阵的元素
	for (int i = 0; i < matrix_23.rows();i++)
		for (int j = 0; j < matrix_23.cols();j++)
		{
		    cout <<"matrix_32("<<j<<","<<i<<") = "<<matrix_23(i,j)<<std::endl;
		}

   //矩阵相乘
    v_3d<<1,2,3;
	Eigen::Matrix<double,2,1> result = matrix_23.cast<double>() * v_3d;
	cout<<result<<endl;


	matrix_33  = Eigen::Matrix3d::Random();
	
	cout<<"random matrix_33 " << matrix_33<<endl;

	
	cout<<matrix_33.transpose()<<endl; //转置
	cout<<matrix_33.sum()<<endl;       //元素的和
	cout<<matrix_33.trace()<<endl;     //矩阵的迹
	cout<<matrix_33 * 10<<endl;
	cout<<matrix_33.inverse()<<endl;
	cout<<matrix_33.determinant()<<endl;

    //利用Random函数产生任意大小/类型的矩阵
	Eigen::Matrix<float,MATRIX_SIZE,MATRIX_SIZE> matrix_nn;
	matrix_nn = Eigen::Matrix<float,MATRIX_SIZE,MATRIX_SIZE>::Random();

	//利用MatrixXd::Random产生任意大小的矩阵
	Eigen::Matrix<double,MATRIX_SIZE,MATRIX_SIZE> matrix_nx;
	matrix_nx = Eigen::MatrixXd::Random(MATRIX_SIZE,MATRIX_SIZE);

	//利用MatrixXd::Random产生任意大小的矩阵
	Eigen::Matrix<double,MATRIX_SIZE,1> nb;
	nb = Eigen::MatrixXd::Random(MATRIX_SIZE,1);
    
    Eigen::Matrix<double,MATRIX_SIZE,1> nx = matrix_nx.inverse() * nb;

	std::cout <<"nx "<<nx <<std::endl;

	std::cout <<"qr "<<matrix_nx.colPivHouseholderQr().solve(nb) <<std::endl;
	
}

