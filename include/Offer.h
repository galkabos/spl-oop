#pragma once

class Offer
{
    public:
    Offer(int offeringAgentId, int mandatesOfCoalition, int offeringPartyId);
    const int getOfferingAgendId() const;
    const int getMandatesOfCoalition() const;
    const int getOfferingPartyId() const;

    private:
    int offeringAgentId;
    int mandatesOfCoalition;
    int offeringPartyId;
};