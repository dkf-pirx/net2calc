#ifndef CKTCAPACITOR_H
#define CKTCAPACITOR_H

#include "cktelempassive.h"

class CktCapacitor : public CktElemPassive
{
    double      m_capacitance;
public:
    CktCapacitor( );
    CktCapacitor( unsigned short n1, unsigned short n2, double capacitance );

    cxd getImpedance( double frequency );
    cxd getAdmittance( double frequency );
};

#endif // CKTCAPACITOR_H
