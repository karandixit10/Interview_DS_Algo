class Solution {
public:
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        int numEnemies = damage.size();
        vector<pair<int, double>> enemies(numEnemies);

        for (int i = 0; i < numEnemies; ++i) {
            long long hitsRequired = (double)(health[i] + power - 1) / power;
            double damageRatio = (double)damage[i] / hitsRequired;
            enemies[i] = {i, damageRatio};
        }

        sort(enemies.begin(), enemies.end(), [](const pair<int, double>& a, const pair<int, double>& b) {
                 return a.second > b.second;
             });

        long long totalDamage = 0;
        long long currentDamage = 0;

        for (int i = 0; i < numEnemies; ++i) {
            int enemyind = enemies[i].first;
            long long hits = (health[enemyind] + power - 1) / power;
            totalDamage += damage[enemyind] * (currentDamage + hits);
            currentDamage += hits;
        }

        return totalDamage;
    }
};
