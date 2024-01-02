# Project Overview

The goal of this project was to implement a graph to represent a system
of accounts, some of which are following one another. In each input file,
the account in the second column is following the account in the first.
The root account is the account with the greatest number of followers.
We also want to print every account within depth 2 of the root as a tree,
with each list of followers in alphabetical order.

# Original Implementation

The code consists of two major classes, an account class and a graph class.
The account class contains the distance to the root account (depth), the
account's name, and two vectors each of type Account* , one to store the
account's followers, and the other to store accounts it is following. The
graph class contains a vector of type Account* to store the accounts

# Noteable Differences in Second Implementation

•   Sets of type string are used to store followers and following in the
    account class. This prevents duplicates and is ordered, so there is no
    need to iterate through each to check if the element being inserted is
    already present. Also, nothing additional needs to be done to print
    the followers in alphabetical order since this is already done by the set.

•   Lists of type Account* are used in the graph class to store each account.
    Accounts are inserted in alphabetical order as they are added, and duplicates
    are not added. The vector either requires shifting elements after the position
    a new element is inserted, or needs to be sorted later. To check for duplicates
    and either sort a vector or shift elements, the vector must be iterated through
    twice depending on the sorting algorithm used. A list needs to be iterated
    through once to both check for a duplicate and insert a new element in the
    correct position. Also, the shifting issue in vectors is avoided with lists.

•   Root account is tracked and updated as accounts are added to the graph. When
    a new follower is added to an account in the graph, a function is called to
    check if the account that gained a follower now has more followers than the
    current root. If it does, the root is updated. This avoids the need to search
    the list of accounts again after they have all been read from the input file.
    