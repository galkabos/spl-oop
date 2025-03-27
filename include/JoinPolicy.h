#pragma once

class Simulation;

class JoinPolicy {
    public:
    virtual void Join(Simulation &s, int partyId)=0;
    virtual ~JoinPolicy();
    virtual JoinPolicy* getNewJoinPolicy() =0;

};

class MandatesJoinPolicy : public JoinPolicy 
{
    virtual void Join(Simulation &s, int partyId);
    virtual JoinPolicy* getNewJoinPolicy();
};

class LastOfferJoinPolicy : public JoinPolicy 
{
    virtual void Join(Simulation &s, int partyId);
    virtual JoinPolicy* getNewJoinPolicy();
};

