#include "JoinPolicy.h"
#include "Simulation.h"
#include "Party.h"
#include "Offer.h"
#include "Agent.h"
#include <vector>

using std::vector;

void MandatesJoinPolicy::Join(Simulation &s, int partyId)
{
    Party p = s.getPartyN(partyId);
    vector<Offer> offers = p.getOffers();
    int max = 0;
    int agentId = 0;
    int tmp = 0;
   
    for(unsigned int i = 0; i<offers.size(); i++)
    {
        tmp = offers[i].getMandatesOfCoalition();
        if(tmp>max)
        {
            max=tmp;
            agentId = offers[i].getOfferingAgendId();
        }
    }
   
    s.setCoalition(agentId,partyId); 
    vector<Agent> agents = s.getAgents();
    Agent a = agents[agentId];
    a.setId(s.getAgents().size());
    a.setPartyId(partyId);
    s.getAgents().push_back(a);
}

JoinPolicy* MandatesJoinPolicy::getNewJoinPolicy()
{
    JoinPolicy* newJP = new MandatesJoinPolicy;
    return newJP;
}
