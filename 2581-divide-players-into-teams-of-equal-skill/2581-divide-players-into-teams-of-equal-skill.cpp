class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        
        sort(skill.begin(), skill.end());
        
        int i = 0;
        int j = n - 1;
        int targetSkill = skill[i] + skill[j];
        long long chem = 0;

        while(i < j) {
            int currSkill = skill[i] + skill[j];

            if(currSkill != targetSkill) {
                return -1;
            }
            
            chem += skill[i] * skill[j];
            i++;
            j--;
        }
        return chem;
    }
};