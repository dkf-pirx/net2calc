#include "cktcapacitor.h"

CktCapacitor::CktCapacitor()
{

}

CktCapacitor::CktCapacitor(unsigned short n1, unsigned short n2, double capacitance )
{
    m_capacitance       = capacitance;
    m_nodes.node1       = n1;
    m_nodes.node2       = n2;
}

cxd CktCapacitor::getImpedance( double frequency )
{
    cxd reactance;

    reactance = 1 / ( 1i * 2 * PI * frequency * m_capacitance );

    return ( reactance );
}

cxd CktCapacitor::getAdmittance(double frequency)
{
    cxd susceptance;

    susceptance = 1i * 2 * PI * frequency * m_capacitance;

return ( susceptance );
}
