#include <string>
#include "array_queue.h"

using namespace std;

class HotPotatoGameArrayQueue {
    private:
        ArrayQueue<string> currentPlayers;
        ArrayQueue<string> eliminatedPlayers;
        string winner;
    public:
        HotPotatoGameArrayQueue();
        HotPotatoGameArrayQueue(const HotPotatoGameArrayQueue& other);
        ~HotPotatoGameArrayQueue();
        string playgame(const ArrayQueue<string>& inputPlayers, const int passes);
        void printCurrentPlayers();
        void printEliminatedPlayers();
        void clear();

        HotPotatoGameArrayQueue& operator=(const HotPotatoGameArrayQueue& other);
};