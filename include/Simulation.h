#pragma once
#include "Graph.h"
#include <vector>

using std::vector;

class Agent;
class Party;

class Simulation
{
public:
    Simulation(Graph g, vector<Agent> agents);

    void step();
    bool shouldTerminate() const;
    const Graph &getGraph() const;
    const vector<Agent> &getAgents() const;
    vector<Agent> &getAgents();
    const Party &getParty(int partyId) const;
    const vector<vector<int>> getPartiesByCoalitions() const;
    Party &getPartyN(int partyId);
    void setCoalition(int agentId, int partyId);
    void setAgents(Agent);

private:
    Graph mGraph;
    vector<Agent> mAgents;
    vector<vector<int>> coalitions;
    vector<vector<int>> iniVectorCoalitions();
};