#include <iostream>
#include <vector>

class BowlingGame {
private:
    std::vector<std::vector<int>> frames;
    std::vector<int> frameScores;
    std::vector<int> pendingBonusFrames;
    int currentFrame;
    bool gameOver;

public:
    BowlingGame() : currentFrame(0), gameOver(false) 
    {
        frames.resize(10);
        frameScores.resize(10, 0);
    }

    void roll(int pins) 
    {
        if (gameOver)
        {
            std::cout << "Game is over, No more rolls allowed.\n";
            return;
        }

        if (pins > 10)
        {
            std::cout << "Invalid input, Number of pins in a roll cannot exceed 10.\n";
            return;
        }

        if (currentFrame < 9)
        {
            // First roll
            if (frames[currentFrame].empty()) 
            {
                frames[currentFrame].push_back(pins);
            }
            else // Second roll
            {
                if (frames[currentFrame][0] + pins > 10) 
                {
                    std::cout << "Invalid input, Total pins in a frame cannot exceed 10.\n";
                    return;
                }
                frames[currentFrame].push_back(pins);
            }

            updatePendingBonusFrames(pins);

            // Decide moving to next frame - If a Strike or two rolls Done
            if ((frames[currentFrame][0] == 10 || frames[currentFrame].size() == 2)) 
            {
                if (isStrike(currentFrame) || isSpare(currentFrame)) 
                {
                    pendingBonusFrames.push_back(currentFrame);
                }
                calculateFrameScore(currentFrame);
                currentFrame++;
            }
        }
        else 
        {
            frames[9].push_back(pins);

            // Second Roll
            if (frames[9].size() >= 2 && frames[9][0] != 10 && frames[9][0] + frames[9][1] > 10) 
            {
                std::cout << "Invalid input, Total pins in first two rolls cannot exceed 10.\n";
                frames[9].pop_back();
                return;
            }

            // Third Roll
            if (frames[9].size() == 3) 
            {
                if (frames[9][0] == 10) // Strike
                { 
                    if (frames[9][1] != 10 && frames[9][1] + pins > 10) 
                    {
                        std::cout << "Invalid input, Total pins in second and third rolls cannot exceed 10.\n";
                        frames[9].pop_back();
                        return;
                    }
                }
                else if (frames[9][0] + frames[9][1] == 10)  // Spare
                {
                    if (pins > 10) 
                    {
                        std::cout << "Invalid input, Bonus roll cannot exceed 10 pins.\n";
                        frames[9].pop_back();
                        return;
                    }
                }
            }
            // Decide Game Over
            if (frames[9].size() == 3 || (frames[9].size() == 2 && frames[9][0] + frames[9][1] < 10)) 
            {
                gameOver = true;
            }
            updatePendingBonusFrames(pins);
            calculateFrameScore(9);
        }
        displayLiveScores();
    }

    int getCurrentFrame() 
    {
        return currentFrame + 1;
    }

    bool isGameOver() 
    {
        return gameOver;
    }

    void displayLiveScores() 
    {
        std::cout << "\nLive Frame Scores:\n";
        
        if (currentFrame == 9 && frames[9].size() >= 2)
        {
            if (frames[9][0] == 10 || frames[9][0] + frames[9][1] == 10)
            {
                if (frames[9].size() < 3) {
                    std::cout << "Frame 10: Waiting for bonus rolls...\n";
                }
                else 
                {
                    std::cout << "Frame 10: Bonus rolls complete.\n";
                }
            }
        }

        for (int frameindex = 0; frameindex <= currentFrame; frameindex++) 
        {
            std::cout << "Frame " << frameindex + 1 << ": ";

            if (!frames[frameindex].empty()) 
            {
                std::cout << "Roll1=" << frames[frameindex][0];
                if (frames[frameindex].size() > 1) 
                {
                    std::cout << ", Roll2=" << frames[frameindex][1];
                }
                // Handle third roll for the 10th frame (bonus roll)
                if (frameindex == 9 && frames[frameindex].size() > 2) 
                {
                    std::cout << ", Roll3=" << frames[frameindex][2];
                }
            }
            else 
            {
                std::cout << "No rolls yet";
            }
            std::cout << ", Score=" << frameScores[frameindex] << "\n";
        }
    }

    void displayFinalScore() 
    {
        std::cout << "\nFinal Score: " << frameScores[9] << "\n";
    }

private:
    void calculateFrameScore(int frameindex) 
    {
        if (frames[frameindex].empty())
        {
            return;
        }

        int frameScore = 0;
        if (frameindex < 9) 
        {
            if (isStrike(frameindex)) // Strike
            { 
                frameScore += 10 + getNextTwoRolls(frameindex);
            }
            else if (isSpare(frameindex))  // Spare
            {
                frameScore += 10 + getNextRoll(frameindex);
            }
            else if (frames[frameindex].size() > 1) 
            {
                frameScore += frames[frameindex][0] + frames[frameindex][1];
            }
        }
        else // 10th frame
        { 
            for (int roll : frames[frameindex]) {
                frameScore += roll;
            }
        }

        frameScores[frameindex] = frameScore + (frameindex > 0 ? frameScores[frameindex - 1] : 0);
    }

    void updatePendingBonusFrames(int pins) 
    {
        for (auto it = pendingBonusFrames.begin(); it != pendingBonusFrames.end();) 
        {
            int frameindex = *it;

            if (isStrike(frameindex) && getPendingBonusRolls(frameindex) == 2) 
            {
                calculateFrameScore(frameindex);
                it = pendingBonusFrames.erase(it);
            }
            else if (isSpare(frameindex) && getPendingBonusRolls(frameindex) == 1) 
            {
                calculateFrameScore(frameindex);
                it = pendingBonusFrames.erase(it);
            }
            else 
            {
                ++it;
            }
        }
    }

    bool isStrike(int frameindex)
    {
        if (frames[frameindex][0] == 10)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isSpare(int frameindex) 
    {
        if (frames[frameindex].size() > 1 && (frames[frameindex][0] + frames[frameindex][1] == 10))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int getNextRoll(int frameindex)
    {
        if (frameindex + 1 < frames.size() && !frames[frameindex + 1].empty())
        {
            return frames[frameindex + 1][0];
        }
        return 0;
    }

    int getNextTwoRolls(int frameindex)
    {
        int nextRolls = 0;

        if (frameindex + 1 < frames.size() && !frames[frameindex + 1].empty())
        {
            nextRolls += frames[frameindex + 1][0];
            if (frames[frameindex + 1].size() > 1) {
                nextRolls += frames[frameindex + 1][1];
            }
            else if (frameindex + 2 < frames.size() && !frames[frameindex + 2].empty()) {//if frameindex+1 is strike, move to frameindex+2
                nextRolls += frames[frameindex + 2][0];
            }
        }

        return nextRolls;
    }

    int getPendingBonusRolls(int frameindex)
    {
        int rollsAfterFrame = 0;
        for (int i = frameindex + 1; i < frames.size(); ++i)
        {
            rollsAfterFrame += frames[i].size();
        }
        return rollsAfterFrame;
    }

};

int main() {
    BowlingGame game;
    int pins;

    std::cout << "Welcome to the Bowling Game!\n";
    std::cout << "Enter the number of pins knocked down for each roll (0-10):\n";

    while (!game.isGameOver()) 
    {
        std::cout << "Roll for Frame " << game.getCurrentFrame() << ": ";
        std::cin >> pins;

        // Validate input
        if (pins < 0 || pins > 10) {
            std::cout << "Invalid input! Please enter a number between 0 and 10.\n";
            continue;
        }

        game.roll(pins); // Register roll in game
    }

    game.displayFinalScore();
    return 0;
}


