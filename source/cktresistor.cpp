#include "cktresistor.h"

CktResistor::CktResistor( )
    : m_resistance( 1000000000 ) // infinite, open-circuit
{

}

CktResistor::CktResistor( unsigned short n1, unsigned short n2, double resistance )
{
    m_resistance        = resistance;
    m_nodes.node1       = n1;
    m_nodes.node2       = n2;
}

void CktResistor::addResistance( double resistance )
{
    m_resistance = resistance;
}

cxd CktResistor::getImpedance( double frequency )
{
    (void)(frequency); // not required for resistor

    return m_resistance;
}

cxd CktResistor::getAdmittance( double frequency )
{
    (void)(frequency); // not required for resistor

    return ( 1 / m_resistance );
}
