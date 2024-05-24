#include <bits/stdc++.h>
using namespace std;

int intialAbhiPower;
int totalRechargeTimes;
vector<int> enemyPower;

int totalToKillEnemy(int enemy, int currentPower){
    return ceil(float(enemy - currentPower)/intialAbhiPower);
}

int main() {

    enemyPower = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1000, 1};
    int n = enemyPower.size();

    intialAbhiPower = 5;
    totalRechargeTimes = 5;

    int currentPower = intialAbhiPower;
    
    bool battle = true;
    
    for(int i=0; i<n; i++){
        int enemy = enemyPower[i];
        if(i >= 3 && i <= 5){
            enemy += enemyPower[2];
        }
        if(i >= 6){
            enemy += enemyPower[6];
        }

        // can i kill backstaber and current enemy together with curren power?
        if(currentPower >= enemy){
            currentPower -= enemyPower[i];
            continue;
        }

        // no of times recharge required to kill enemies
        int totalTimes = totalToKillEnemy(enemy, currentPower);

        // total times is withing the limit or not?
        if(totalTimes > totalRechargeTimes){
            battle = false;
            break;
        }

        // if total times is possible, then check whether i can kill the alone enemy becuase backstaber won't come if power is more
        if(currentPower >= enemyPower[i]){
            currentPower -= enemyPower[i];
            continue;
        }

        // total times to kill current enemy only
        totalTimes = totalToKillEnemy(enemyPower[i], currentPower);

        // final power after killing current enemy
        currentPower += totalTimes * intialAbhiPower - enemyPower[i];

        totalRechargeTimes -= totalTimes;
    }

    cout <<( battle ? "escaped" : "not escaped") << endl;
    

    return 0;
}
