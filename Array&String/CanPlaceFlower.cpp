// class Solution {
// public:
//     bool canPlaceFlowers(vector<int>& flowerbed, int n) {
//         int size = flowerbed.size();
//         for (int i = 0; i < size; i++) {
//             if (flowerbed[i] == 0) {
//                 bool leftEmpty = (i == 0 || flowerbed[i - 1] == 0);
//                 bool rightEmpty = (i == size - 1 || flowerbed[i + 1] == 0);

//                 if (leftEmpty && rightEmpty) {
//                     flowerbed[i] = 1;
//                     n--;
//                     if (n == 0) {
//                         return true;
//                     }
//                 }
//             }
//         }

//         return false;
//     }
// };



class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        int zeros = 1; 

        for (int plot : flowerbed) {
            if (plot == 0) {
                zeros++;
            } else {
                count += (zeros - 1) / 2;
                zeros = 0;
            }
        }
        
        zeros++; 
        count += (zeros - 1) / 2;

        return count >= n;
    }
};
