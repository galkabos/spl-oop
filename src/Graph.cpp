#include "Graph.h"

 #include <iostream>
using namespace std;

Graph::Graph(vector<Party> vertices, vector<vector<int>> edges) : mVertices(vertices), mEdges(edges) 
{
    // You can change the implementation of the constructor, but not the signature!
}

int Graph::getMandates(int partyId) const
{
    return mVertices[partyId].getMandates();
}
int Graph::getMandatesNotConst(int partyId) 
{
    return mVertices[partyId].getMandates();
}

int Graph::getEdgeWeight(int v1, int v2) const
{
    return mEdges[v1][v2];
}

int Graph::getNumVertices() const
{
    return mVertices.size();
}

const Party &Graph::getParty(int partyId) const
{
    return mVertices[partyId];
}

Party &Graph::getParty(int partyId)
{
    return mVertices[partyId];
}
vector<Party> Graph:: getNeighbors(int partyId)const
{
    vector<Party>Neighbors;
    for(unsigned int i = 0; i <mEdges[partyId].size();i++)
    {
        if(mEdges[partyId].at(i)!=0)
            Neighbors.push_back(mVertices.at(i));
    }
    return Neighbors;
}