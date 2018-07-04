#ifndef CKTELEMENT_H
#define CKTELEMENT_H

#include "netdefs.h"

struct sNodes
{
    unsigned int node1;
    unsigned int node2;
};

class CktElement
{
protected:
    sNodes              m_nodes;

public:
    CktElement( );

    sNodes              getNodes( ) { return m_nodes; };

    unsigned int        getMaxNode(  ) { return (m_nodes.node1>m_nodes.node2 ? m_nodes.node1 : m_nodes.node2);};
};

#endif // CKTELEMENT_H
