#include "Simulation.h"
#include "Agent.h"
#include "Party.h"

 #include <iostream>
using namespace std;

Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph), mAgents(agents), coalitions(iniVectorCoalitions())
{
    for(unsigned int i=0;i<mAgents.size();i++)
    {
        vector<int> party;
        party.push_back(mAgents[i].getPartyId());
        coalitions.push_back(party);
    }    
}

vector<vector<int>> Simulation::iniVectorCoalitions()
{
    vector<vector<int>> v1;
    return v1;
}

void Simulation::step()
{
    for( int i=0;i<mGraph.getNumVertices(); i++)
    {
        Party &p1=mGraph.getParty(i);
        p1.step(*this);
    }
    for(unsigned int i=0;i<mAgents.size(); i++)
    {
        Agent &a = mAgents.at(i);
        a.step(*this);
    }
}

void Simulation::setAgents(Agent agent)
{
    mAgents.push_back(agent);
}

bool Simulation::shouldTerminate() const
{
        
    int sumAll = 120;
    int sum =0;
    for(unsigned int i=0;i<coalitions.size();i++)
    {
        for(unsigned int j=0;j<coalitions.at(i).size();j++)
        {
            int mandate = mGraph.getMandates(coalitions.at(i).at(j));
            sum += mandate;
        }
        if(sum>=61)
            return true;
        sumAll -= sum;
        sum =0;
        if(sumAll == 0)
            return true;
    }
    
    return false;
}

const Graph &Simulation::getGraph() const
{
    return mGraph;
}


const vector<Agent> &Simulation::getAgents() const
{
    return mAgents;
}

vector<Agent> &Simulation::getAgents()
{
    return mAgents;
}

const Party &Simulation::getParty(int partyId) const
{
    return mGraph.getParty(partyId);
}

Party& Simulation :: getPartyN(int partyId)
{
    return mGraph.getParty(partyId);
}

/// This method returns a "coalition" vector, where each element is a vector of party IDs in the coalition.
/// At the simulation initialization - the result will be [[agent0.partyId], [agent1.partyId], ...]
const vector<vector<int>> Simulation::getPartiesByCoalitions() const
{
    // TODO: you MUST implement this method for getting proper output, read the documentation above.
    return coalitions;
}

void Simulation::setCoalition(int agentId, int partyId)
{
    bool find = false;

    
    for(unsigned int i=0;i<coalitions.size()&&!find;i++)
    {
        for(unsigned int j=0;j<coalitions.at(i).size()&&!find;j++)
        {
            if(mAgents.at(agentId).getPartyId() == coalitions.at(i).at(j))
            {
                coalitions.at(i).push_back(partyId);
                find = true;
            }
        }
    }
    
}