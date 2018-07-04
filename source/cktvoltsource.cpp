#include "cktvoltsource.h"

CktVoltSource::CktVoltSource()
{

}

CktVoltSource::CktVoltSource( unsigned short n1, unsigned short n2, double voltage_V )
{
    m_voltage_V         = voltage_V;
    m_nodes.node1       = n1;
    m_nodes.node2       = n2;
}
