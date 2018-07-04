#ifndef CIRCUITDESIGN_H
#define CIRCUITDESIGN_H

#include <vector>
#include <memory>
#include <fstream>

#include "cktcapacitor.h"
#include "cktinductor.h"
#include "cktresistor.h"
#include "cktvoltsource.h"


class CircuitDesign
{
    std::vector<std::shared_ptr<CktElemPassive>>
                        m_netlist;
    std::vector<std::shared_ptr<CktVoltSource>>
                        m_voltlist;

    unsigned int        m_NoNodes;
    unsigned int        m_NoVoltSources;

    AddResistor( unsigned int node1, unsigned int node2, double resistance_ohm );
    AddCapacitor( unsigned int node1, unsigned int node2, double capacitance_F );
    AddInductor( unsigned int node1, unsigned int node2, double inductance_H, double resistance_ohm = 0 );
    AddVoltSource( unsigned int pnode, unsigned int nnode, double voltage_V );

    void countNoNodes( );
    void countNoVoltSources( );

public:
    CircuitDesign( );

    void ReadNetlist( std::ifstream &netlistfile );

    void SolveCircuit( unsigned int freq_start_Hz, unsigned int freq_stop_Hz, unsigned int freq_step_Hz = 1 );
};

#endif // CIRCUITDESIGN_H
