class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> valid(bank.begin(), bank.end());

        if (startGene == endGene) {
            return 0;
        }

        if (valid.find(endGene) == valid.end()) {
            return -1;
        }

        queue<pair<string, int>> q;
        unordered_set<string> visited;

        q.push({startGene, 0});
        visited.insert(startGene);

        string genes = "ACGT";

        while (!q.empty()) {
            auto current = q.front();
            q.pop();

            string gene = current.first;
            int mutations = current.second;

            for (int i = 0; i < 8; i++) {
                char original = gene[i];

                for (char c : genes) {
                    if (c == original) {
                        continue;
                    }

                    gene[i] = c;

                    if (gene == endGene) {
                        return mutations + 1;
                    }

                    if (valid.find(gene) != valid.end() &&
                        visited.find(gene) == visited.end()) {
                        visited.insert(gene);
                        q.push({gene, mutations + 1});
                    }
                }

                gene[i] = original;
            }
        }

        return -1;
    }
};