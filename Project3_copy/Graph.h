//Graph
#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <list>
#include "Project3a.h"
using namespace std;

class Graph {
    private:
        //node storage
        list<Account> myaccounts;
        //vector<Account> inSN;
        Account root;
    public:
        Graph();
        //adding accounts
        //bool AccountAdded(string newAccount);
        void AddAccount(string newAccount);
        Account GetAccountFromName(string account);
        void PrintAccounts();
        void SetRoot();
        Account* GetRoot();
        //populate social network
        void BFS();
        void PrintSN();
};

#endif