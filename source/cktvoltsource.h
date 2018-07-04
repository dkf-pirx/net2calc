#ifndef CKTVOLTSOURCE_H
#define CKTVOLTSOURCE_H

#include "CktElement.h"


class CktVoltSource : public CktElement
{
    double          m_voltage_V;
public:
    CktVoltSource( );
    CktVoltSource( unsigned short n1, unsigned short n2, double voltage_V );

    double          getVoltage( ) { return m_voltage_V; };
};

#endif // CKTVOLTSOURCE_H
