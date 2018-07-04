#include "cktinductor.h"

CktInductor::CktInductor( )
    : m_inductance( 1000000000 )
{

}

CktInductor::CktInductor( unsigned short n1, unsigned short n2,
                          double inductance , double ser_resistance )
{
    m_seriesresistance  = ser_resistance;
    m_inductance        = inductance;
    m_nodes.node1       = n1;
    m_nodes.node2       = n2;
}

cxd CktInductor::getImpedance( double frequency )
{
    cxd reactance;

    reactance = 1i * 2 * PI * frequency * m_inductance;

return ( m_seriesresistance + reactance );
}

cxd CktInductor::getAdmittance( double frequency )
{
    cxd reactance;

    reactance = 1i * 2 * PI * frequency * m_inductance;

return ( 1.0 / ( m_seriesresistance + reactance ) );
}
