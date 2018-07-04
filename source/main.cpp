#include <fstream>
#include <iostream>
#include <complex>
#include <memory>
#include <Eigen/Dense>
#include <Eigen/LU>

#include "cktcapacitor.h"
#include "cktinductor.h"
#include "cktresistor.h"
#include "cktvoltsource.h"

#include "circuitdesign.h"


using Eigen::MatrixXcd;
using Eigen::Matrix3f;
using namespace Eigen;

int main()
{
    CircuitDesign       myCircuit;

    std::ifstream infile( "netlist.txt" );
    myCircuit.ReadNetlist( infile );

    myCircuit.SolveCircuit( 1, 22000, 1 );




    MatrixXd G = MatrixXd::Random(100,100);
    MatrixXd b = MatrixXd::Random(100,50);
    MatrixXd t = G.fullPivLu().solve(b);
    double relative_error = (G*t - b).norm() / b.norm(); // norm() is L2 norm
    std::cout << "The relative error is:\n" << relative_error << std::endl;


}
