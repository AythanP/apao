#include <random>
#include "HotPotatoGameListQueue.h"

HotPotatoGameListQueue::HotPotatoGameListQueue() : winner("None") {
    
}
HotPotatoGameListQueue::HotPotatoGameListQueue(const HotPotatoGameListQueue& other) {
    if (this != &other) {
        currentPlayers = other.currentPlayers;
        eliminatedPlayers = other.eliminatedPlayers;
        winner = other.winner;
    }
}
HotPotatoGameListQueue::~HotPotatoGameListQueue() {

}

// function to simulate a game of hot potato using queues
string HotPotatoGameListQueue::playgame(const ListQueue<string>& inputPlayers, const int passes) {
    // generate random number of passes
    random_device rd;
    default_random_engine generator(rd());
    uniform_int_distribution<int> distribution(1, passes);

    currentPlayers = inputPlayers;
    while (currentPlayers.size() > 1) {
        int numPasses = distribution(generator);
        for (int i = 0; i < numPasses; i++) {
            string player = currentPlayers.dequeue();
            currentPlayers.enqueue(player);
        }
        
        string eliminated = currentPlayers.dequeue();
        eliminatedPlayers.enqueue(eliminated);

        cout << "Eliminated player: " << eliminated << endl;
    }

    winner = currentPlayers.front();
    return winner;
}

// assumes the queue assignment overload is a deep copy
HotPotatoGameListQueue& HotPotatoGameListQueue::operator=(const HotPotatoGameListQueue& other) {
    if (this != &other) {
        currentPlayers.clear();
        eliminatedPlayers.clear();
        currentPlayers = other.currentPlayers;
        eliminatedPlayers = other.eliminatedPlayers;
        winner = other.winner;
    }

    return *this;
}

void HotPotatoGameListQueue::printCurrentPlayers() {
    currentPlayers.printQueue();
}

void HotPotatoGameListQueue::printEliminatedPlayers() {
    eliminatedPlayers.printQueue();
}

void HotPotatoGameListQueue::clear() {
    currentPlayers.clear();
    eliminatedPlayers.clear();
    winner = "None";
}