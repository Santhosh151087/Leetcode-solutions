class Solution {
public:
    bool canAliceWin(int n) {

        int remove = 10;
        int player = 0;
        while (n > 0) {
            // cout<<player<<" "<<n<<" "<<remove<<endl;
            if (n < remove)
                return player == 1;
            player = 1 - player;

            n -= remove;
            remove--;
        }
        return player==1;
    }
};