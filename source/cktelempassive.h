#ifndef CKTELEMPASSIVE_H
#define CKTELEMPASSIVE_H

#include "CktElement.h"


class CktElemPassive : public CktElement
{
public:
    CktElemPassive();

    virtual cxd         getImpedance( double frequency ) = 0;
    virtual cxd         getAdmittance( double frequency ) = 0;
};

#endif // CKTELEMPASSIVE_H
