#ifndef CKTRESISTOR_H
#define CKTRESISTOR_H

#include "CktElemPassive.h"

class CktResistor : public CktElemPassive
{
    double      m_resistance;
public:
    CktResistor( );
    CktResistor( unsigned short n1, unsigned short n2, double resistance );

    void addResistance( double resistance );

    cxd getImpedance( double frequency = 0 );
    cxd getAdmittance( double frequency = 0 );

};

#endif // CKTRESISTOR_H
