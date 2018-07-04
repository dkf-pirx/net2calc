#ifndef CKTINDUCTOR_H
#define CKTINDUCTOR_H

#include "CktElemPassive.h"

class CktInductor : public CktElemPassive
{
    double      m_inductance;
    double      m_seriesresistance;
public:
    CktInductor( );
    CktInductor( unsigned short n1, unsigned short n2,
                 double inductance, double ser_resistance = 0 );

    cxd getImpedance( double frequency );
    cxd getAdmittance( double frequency );
};

#endif // CKTINDUCTOR_H
