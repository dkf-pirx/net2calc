#include "circuitdesign.h"

#include <iostream>

#include <complex>
#include <Eigen/Dense>
#include <Eigen/LU>

using Eigen::MatrixXcd;
using namespace Eigen;


void CircuitDesign::countNoNodes( )
{
    // ---- Count number of passive elements and voltage sources
    unsigned int NodeCount = 0;
    for ( unsigned int i = 0; i < m_netlist.size( ); i++ )
    {
        if ( m_netlist.at( i )->getMaxNode( ) > NodeCount )
        {
            NodeCount = m_netlist.at( i )->getMaxNode( );
        }
    }
    m_NoNodes = NodeCount;
}

void CircuitDesign::countNoVoltSources( )
{
    m_NoVoltSources = m_voltlist.size( );
}

CircuitDesign::CircuitDesign()
{
    m_netlist.reserve( 10 );
    m_voltlist.reserve( 10 );
}

void CircuitDesign::ReadNetlist( std::ifstream &netlistfile )
{
    char el;
    unsigned short n1;
    unsigned short n2;
    double val;

    if ( netlistfile )
    {
        while ( netlistfile >> el >> n1 >> n2 >> val )
        {
            //std::cout << el << " " << n1 << " " << n2 << " " << val << std::endl;

            CktElemPassive* pa = 0x0;
            if ( el == 'R' )
            {
                pa = new CktResistor( n1, n2, val );
            }
            else if ( el ==  'L' )
            {
                pa = new CktInductor( n1, n2, val );
            }
            else if ( el == 'C' )
            {
                pa = new CktCapacitor( n1, n2, val );
            }
            else if ( el == 'V' )
            {
                CktVoltSource* pV = new CktVoltSource( n1, n2, val );
                m_voltlist.push_back( std::shared_ptr<CktVoltSource>( pV ) );
            }
            if ( pa != 0x0 )
                m_netlist.push_back( std::shared_ptr<CktElemPassive>( pa ) );

        }
    }
    else
    {
        //std::cerr << "Couldn't open for reading\n";
    }

    countNoNodes( );
    countNoVoltSources( );
}

void CircuitDesign::SolveCircuit( unsigned int freq_start_Hz, unsigned int freq_stop_Hz, unsigned int freq_step_Hz )
{
    unsigned int        matsize = m_NoNodes+m_NoVoltSources;
    // ---- create and fill matrix
    double freq = 1000;
    MatrixXcd A( matsize, matsize );
    A.setZero( matsize, matsize );

    for ( unsigned int i = 0; i < m_netlist.size( ); i++ )
    {
        sNodes nodes = m_netlist.at( i )->getNodes( );
        if ( nodes.node1 != 0 )
        {
            A( nodes.node1-1, nodes.node1-1 ) = A( nodes.node1-1, nodes.node1-1 )
                                            + m_netlist.at( i )->getAdmittance( freq );
        }
        if ( nodes.node2 != 0 )
        {
            A( nodes.node2-1, nodes.node2-1 ) = A( nodes.node2-1, nodes.node2-1 )
                                            + m_netlist.at( i )->getAdmittance( freq );
        }
        if ( nodes.node1 != 0 && nodes.node2 != 0 )
        {
            A( nodes.node1-1, nodes.node2-1 ) = A( nodes.node1-1, nodes.node2-1 )
                                            - m_netlist.at( i )->getAdmittance( freq );

            A( nodes.node2-1, nodes.node1-1 ) = A( nodes.node2-1, nodes.node1-1 )
                                            - m_netlist.at( i )->getAdmittance( freq );
        }
    }

    /* n is the number of nodes
     * m is the number of independent voltage sources
     *
     * Ax = z
     *
     * A --> (m+n) x (m+n)
     * z --> (m+n) x 1
     *
     */

    MatrixXcd z( matsize, 1 );
    z.setZero( matsize, 1 );

    unsigned int uiStartIdx = m_NoNodes;
    for ( unsigned int i = 0; i < m_voltlist.size( ); i++ )
    {
        sNodes nodes = m_voltlist.at( i )->getNodes( );
        if ( nodes.node1 != 0 )
        {
            A( nodes.node1-1, uiStartIdx + i ) = 1;
            A( uiStartIdx + i, nodes.node1-1 ) = 1;
            z( m_NoNodes + i, 0 ) = m_voltlist.at( i )->getVoltage( );
        }
        if ( nodes.node2 != 0 )
        {
            A( nodes.node1-1, uiStartIdx + i ) = -1;
            A( uiStartIdx + i, nodes.node1-1 ) = -1;
        }

    }

    MatrixXcd A_1( matsize, matsize );
    A_1 = A.inverse( );

    MatrixXcd x( matsize, 1 );
    x = A.fullPivLu().solve(z);

    std::cout << "Result:\n" << x.cwiseAbs() << std::endl;
    std::cout << "Phase:\n" << x.array().arg() << std::endl;
}
