#pragma once
class Party;
class Simulation;

class SelectionPolicy {
    public:
        virtual ~ SelectionPolicy();
        virtual int select(Simulation * sim, int AgentId ) = 0;
        virtual SelectionPolicy* getNewSelectionPolicy()=0;

       
 };

class MandatesSelectionPolicy: public SelectionPolicy{
    public:
    
        virtual int select(Simulation * sim, int AgentId);
        virtual SelectionPolicy* getNewSelectionPolicy();

    
 };

class EdgeWeightSelectionPolicy: public SelectionPolicy{
    public:
    
        virtual int select(Simulation * sim, int AgentId);
        virtual SelectionPolicy* getNewSelectionPolicy();
 };