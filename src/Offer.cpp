#include "Offer.h"

Offer::Offer(int offeringAgentId1,int mandatesOfCoalition1, int offeringPartyId1) : offeringAgentId(offeringAgentId1), mandatesOfCoalition(mandatesOfCoalition1),offeringPartyId(offeringPartyId1){}

const int Offer::getOfferingAgendId() const
{
    return offeringAgentId;
}

const int Offer::getMandatesOfCoalition() const
{
    return mandatesOfCoalition;
}

const int Offer::getOfferingPartyId() const
{
    return offeringPartyId;
}