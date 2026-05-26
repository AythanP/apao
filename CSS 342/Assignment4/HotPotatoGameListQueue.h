#include <string>
#include "list_queue.h"

using namespace std;

class HotPotatoGameListQueue {
    private:
        ListQueue<string> currentPlayers;
        ListQueue<string> eliminatedPlayers;
        string winner;
    public:
        HotPotatoGameListQueue();
        HotPotatoGameListQueue(const HotPotatoGameListQueue& other);
        ~HotPotatoGameListQueue();
        string playgame(const ListQueue<string>& inputPlayers, const int passes);
        void printCurrentPlayers();
        void printEliminatedPlayers();
        void clear();

        HotPotatoGameListQueue& operator=(const HotPotatoGameListQueue& other);
};