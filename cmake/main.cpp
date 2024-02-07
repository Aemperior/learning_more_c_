#include <iostream>

#include <eigen3/Eigen/Dense> //NOTE: I had to change this line from "#include <Eigen/Dense>" to "#include <eigen3/Eigen/Dense>"

#include "my_lib.hpp"

int main() {

    std::cout << "Hello world!" << std::endl;
    std::cout << my_lib_function() << std::endl;

    Eigen::MatrixXd m(2,2);
    m(0,0) = 3;
    m(1,0) = 2.5;
    m(0,1) = -1;
    m(1,1) = m(1,0) + m(0,1);
    std::cout << m << std::endl;

    return 0;
}
