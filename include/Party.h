#pragma once
#include <string>
#include "Offer.h"
#include "JoinPolicy.h"
#include <vector>

using std::string;
using std::vector;

class Simulation;

enum State
{
    Waiting,
    CollectingOffers,
    Joined
};

class Party
{
public:
    Party(int id, string name, int mandates, JoinPolicy *);
    
    Party(const Party &other);
    virtual ~Party();
    Party& operator= (const Party &other); 
    Party& operator= (Party&& other);

    State getState() const;
    State getState();
    void setState(State state);
    int getMandates() const;
    int getPartyId() const;
    void step(Simulation &s);
    void addOffer(Offer o1);
    vector<Offer> getOffers();
    const string &getName() const;

private:
    int mId;
    string mName;
    int mMandates;
    JoinPolicy *mJoinPolicy;
    State mState;
    int timerIter;
    vector<Offer> offers;
    vector<Offer> iniVectorOffers();
};