#pragma once

#include <vector>
#include "Graph.h"
#include "SelectionPolicy.h"

class Simulation;

class Agent
{
public:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);
    virtual ~Agent();
    int getPartyId() const;
    void setPartyId(int id);
    int getId() const;
    void setId(int id);
    void step(Simulation &);
    Agent cloneAgent(Simulation &);
    Agent (const Agent& other);
    Agent& operator = (const Agent&other);
    Agent& operator=(Agent && other);
    int findTheCoalitionNumber (int agentId, int partyId, Simulation&);

private:
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
};