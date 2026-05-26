#include <random>
#include "HotPotatoGameArrayQueue.h"

HotPotatoGameArrayQueue::HotPotatoGameArrayQueue() : winner("None") {
    
}
HotPotatoGameArrayQueue::HotPotatoGameArrayQueue(const HotPotatoGameArrayQueue& other) {
    if (this != &other) {
        currentPlayers = other.currentPlayers;
        eliminatedPlayers = other.eliminatedPlayers;
        winner = other.winner;
    }
}
HotPotatoGameArrayQueue::~HotPotatoGameArrayQueue() {

}

// function to simulate a game of hot potato using queues
string HotPotatoGameArrayQueue::playgame(const ArrayQueue<string>& inputPlayers, const int passes) {
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
HotPotatoGameArrayQueue& HotPotatoGameArrayQueue::operator=(const HotPotatoGameArrayQueue& other) {
    if (this != &other) {
        currentPlayers.clear();
        eliminatedPlayers.clear();
        currentPlayers = other.currentPlayers;
        eliminatedPlayers = other.eliminatedPlayers;
        winner = other.winner;
    }

    return *this;
}

void HotPotatoGameArrayQueue::printCurrentPlayers() {
    currentPlayers.printQueue();
}

void HotPotatoGameArrayQueue::printEliminatedPlayers() {
    eliminatedPlayers.printQueue();
}

void HotPotatoGameArrayQueue::clear() {
    currentPlayers.clear();
    eliminatedPlayers.clear();
    winner = "None";
}