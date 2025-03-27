# include "SelectionPolicy.h"
#include "Party.h"
#include "Simulation.h"
#include "Agent.h"
#include <vector>


 #include <iostream>
using namespace std;
 int EdgeWeightSelectionPolicy :: select(Simulation * sim, int agentId)
{
    int maxWeight = 0;
    int theSelectParty = -1;
    Graph gr = sim->getGraph();
    vector<Agent> agents = sim->getAgents();//maybe error
    Agent *ag = nullptr;
     // get the object of Agent
    for(unsigned int i=0;i<agents.size();i++)
    {
        if(agents.at(i).getId()==agentId)
        {
            ag =&agents.at(i);
            i = agents.size();
        }

    }
    if(ag!=nullptr)
    {
        vector <Party> Neighbors = gr.getNeighbors(ag->getPartyId()) ;
        bool find = false;
        int theCoalition = ag->findTheCoalitionNumber(agentId,ag->getPartyId(),*sim);
        
        for(unsigned int i=0; i< Neighbors.size();i++)
        {
            find = false;
            // check if the weight is bigger
            if(gr.getEdgeWeight(ag->getPartyId(),Neighbors.at(i).getPartyId()) > maxWeight)
            {
                // check the state condition
                if(Neighbors.at(i).getState()!=Joined)
                {
                    
                    for(unsigned int j = 0;j<sim->getPartiesByCoalitions().at(theCoalition).size() && !find;j++)
                    {
                        for(unsigned int k = 0;k<Neighbors.at(i).getOffers().size() && !find;k++)
                        {
                            if(Neighbors.at(i).getOffers().at(k).getOfferingPartyId()==sim->getPartiesByCoalitions().at(theCoalition).at(j))
                                find = true;
                        }
                    }
                    
                    if(!find)
                    {
                        maxWeight = gr.getEdgeWeight(ag->getPartyId(),Neighbors.at(i).getPartyId());
                        theSelectParty = Neighbors.at(i).getPartyId();
                    }
                }
            }
        }
        ag=nullptr;
    }
    return theSelectParty; 
}

SelectionPolicy *EdgeWeightSelectionPolicy::getNewSelectionPolicy() 
{
    SelectionPolicy* newSP = new EdgeWeightSelectionPolicy;
    return newSP;
}