# include "SelectionPolicy.h"
#include "Party.h"
#include "Simulation.h"
#include "Agent.h" 
#include <vector>

using std::vector;

 #include <iostream>
using namespace std;

 int MandatesSelectionPolicy:: select(Simulation * sim, int agentId)
{
    int maxMandt = 0;
    int theSelectParty = -1;
    Graph gr = sim->getGraph();
    vector<Agent> agents = sim->getAgents();
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
            // check the mandate condition
            if(Neighbors.at(i).getMandates()>maxMandt)
            {
                // check the state condition
                if(Neighbors.at(i).getState()!=Joined)
                {                
                    // check if anyone from the colition offer to the party
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
                        maxMandt = Neighbors.at(i).getMandates();
                        theSelectParty = Neighbors.at(i).getPartyId();
                    }
                }
            }
        }
        ag=nullptr;
    }    
    return theSelectParty ;
    
}

SelectionPolicy *MandatesSelectionPolicy::getNewSelectionPolicy()
{
    SelectionPolicy* newSP = new MandatesSelectionPolicy;
    return newSP;
}