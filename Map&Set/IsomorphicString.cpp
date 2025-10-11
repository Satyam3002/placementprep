    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        vector<int> sIndex(256, -1);
        vector<int> tIndex(256, -1);
        for (int i = 0; i < s.length(); i++) {
            char ch1 = s[i];
            char ch2 = t[i];
            if (sIndex[ch1] != tIndex[ch2]){
                return false;
            }

            sIndex[ch1] = tIndex[ch2] = i;
        }
        return true;
    }


   // using map 
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        unordered_map<char, char> mapST;
        unordered_map<char, char> mapTS;
        for (int i = 0; i < s.size(); i++) {
            char chS = s[i];
            char chT = t[i];

            if (mapST.count(chS) && mapST[chS] != chT) {
                return false;
            }

            if (mapTS.count(chT) && mapTS[chT] != chS) {
                return false;
            }
            mapST[chS] = chT;
            mapTS[chT] = chS;
        }

        return true;
    }
