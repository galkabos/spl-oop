#include "Agent.h"
#include "Simulation.h"

 #include <iostream>
using namespace std;
Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy)
{
    // You can change the implementation of the constructor, but not the signature!
}
Agent::~Agent()
{
    if (this->mSelectionPolicy)
        delete this->mSelectionPolicy;
}

Agent &Agent::operator=(const Agent &other)
{
    if (this != &other)
    {
        if (this->mSelectionPolicy)
            delete this->mSelectionPolicy;
        mAgentId = other.mAgentId;
        mPartyId = other.mPartyId;
        mSelectionPolicy = other.mSelectionPolicy->getNewSelectionPolicy();
    }
    return *this;
}

Agent &Agent::operator=(Agent &&other)
{
    if (this->mSelectionPolicy)
        delete this->mSelectionPolicy;
    mAgentId = other.mAgentId;
    mPartyId = other.mPartyId;
    mSelectionPolicy = other.mSelectionPolicy;
    other.mSelectionPolicy = nullptr;
    return *this;
}
Agent Agent::cloneAgent(Simulation &sim)
{
    int next = sim.getAgents().size();
    SelectionPolicy *SP = mSelectionPolicy->getNewSelectionPolicy();
    sim.setAgents(Agent(next, mPartyId, SP));
    return Agent(next, mPartyId, SP);
}

Agent::Agent(const Agent &other) : mAgentId(other.mAgentId), mPartyId(other.mPartyId), mSelectionPolicy(other.mSelectionPolicy->getNewSelectionPolicy()) {}

int Agent::getId() const
{
    return mAgentId;
}

void Agent::setId(int id)
{
    mAgentId=id;
}

//setIdParty
void Agent::setPartyId(int id)
{
    mPartyId = id;
}

int Agent::getPartyId() const
{
    return mPartyId;
}

int Agent::findTheCoalitionNumber(int agentId, int partyId, Simulation& sim)
{
    int theColumn = -1;
    bool find = false;

    // find the column of the party (the original agent)
    for(unsigned int i = 0; i< sim.getPartiesByCoalitions().size() && !find; i++)
    {
        for (unsigned int j = 0; j< sim.getPartiesByCoalitions().at(i).size() && !find; j++)
        {
            if(sim.getPartiesByCoalitions().at(i).at(j) == mPartyId)
            {
                theColumn = i;
                find = true;
            }
        }
    }
    return theColumn;
}

void Agent::step(Simulation &sim)
{
    // TODO: implement this method
    int selectParty = this->mSelectionPolicy->select(&sim, mAgentId);
    if(selectParty != -1)
    {
        Party &theOffered = sim.getPartyN(selectParty);
        int sum = 0;
        int theColumn = findTheCoalitionNumber(mAgentId, mPartyId, sim);
        for (unsigned int i = 0; i < sim.getPartiesByCoalitions().at(theColumn).size(); i++)
        {
        // count the number of the mandate
            int man = sim.getGraph().getMandates(sim.getPartiesByCoalitions().at(theColumn).at(i));
            sum += man;
        }
        if(theOffered.getState()==Waiting)
        {
            theOffered.setState(CollectingOffers);
        }
        theOffered.addOffer(Offer(mAgentId, sum,mPartyId));
    }
}