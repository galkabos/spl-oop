#include "JoinPolicy.h"
#include "Simulation.h"
#include "Party.h"
#include "Offer.h"
#include "Agent.h"

void LastOfferJoinPolicy::Join(Simulation &s, int partyId)
{
    Party p = s.getPartyN(partyId);
    Offer o = p.getOffers().back();
    int agentId = o.getOfferingAgendId();
    s.setCoalition(agentId,partyId); 
    vector<Agent> agents = s.getAgents();
    Agent a = agents[agentId];
    a.setId(s.getAgents().size());
    a.setPartyId(partyId);
    s.getAgents().push_back(a);
}

JoinPolicy *LastOfferJoinPolicy::getNewJoinPolicy()
{
    JoinPolicy* newJP = new LastOfferJoinPolicy;
    return newJP;
}
