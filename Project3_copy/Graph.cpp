#include "Graph.h"
#include <iostream>
using namespace std;


Graph::Graph() {
    root = NULL;
}

void Graph::AddAccount(string newAccount) {
    bool added = false;
    Account temp;
    list<Account*>::iterator i = myaccounts.begin();
    if (myaccounts.size() == 0) {
        //temp = new Account(newAccount);
        myaccounts.push_back(new Account(newAccount));
        return;
    }
    //if new account should be last in the list
    else if ((myaccounts.back())->GetName() < newAccount){
        myaccounts.push_back(new Account(newAccount));
        return;
    }
    //find account's place in the list
    else {
        while(i != myaccounts.end()) {
            //if account was already added
            if ((*i)->GetName() == newAccount) {
                added = true;
                break;
            }
            if ((*i)->GetName() > newAccount) {
                break;
            }
            ++i;
        }        
        if (!added) {
            myaccounts.insert(i, new Account(newAccount));
        }
    }
}

Account* Graph::GetAccountFromName(string account) {
    Account* temp;
    list<Account*>::iterator i;
    for (i = myaccounts.begin(); i != myaccounts.end(); ++i) {
        if ((*i)->GetName() == account) {
            temp = *i;
            break;
        }
    }
    return temp;
}


void Graph::PrintAccounts() {
    cout << "ACCOUNTS:" << endl;
    list<Account*>::iterator i;
    for (i = myaccounts.begin(); i != myaccounts.end(); ++i) {
        cout << (*i)->GetName() << endl;
    }
}

void Graph::SetRoot() {
    Account* temp = myaccounts.front();
    list<Account*>::iterator i = myaccounts.begin();
    while(i != myaccounts.end()) {
        //check if equal number of followers
        if ((*i)->GetNumFollowers() > temp->GetNumFollowers()) {
            temp = *i;
        }
        //check if equal
        else if ((*i)->GetNumFollowers() == temp->GetNumFollowers()) {
            //TODO sort alphabetically
            if ((*i)->GetName() < temp->GetName()) {
                temp = *i;
            }
        }
        ++i;
    }
    root = temp;
}

void Graph::UpdateRoot(Account* newAccount) {
    if (root == NULL) {
        root = newAccount;
    }
    else if (newAccount->GetNumFollowers() > root->GetNumFollowers()) {
        root = newAccount;
    }
    //break tie using alphabet
    else if (newAccount->GetNumFollowers() == root->GetNumFollowers()) {
        if (newAccount->GetName() < root->GetName()) {
            root = newAccount;
        }
    }       
}

Account* Graph::GetRoot() {
    return root;
}
/*
//populate in social network
void Graph::BFS() {
    //visit all nodes within depth 1 of the root
    int numFrontier = root->GetNumFollowers();
    int adjFrontier = 0;
    string tempName;
    
    //sort to print in alphabetical order
    //root->SortFollowers();
    //cout << "Follwoers sorted for root!" << endl;
    //iterate through everything with depth 1
    for (int i = 0; i < numFrontier; ++i) {

        //sort to print in alphabetical order
        root->GetFollowers().at(i)->SortFollowers();

        //set adjFrontier to visit all adjacent accounts
        adjFrontier = root->GetFollowers().at(i)->GetNumFollowers();
        //add current node to inSN. Get name and distance from root will be 1
        tempName = root->GetFollowers().at(i)->GetName();
        //cout << root->GetFollowers().at(i)->GetName() << " (1)" << endl;
        inSN.push_back(Account(tempName, 1));

        for (int j = 0; j < adjFrontier; ++j) {
            tempName = root->GetFollowers().at(i)->GetFollowers().at(j)->GetName();
            inSN.push_back(Account(tempName, 2));
        }
    }
}

void Graph::PrintSN() {
    cout << "The root user is " << root->GetName();
    cout <<", with in-degree centrality of " << root->GetNumFollowers() << "." << endl;
    cout << "There are " << myaccounts.size() << " users in the social network." << endl;
    cout << root->GetName() << " (0)" << endl;
    for (unsigned int i = 0; i < inSN.size(); ++i) {
        cout << inSN.at(i).GetName() << " (" << inSN.at(i).GetRootDist() << ")" << endl;
    }

}*/