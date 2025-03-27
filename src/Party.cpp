#include "Party.h"
#include "Simulation.h"

Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting),timerIter(0), offers(iniVectorOffers()){}

vector<Offer> Party::iniVectorOffers()
{
    vector<Offer> v1;
    return v1;
}

Party::Party(const Party &other) : mId(other.mId), mName (other.mName), mMandates(other.mMandates), mJoinPolicy(other.mJoinPolicy->getNewJoinPolicy()), mState(other.mState), timerIter(other.timerIter), offers(other.offers){}

Party::~Party()
{
    if(this->mJoinPolicy) delete this->mJoinPolicy;
}

Party &Party::operator=(const Party &other)
{
    if(this!=&other)
    {
        if(this->mJoinPolicy) delete this->mJoinPolicy;
        mId=other.mId;
        mName=other.mName;
        mMandates=other.mMandates;
        mState=other.mState;
        mJoinPolicy=other.mJoinPolicy->getNewJoinPolicy();
    }
    return *this;    
}

Party &Party::operator=(Party &&other)
{
    if(this->mJoinPolicy) delete this->mJoinPolicy;
    mId=other.mId;
    mName=other.mName;
    mMandates=other.mMandates;
    mState=other.mState;
    mJoinPolicy=other.mJoinPolicy;
    other.mJoinPolicy = nullptr;
    return *this;
}

State Party::getState() const
{
    return mState;
}

State Party::getState() 
{
    return mState;
}

void Party::setState(State state)
{
    mState = state;
}

int Party::getMandates() const
{
    return mMandates;
}

vector<Offer> Party::getOffers()
{
    return offers;
}

int Party::getPartyId() const
{
    return mId;
}

const string & Party::getName() const
{
    return mName;
}

void Party::addOffer(Offer o1)
{
    offers.push_back(o1);
}

void Party::step(Simulation &s)
{
    if(mState==CollectingOffers)
    {
        timerIter++;
    } 
    if(timerIter==3)
    {
        this->mJoinPolicy->Join(s,mId);
        this->setState(Joined);
        timerIter++;
    }
}