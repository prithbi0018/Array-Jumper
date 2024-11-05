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

    public:
        PlayerModel();
        ~PlayerModel();

        void initialize();
        PlayerState getPlayerState();
        void setPlayerState(PlayerState new_player_state);
        int getCurrentPosition();
        void setCurrentPosition(int new_position);
    };
}