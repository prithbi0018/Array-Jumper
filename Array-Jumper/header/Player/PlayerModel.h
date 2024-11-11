#pragma once

namespace Player
{
    enum class PlayerState
    {
        ALIVE,
        DEAD
    };

    class PlayerModel
    {
    private:
        PlayerState player_state;
        int current_position;
        const int max_lives = 3;
        int current_lives;

    public:
        PlayerModel();
        ~PlayerModel();

        void initialize();
        PlayerState getPlayerState();
        void setPlayerState(PlayerState new_player_state);
        int getCurrentPosition();
        void setCurrentPosition(int new_position);
        int getCurrentLives();
        void decrementLife();
        void resetPosition();
    };
}